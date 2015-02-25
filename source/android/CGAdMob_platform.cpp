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


 static void cgAdmob_NotifyAdClosed(JNIEnv *, jobject);
 static void cgAdmob_NotifyAdFailedToLoad(JNIEnv *, jobject);
 static void cgAdmob_NotifyAdLoaded(JNIEnv *, jobject);
 static void cgAdmob_NotifyAdOpened(JNIEnv *, jobject);
 static void cgAdmob_NotifyAdLeftApplication(JNIEnv *, jobject);


static jobject g_Obj;
static jmethodID g_InitAdView;
static jmethodID g_ShowInterstitialAd;
static jmethodID g_SetGoogleAppKey;
static jmethodID g_BannerAdLoad;
static jmethodID g_BannerAdShow;
static jmethodID g_BannerAdHide;
static jmethodID g_IsLandscape;
static jmethodID g_BannerAdPosition;
static jmethodID g_BannerAdSize;
static jmethodID g_TestDeviceHashedId;
static jmethodID g_Release;

s3eResult CGAdMobInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

     const JNINativeMethod nativeMethodDefs[] = {
     { "notifyAdClosed", "()V", (void *)&cgAdmob_NotifyAdClosed },
     { "notifyAdFailedToLoad", "()V", (void *)&cgAdmob_NotifyAdFailedToLoad },
     { "notifyAdLoaded", "()V", (void *)&cgAdmob_NotifyAdLoaded },
     { "notifyAdOpened", "()V", (void *)&cgAdmob_NotifyAdOpened },
     { "notifyAdLeftApplication", "()V", (void *)&cgAdmob_NotifyAdLeftApplication },
     
     };
    
    
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

    g_ShowInterstitialAd = env->GetMethodID(cls, "ShowInterstitialAd", "()I");
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

    g_IsLandscape = env->GetMethodID(cls, "IsLandscape", "(Z)V");
    if (!g_IsLandscape)
        goto fail;

    g_BannerAdPosition = env->GetMethodID(cls, "BannerAdPosition", "(I)V");
    if (!g_BannerAdPosition)
        goto fail;

    g_BannerAdSize = env->GetMethodID(cls, "BannerAdSize", "(I)V");
    if (!g_BannerAdSize)
        goto fail;

    g_TestDeviceHashedId = env->GetMethodID(cls, "TestDeviceHashedId", "(Ljava/lang/String;)V");
    if (!g_TestDeviceHashedId)
        goto fail;

    g_Release = env->GetMethodID(cls, "Release", "()V");
    if (!g_Release)
        goto fail;

    env->RegisterNatives(cls, nativeMethodDefs, sizeof(nativeMethodDefs)/sizeof(nativeMethodDefs[0]));
    

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

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void CGAdMobTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void InitAdView_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_InitAdView);
}

s3eResult ShowInterstitialAd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_ShowInterstitialAd);
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

void IsLandscape_platform(bool landscape)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_IsLandscape, landscape);
}

void BannerAdPosition_platform(CGAdMobPosition position)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_BannerAdPosition, position);
}

void BannerAdSize_platform(CGAdMobBannerAdSize size)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_BannerAdSize, size);
}

void TestDeviceHashedId_platform(const char* deviceHashId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring deviceHashId_jstr = env->NewStringUTF(deviceHashId);
    env->CallVoidMethod(g_Obj, g_TestDeviceHashedId, deviceHashId_jstr);
}

void Release_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_Release);
}

//------------------------------------------------

 void cgAdmob_NotifyAdClosed(JNIEnv *evn, jobject obj)
 {
   s3eEdkCallbacksEnqueue(S3E_EXT_CGADMOB_HASH, CG_ADMOB_CALLBACK_INTERSTITIALDISMISS);
 }
 
 void cgAdmob_NotifyAdFailedToLoad(JNIEnv *evn, jobject obj)
 {
 s3eEdkCallbacksEnqueue(S3E_EXT_CGADMOB_HASH, CG_ADMOB_CALLBACK_INTERSTITIALFAILED);
 }
 
 void cgAdmob_NotifyAdLoaded(JNIEnv * env, jobject obj)
 {
 s3eEdkCallbacksEnqueue(S3E_EXT_CGADMOB_HASH, CG_ADMOB_CALLBACK_INTERSTITIALRECEIVED);
 }
 
 void cgAdmob_NotifyAdOpened(JNIEnv * env, jobject obj)
 {
 s3eEdkCallbacksEnqueue(S3E_EXT_CGADMOB_HASH,CG_ADMOB_CALLBACK_INTERSTITIALWILLPRESENT);
 
 }
 
 void cgAdmob_NotifyAdLeftApplication(JNIEnv * env, jobject obj)
 {
 s3eEdkCallbacksEnqueue(S3E_EXT_CGADMOB_HASH, CG_ADMOB_CALLBACK_INTERSTITIALLEAVEAPP);
 }
