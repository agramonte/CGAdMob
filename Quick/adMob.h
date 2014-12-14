#ifndef __CG_ADMOB_H
#define __CG_ADMOB_H


// tolua_begin
namespace admob {
    
    
    bool adMobAvailable();
    void adMobInit(const char* bannerUnitId, const char* interstatialUnitId, bool isLandscape, bool placeBottom);
    void adMobSetTestDevice(const char* deviceHashId);
    bool adMobPresentInterstitial();
    void adMobPresentBanner();
    void adMobBannerShow();
    void adMobBannerHide();
    
}

// tolua_end

#endif // __CG_ADMOB_H