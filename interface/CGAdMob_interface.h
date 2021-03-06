/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*CGAdMobRegister_t)(CGAdMobCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*CGAdMobUnRegister_t)(CGAdMobCallback cbid, s3eCallback fn);
typedef       void(*InitAdView_t)();
typedef  s3eResult(*ShowInterstitialAd_t)();
typedef       void(*SetGoogleAppKey_t)(const char* bannerAdUnitId, const char* interstatialAdUnitId);
typedef       void(*BannerAdLoad_t)();
typedef       void(*BannerAdShow_t)();
typedef       void(*BannerAdHide_t)();
typedef       void(*IsLandscape_t)(bool landscape);
typedef       void(*BannerAdPosition_t)(CGAdMobPosition position);
typedef       void(*BannerAdSize_t)(CGAdMobBannerAdSize size);
typedef       void(*TestDeviceHashedId_t)(const char* deviceHashId);
typedef       void(*Release_t)();

/**
 * struct that gets filled in by CGAdMobRegister
 */
typedef struct CGAdMobFuncs
{
    CGAdMobRegister_t m_CGAdMobRegister;
    CGAdMobUnRegister_t m_CGAdMobUnRegister;
    InitAdView_t m_InitAdView;
    ShowInterstitialAd_t m_ShowInterstitialAd;
    SetGoogleAppKey_t m_SetGoogleAppKey;
    BannerAdLoad_t m_BannerAdLoad;
    BannerAdShow_t m_BannerAdShow;
    BannerAdHide_t m_BannerAdHide;
    IsLandscape_t m_IsLandscape;
    BannerAdPosition_t m_BannerAdPosition;
    BannerAdSize_t m_BannerAdSize;
    TestDeviceHashedId_t m_TestDeviceHashedId;
    Release_t m_Release;
} CGAdMobFuncs;
