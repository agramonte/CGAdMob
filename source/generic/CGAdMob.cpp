/*
Generic implementation of the CGAdMob extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "CGAdMob_internal.h"
s3eResult CGAdMobInit()
{
    //Add any generic initialisation code here
    return CGAdMobInit_platform();
}

void CGAdMobTerminate()
{
    //Add any generic termination code here
    CGAdMobTerminate_platform();
}

void InitAdView()
{
	InitAdView_platform();
}

s3eResult ShowInterstitialAd()
{
	ShowInterstitialAd_platform();
}

void SetGoogleAppKey(const char* bannerAdUnitId, const char* interstatialAdUnitId)
{
	SetGoogleAppKey_platform(bannerAdUnitId, interstatialAdUnitId);
}

void BannerAdLoad()
{
	BannerAdLoad_platform();
}

void BannerAdShow()
{
	BannerAdShow_platform();
}

void BannerAdHide()
{
	BannerAdHide_platform();
}

void IsLandscape(bool landscape)
{
	IsLandscape_platform(landscape);
}

void BannerAdPosition(CGAdMobPosition position)
{
	BannerAdPosition_platform(position);
}

void BannerAdSize(CGAdMobBannerAdSize size)
{
	BannerAdSize_platform(size);
}

void TestDeviceHashedId(const char* deviceHashId)
{
	TestDeviceHashedId_platform(deviceHashId);
}

void Release()
{
	Release_platform();
}
