/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "CGAdMob.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if defined I3D_ARCH_MIPS || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (MIPS, WP8, Android-x86, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif


#include "CGAdMob_interface.h"

static CGAdMobFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xbfdc71f2, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: CGAdMob");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xbfdc71f2, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool CGAdMobAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult CGAdMobRegister(CGAdMobCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[0] func: CGAdMobRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_CGAdMobRegister);
#endif

    s3eResult ret = g_Ext.m_CGAdMobRegister(cbid, fn, userData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_CGAdMobRegister);
#endif

    return ret;
}

s3eResult CGAdMobUnRegister(CGAdMobCallback cbid, s3eCallback fn)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[1] func: CGAdMobUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_CGAdMobUnRegister);
#endif

    s3eResult ret = g_Ext.m_CGAdMobUnRegister(cbid, fn);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_CGAdMobUnRegister);
#endif

    return ret;
}

void InitAdView()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[2] func: InitAdView"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_InitAdView);
#endif

    g_Ext.m_InitAdView();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_InitAdView);
#endif

    return;
}

s3eResult ShowInterstitialAd()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[3] func: ShowInterstitialAd"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_ShowInterstitialAd);
#endif

    s3eResult ret = g_Ext.m_ShowInterstitialAd();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_ShowInterstitialAd);
#endif

    return ret;
}

void SetGoogleAppKey(const char* bannerAdUnitId, const char* interstatialAdUnitId)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[4] func: SetGoogleAppKey"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_SetGoogleAppKey);
#endif

    g_Ext.m_SetGoogleAppKey(bannerAdUnitId, interstatialAdUnitId);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_SetGoogleAppKey);
#endif

    return;
}

void BannerAdLoad()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[5] func: BannerAdLoad"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_BannerAdLoad);
#endif

    g_Ext.m_BannerAdLoad();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_BannerAdLoad);
#endif

    return;
}

void BannerAdShow()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[6] func: BannerAdShow"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_BannerAdShow);
#endif

    g_Ext.m_BannerAdShow();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_BannerAdShow);
#endif

    return;
}

void BannerAdHide()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[7] func: BannerAdHide"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_BannerAdHide);
#endif

    g_Ext.m_BannerAdHide();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_BannerAdHide);
#endif

    return;
}

void IsLandscape(bool landscape)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[8] func: IsLandscape"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_IsLandscape);
#endif

    g_Ext.m_IsLandscape(landscape);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_IsLandscape);
#endif

    return;
}

void BannerAdPosition(CGAdMobPosition position)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[9] func: BannerAdPosition"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_BannerAdPosition);
#endif

    g_Ext.m_BannerAdPosition(position);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_BannerAdPosition);
#endif

    return;
}

void BannerAdSize(CGAdMobBannerAdSize size)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[10] func: BannerAdSize"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_BannerAdSize);
#endif

    g_Ext.m_BannerAdSize(size);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_BannerAdSize);
#endif

    return;
}

void TestDeviceHashedId(const char* deviceHashId)
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[11] func: TestDeviceHashedId"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_TestDeviceHashedId);
#endif

    g_Ext.m_TestDeviceHashedId(deviceHashId);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_TestDeviceHashedId);
#endif

    return;
}

void Release()
{
    IwTrace(CGADMOB_VERBOSE, ("calling CGAdMob[12] func: Release"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_Release);
#endif

    g_Ext.m_Release();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_Release);
#endif

    return;
}
