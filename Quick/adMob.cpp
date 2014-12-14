#include "CGAdMob.h"
#include "adMob.h"

static const char* testDeviceId;


namespace admob {
    
//-------------------------------------------------
    bool adMobAvailable()
    {
        return CGAdMobAvailable();
        
    }
    
    void adMobInit(const char* bannerUnitId, const char* interstatialUnitId, bool isLandscape, bool placeBottom)
    {
        IsLandscape(isLandscape);
        
        if (placeBottom) {
            BannerAdPosition(CG_ADMOB_POSITION_BOTTOM);
        }else{
            BannerAdPosition(CG_ADMOB_POSITION_TOP);
        }
        
        TestDeviceHashedId(testDeviceId);
        
        SetGoogleAppKey(bannerUnitId, interstatialUnitId);
        
        InitAdView();
    }
    
    
    void adMobSetTestDevice(const char* deviceHashId)
    {
        testDeviceId = deviceHashId;
    }
    
    bool adMobPresentInterstitial()
    {
        return ShowInterstitialAd();
    }
    
    void adMobPresentBanner()
    {
        BannerAdLoad();
    }
    
    void adMobBannerShow()
    {
        BannerAdShow();
    }
    
    void adMobBannerHide()
    {
        BannerAdHide();
    }
    
    


} // namespace admob


