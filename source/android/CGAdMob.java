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
    private String versionNumber = "Version: 1.0.01";
	private String _bannerAdUnitId = "";
    private String _interstatialAdUnitId = "";
	private RelativeLayout.LayoutParams _lp;
    
    
    

    public void InitAdView()
    {
        Log.e(logTag, versionNumber);

	        //Create LayoutParams.
        _lp = new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.WRAP_CONTENT);

        _setGoogleAds();
		        
    }
    public boolean ShowInterstitialAd()
    {
        if (_mInterstitialAd.isLoaded()) {
            
            _mInterstitialAd.show();
            AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
            _mInterstitialAd.loadAd(adRequestBuilder.build());
            
            return true;
        } else {
            AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
            _mInterstitialAd.loadAd(adRequestBuilder.build());
            return  false;
        }
        
        
        
    }
    public void SetGoogleAppKey(String bannerAdUnitId, String interstatialAdUnitId)
    {
        _interstatialAdUnitId = interstatialAdUnitId;
        _bannerAdUnitId = bannerAdUnitId;
    }
    public void BannerAdLoad()
    {
        AdRequest adRequest = new AdRequest.Builder().build();
        this._googleAdView.loadAd(adRequest);
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
    public void Release()
    {
         _googleAdView.destroy();
    }

    private void _setGoogleAds(){
        
        
            this._googleAdView = new AdView(LoaderActivity.m_Activity);
            this._googleAdView.setAdUnitId(_bannerAdUnitId);
            this._googleAdView.setAdSize(com.google.android.gms.ads.AdSize.BANNER);
        
            this._mInterstitialAd = new InterstitialAd(LoaderActivity.m_Activity);
            this._mInterstitialAd.setAdUnitId(_interstatialAdUnitId);
        
            AdRequest.Builder adRequestBuilder = new AdRequest.Builder();
            _mInterstitialAd.loadAd(adRequestBuilder.build());

            this._googleAdView.setLayoutParams(_lp);
            
            try {
                LoaderActivity.m_Activity.addContentView(_googleAdView, _lp);
                
            } catch (final Exception e) {
                Log.e(logTag, "Init Google view ex. thrown: " + e.toString());
                return;
            }
        
    }
}
