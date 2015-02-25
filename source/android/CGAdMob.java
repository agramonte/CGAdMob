/*
java implementation of the CGAdMob extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.google.android.gms.ads.*;
import android.util.*;
import android.widget.RelativeLayout;
import android.view.*;

// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

class CGAdMob
{
    
    public final static int CG_ADMOB_POSITION_TOP    = 1;
    public final static int CG_ADMOB_POSITION_BOTTOM = 2;
    
    public final static int CG_ADMOB_SMART = 0;
    public final static int CG_ADMOB_320x50 = 1;
    public final static int CG_ADMOB_320x100 = 2;
    public final static int CG_ADMOB_300x250 = 3;
    public final static int CG_ADMOB_468x60 = 4;
    public final static int CG_ADMOB_728x90 = 5;
    
    private AdView _googleAdView;
    private RelativeLayout _adLayout;
	private InterstitialAd _mInterstitialAd;

        //Logging
    private String logTag = "marmalade";
    private String _bannerAdUnitId = "";
    private String _interstatialAdUnitId = "";
	private RelativeLayout.LayoutParams _lp;
    private boolean _isLandscape = false;
    private String _testDeviceHashId = "";
    private boolean _showAtBottom = false;
    private int adSize = 0;
    
    
    

    public void InitAdView()
    {
       
	        //Create LayoutParams.
        this._lp = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.FILL_PARENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
        

        this._setGoogleAds();
		        
    }
    
    public int ShowInterstitialAd()
    {
        int adLoaded = 0;
        
        if (this._mInterstitialAd.isLoaded()) {
            
            this._mInterstitialAd.show();
            adLoaded = 1;
        }
        
        //TODO: Ad events and make this call on fail instead of every time.
        AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
        adRequestBuilder.addTestDevice(_testDeviceHashId);
        
        this._mInterstitialAd.loadAd(adRequestBuilder.build());
        
        
        return adLoaded;
        
    }
    
    public void SetGoogleAppKey(String bannerAdUnitId, String interstatialAdUnitId)
    {
        this._interstatialAdUnitId = interstatialAdUnitId;
        this._bannerAdUnitId = bannerAdUnitId;
    }
    
    public void BannerAdLoad()
    {
        AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
        adRequestBuilder.addTestDevice(_testDeviceHashId);
        this._googleAdView.loadAd(adRequestBuilder.build());
    }
    public void BannerAdShow()
    {
        
	try {
            ViewGroup rootView = (ViewGroup) LoaderActivity.m_Activity.findViewById(android.R.id.content);
            
            for (int i = 0; i < rootView.getChildCount(); i++) {
                if(rootView.getChildAt(i) == this._adLayout) {
                    rootView.getChildAt(i).setVisibility(View.VISIBLE);
                }
            }
            
        } catch (final Exception e) {
            Log.e(logTag, "Show Google view ex. thrown: " + e.toString());
            return;
        }
        
    }

    public void BannerAdHide()
    {
	try {
            ViewGroup rootView = (ViewGroup) 	LoaderActivity.m_Activity.findViewById(android.R.id.content);
            
            for (int i = 0; i < rootView.getChildCount(); i++) {
                if(rootView.getChildAt(i) == this._adLayout) {
                    rootView.getChildAt(i).setVisibility(View.GONE);
                }
            }
            
        } catch (final Exception e) {
            Log.e(logTag, "Hide Google view ex. thrown: " + e.toString());
            return;
        }
                
    }
    
    private void _setAdSize(){
        
        switch (adSize) {
            case 1: this._googleAdView.setAdSize(AdSize.BANNER);
                break;
            case 2: this._googleAdView.setAdSize(AdSize.LARGE_BANNER);
                break;
            case 3: this._googleAdView.setAdSize(AdSize.MEDIUM_RECTANGLE);
                break;
            case 4: this._googleAdView.setAdSize(AdSize.FULL_BANNER);
                break;
            case 5: this._googleAdView.setAdSize(AdSize.LEADERBOARD);
                break;
            default: this._googleAdView.setAdSize(AdSize.SMART_BANNER);
                break;
        }
    }
    
    
    private void _setGoogleAds(){
        
        //Set up google banner.
        _adLayout = new RelativeLayout(LoaderActivity.m_Activity);
        
        this._googleAdView = new AdView(LoaderActivity.m_Activity);
        this._googleAdView.setAdUnitId(_bannerAdUnitId);
        this._setAdSize();
        //this._googleAdView.setAdSize(adSize);
        
        this._googleAdView.setLayoutParams(_lp);
        _adLayout.addView(_googleAdView);
        
        //Set up interstatial.
        this._mInterstitialAd = new InterstitialAd(LoaderActivity.m_Activity);
        this._mInterstitialAd.setAdUnitId(_interstatialAdUnitId);
        this._mInterstitialAd.setAdListener(admobListener);
        
        //Request the first interstitial ad. So that on request it is ready.
        AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
        adRequestBuilder.addTestDevice(_testDeviceHashId);
        this._mInterstitialAd.loadAd(adRequestBuilder.build());
        
        
        
        try {
            
            if(this._showAtBottom){
                _lp.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM, RelativeLayout.TRUE);
           }
            
            
            LoaderActivity.m_Activity.addContentView(_adLayout, _lp);
                
        } catch (final Exception e) {
            Log.e(logTag, "Init Google view ex. thrown: " + e.toString());
            return;
        }
        
    }    

    public void IsLandscape(boolean landscape)
    {
        this._isLandscape = landscape;
    }
    
    
    public void BannerAdPosition(int position)
    {
        if(position == CG_ADMOB_POSITION_BOTTOM){
            this._showAtBottom = true;
        } else {
            this._showAtBottom = false;
        }
        
        
    }
    
    public void BannerAdSize(int size)
    {
        if(size > 0) {
           adSize = size;
        }
        
    }
    
    public void TestDeviceHashedId(String deviceHashId)
    {
        this._testDeviceHashId = deviceHashId;
    }
    
    public void Release()
    {
        
    }
    
    public AdListener admobListener = new AdListener()
	{
    

    
    @Override
    public void onAdClosed(){
    notifyAdClosed();
    }
    
    @Override
    public void onAdFailedToLoad(int errorCode){
        notifyAdFailedToLoad();
    }

    @Override
    public void onAdLoaded()
    {
        notifyAdLoaded();
    }

    @Override
    public void onAdOpened()
    {
        notifyAdOpened();
    }

    @Override
    public void onAdLeftApplication()
    {
        notifyAdLeftApplication();
    }
};

////////////////////////////////////////////////////////////////
// Native interface
public native void notifyAdClosed();
public native void notifyAdFailedToLoad();
public native void notifyAdLoaded();
public native void notifyAdOpened();
public native void notifyAdLeftApplication();
////////////////////////////////////////////////////////////////

}
