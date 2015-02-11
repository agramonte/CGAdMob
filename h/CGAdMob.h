/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_CGADMOB_H
#define S3E_EXT_CGADMOB_H

#include <s3eTypes.h>

/**
 * Callback events.
 *
 * @par Required Header Files
 * CGAdMob.h
 */
typedef enum CGAdMobCallback
{
    /**
     * Called when an interstitial ad request succeeded. Show it at the next transition point in your
     * application such as when transitioning between view controllers.
     */
    CG_ADMOB_CALLBACK_INTERSTITIALRECEIVED = 0,

    /**
    * Called when an interstitial ad request completed without an interstitial to
    * show. This is common since interstitials are shown sparingly to users.
    */
    CG_ADMOB_CALLBACK_INTERSTITIALFAILED = 1,

    /**
    * Called just before presenting an interstitial. After this method finishes the interstitial will
    * animate onto the screen. Use this opportunity to stop animations and save the state of your
    * application in case the user leaves while the interstitial is on screen (e.g. to visit the App
    Store from a link on the interstitial).
    */
    CG_ADMOB_CALLBACK_INTERSTITIALWILLPRESENT = 2,
    
    /**
    * Called before the interstitial is to be animated off the screen.
    */
    CG_ADMOB_CALLBACK_INTERSTITIALWILLDISMISS = 3,
    
    /**
    * Called just after dismissing an interstitial and it has animated off the screen.
    */
    CG_ADMOB_CALLBACK_INTERSTITIALDISMISS = 4,
    
    /** Called just before the application will background or terminate because the user clicked on an
    * ad that will launch another application (such as the App Store). The normal
    * UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
    * before this.
    */
    CG_ADMOB_CALLBACK_INTERSTITIALLEAVEAPP = 5,

    CGADMOB_CALLBACK_MAX
} CGAdMobCallback;



/**
 * Ad position.
 *
 * @par Required Header Files
 * CGAdMob.h
 */
typedef enum CGAdMobPosition
{
    CG_ADMOB_POSITION_TOP    = 1,  ///< Ad is positioned at top of screen.
    CG_ADMOB_POSITION_BOTTOM = 2,  ///< Ad is positioned at bottom of screen.
} CGAdMobPosition;


/**
* Banner Ad Size.
*
* @par Required Header Files
* CGAdMob.h
*/
typedef enum CGAdMobBannerAdSize
{

    CG_ADMOB_SMART = 0, ///< Default ad size.
    CG_ADMOB_320x50 = 1,
    CG_ADMOB_320x100 = 2,
    CG_ADMOB_300x250 = 3,
    CG_ADMOB_468x60 = 4,
    CG_ADMOB_728x90 = 5,

} CGAdMobBannerAdSize;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the CGAdMob extension is available.
 */
s3eBool CGAdMobAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref CGAdMobCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see CGAdMobUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref CGAdMobCallback enum.
 */
s3eResult CGAdMobRegister(CGAdMobCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the CGAdMobCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see CGAdMobRegister
 */
s3eResult CGAdMobUnRegister(CGAdMobCallback cbid, s3eCallback fn);

/**
 * Most work is done in this method. Call it after setting up the key.
 */
void InitAdView();

/**
 * Returns true if the interstitial ad ready and was displayed successfully.
 */
s3eResult ShowInterstitialAd();

/**
* Currently only works with a max of 2 ad units. This might change in the future.
*/
void SetGoogleAppKey(const char* bannerAdUnitId, const char* interstatialAdUnitId);

/**
 * Load the ad. Needs to be called every time you need the ad refreshed.
 * Make sure you turn off auto refresh in the admob ad unit configuration.
 */
void BannerAdLoad();

/**
 * Show the banner ad.
 */
void BannerAdShow();

/**
 * Hide the banner ad.
 */
void BannerAdHide();

/**
 * Optional: True to display banner ad in Landscape mode. Default is false.
 */
void IsLandscape(bool landscape);

/**
* Optional: If not called banner will display at the top.
*/
void BannerAdPosition(CGAdMobPosition position);

/**
* Optional: If not called banner size will be "Smart Banner" as defined by Google.
*/
void BannerAdSize(CGAdMobBannerAdSize size);

/**
* Optional: Sets the test device string.
*/
void TestDeviceHashedId(const char* deviceHashId);

/**
 * Release any resources.
 */
void Release();

S3E_END_C_DECL

#endif /* !S3E_EXT_CGADMOB_H */
