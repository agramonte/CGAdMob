/*
 * android-specific implementation of the CGAdMob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "CGAdMob_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_InitAdView;
static jmethodID g_ShowInterstitialAd;
static jmethodID g_SetGoogleAppKey;
static jmethodID g_BannerAdLoad;
static jmethodID g_BannerAdShow;
static jmethodID g_BannerAdHide;
static jmethodID g_Release;

s3eResult CGAdMobInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("CGAdMob");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_InitAdView = env->GetMethodID(cls, "InitAdView", "()V");
    if (!g_InitAdView)
        goto fail;

    g_ShowInterstitialAd = env->GetMethodID(cls, "ShowInterstitialAd", "()Z");
    if (!g_ShowInterstitialAd)
        goto fail;

    g_SetGoogleAppKey = env->GetMethodID(cls, "SetGoogleAppKey", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_SetGoogleAppKey)
        goto fail;

    g_BannerAdLoad = env->GetMethodID(cls, "BannerAdLoad", "()V");
    if (!g_BannerAdLoad)
        goto fail;

    g_BannerAdShow = env->GetMethodID(cls, "BannerAdShow", "()V");
    if (!g_BannerAdShow)
        goto fail;

    g_BannerAdHide = env->GetMethodID(cls, "BannerAdHide", "()V");
    if (!g_BannerAdHide)
        goto fail;

    g_Release = env->GetMethodID(cls, "Release", "()V");
    if (!g_Release)
        goto fail;



    IwTrace(CGADMOB, ("CGADMOB init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(CGAdMob, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void CGAdMobTerminate_platform()
{
    // Add any platform-specific termination code here
}

void InitAdView_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_InitAdView);
}

bool ShowInterstitialAd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_ShowInterstitialAd);
}

void SetGoogleAppKey_platform(const char* bannerAdUnitId, const char* interstatialAdUnitId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring bannerAdUnitId_jstr = env->NewStringUTF(bannerAdUnitId);
    jstring interstatialAdUnitId_jstr = env->NewStringUTF(interstatialAdUnitId);
    env->CallVoidMethod(g_Obj, g_SetGoogleAppKey, bannerAdUnitId_jstr, interstatialAdUnitId_jstr);
}

void BannerAdLoad_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_BannerAdLoad);
}

void BannerAdShow_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_BannerAdShow);
}

void BannerAdHide_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_BannerAdHide);
}

void Release_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_Release);
}
