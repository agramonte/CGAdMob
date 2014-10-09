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
    private AdView _googleAdView;
	private InterstitialAd _mInterstitialAd;

        //Logging
    private String logTag = "marmalade";
    private String versionNumber = "Version: 1.0.03";
	private String _bannerAdUnitId = "";
    private String _interstatialAdUnitId = "";
	private RelativeLayout.LayoutParams _lp;
    private boolean _isLandscape = false;
    private String _testDeviceHashId = "";
    private boolean _showAtBottom = false;
    
    
    

    public void InitAdView()
    {
        Log.w(logTag, versionNumber);

	        //Create LayoutParams.
        this._lp = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.FILL_PARENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
        

        this._setGoogleAds();
		        
    }
    
    public boolean ShowInterstitialAd()
    {
        boolean adLoaded = false;
        
        if (this._mInterstitialAd.isLoaded()) {
            
            this._mInterstitialAd.show();
            adLoaded = true;
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
                if(rootView.getChildAt(i) == this._googleAdView) {
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
                if(rootView.getChildAt(i) == this._googleAdView) {
                    rootView.getChildAt(i).setVisibility(View.GONE);
                }
            }
            
        } catch (final Exception e) {
            Log.e(logTag, "Hide Google view ex. thrown: " + e.toString());
            return;
        }
        
    }
    
    
    private void _setGoogleAds(){
        
        
        //Set up google banner.
        RelativeLayout adLayout = new RelativeLayout(LoaderActivity.m_Activity);
        
        this._googleAdView = new AdView(LoaderActivity.m_Activity);
        this._googleAdView.setAdUnitId(_bannerAdUnitId);
        this._googleAdView.setAdSize(AdSize.SMART_BANNER);
        
        this._googleAdView.setLayoutParams(_lp);
        adLayout.addView(_googleAdView);
        
        //Set up interstatial.
        this._mInterstitialAd = new InterstitialAd(LoaderActivity.m_Activity);
        this._mInterstitialAd.setAdUnitId(_interstatialAdUnitId);
        
        //Request the first interstitial ad. So that on request it is ready.
        AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
        adRequestBuilder.addTestDevice(_testDeviceHashId);
        this._mInterstitialAd.loadAd(adRequestBuilder.build());
        
        
        
        try {
            
            if(this._showAtBottom){
                _lp.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM, RelativeLayout.TRUE);
           }
            
            
            LoaderActivity.m_Activity.addContentView(adLayout, _lp);
                
        } catch (final Exception e) {
            Log.e(logTag, "Init Google view ex. thrown: " + e.toString());
            return;
        }
        
    }    

    public void IsLandscape(boolean landscape)
    {
        this._isLandscape = landscape;
    }
    
    public void BannerAdPosition(int x, int y)
    {
        if (y != 0)
        {
            this._showAtBottom = true;
        } else
        {
            this._showAtBottom = false;
        }
        
        
    }
               
    public void TestDeviceHashedId(String deviceHashId)
    {
        this._testDeviceHashId = deviceHashId;
    }
               
    public void Release()
    {
        
    }
}
