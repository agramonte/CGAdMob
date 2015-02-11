/*
 * Internal header for the CGAdMob extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef CGADMOB_INTERNAL_H
#define CGADMOB_INTERNAL_H

#include "s3eTypes.h"
#include "CGAdMob.h"
#include "CGAdMob_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult CGAdMobInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult CGAdMobInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void CGAdMobTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void CGAdMobTerminate_platform();
void InitAdView_platform();

s3eResult ShowInterstitialAd_platform();

void SetGoogleAppKey_platform(const char* bannerAdUnitId, const char* interstatialAdUnitId);

void BannerAdLoad_platform();

void BannerAdShow_platform();

void BannerAdHide_platform();

void IsLandscape_platform(bool landscape);

void BannerAdPosition_platform(CGAdMobPosition position);

void BannerAdSize_platform(CGAdMobBannerAdSize size);

void TestDeviceHashedId_platform(const char* deviceHashId);

void Release_platform();


#endif /* !CGADMOB_INTERNAL_H */