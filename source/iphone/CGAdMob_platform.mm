/*
 * iphone-specific implementation of the CGAdMob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "CGAdMob_internal.h"
#include "GADAdSize.h"
#include "GADBannerView.h"
#include "GADBannerViewDelegate.h"
#include "GADInterstitial.h"
#include "GADInterstitialDelegate.h"
#include "GADModules.h"
#include "GADRequest.h"
#include "GADRequestError.h"
#include "s3eEdk.h"
#include "s3eEdk_iphone.h"
#include "s3eDebug.h"

#import <UIKit/UIKit.h>



//===========================================================================//
//========================= ViewController ===============================//
//===========================================================================//

@interface CGAdMob : NSObject
@property (nonatomic, strong) GADInterstitial *interstitial;
@property (nonatomic, strong) GADBannerView  *bannerView;
@property (nonatomic) const char *interstatialAdId;
@property (nonatomic, retain) NSString *deviceHashId;
@end

@implementation CGAdMob


-(void)loadInterstitialRequest{
    
    GADRequest *request = [GADRequest request];
    request.testDevices = @[ self.deviceHashId];
    [self.interstitial loadRequest:request];
}

-(void)loadBannerRequest{
    
    GADRequest *request = [GADRequest request];
    request.testDevices = @[ self.deviceHashId];
    [self.bannerView loadRequest:request];
}

-(void)initInterstitial:(const char *)appId{
    
    self.interstatialAdId = appId;
    self.initInterstitial;
}

-(void)initInterstitial{
    
    self.interstitial = [[GADInterstitial alloc] init];
    self.interstitial.adUnitID = [[NSString alloc] initWithUTF8String:self.interstatialAdId];
    
}

-(void)showInterstitial{
    
    NSString *info;
    if ([self.interstitial isReady]) {
        
        info = [NSString stringWithFormat:
                @"--------------------------------------- Interstitial is Ready."];
        
        [self.interstitial presentFromRootViewController:s3eEdkGetUIViewController()];
        
        self.initInterstitial;
        self.loadInterstitialRequest;
        
    } else
    {
        
        info = [NSString stringWithFormat:
                @"--------------------------------------- Interstitial not Ready."];
    }
    
    s3eDebugOutputString([info UTF8String]);
}

@end

//===========================================================================//
//========================= end ===============================//
//===========================================================================//

CGAdMob *intAd = [[CGAdMob alloc] autorelease];

const char* _bannerAdUnitId = "";
const char* _interstatialAdUnitId = "";
bool _landscape = false;
CGPoint _point;
bool _pointSet = false;


s3eResult CGAdMobInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void CGAdMobTerminate_platform()
{
}

void InitAdView_platform()
{
    //Start the banner ads
    if (_landscape) {
        
        if (_pointSet) {
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerLandscape origin:(CGPoint)_point];
        }else
        {
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerLandscape];
        }
        
    } else
    {
        if (_pointSet) {
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerPortrait origin:(CGPoint)_point];
        } else {
        intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerPortrait];
        }
    }
    
    intAd.bannerView.adUnitID = [[NSString alloc] initWithUTF8String:_bannerAdUnitId];
    intAd.bannerView.rootViewController = s3eEdkGetUIViewController();
    
    [s3eEdkGetUIView() addSubview:intAd.bannerView];
    [intAd loadBannerRequest];
    
    //Start the interstitial
    [intAd initInterstitial:_interstatialAdUnitId];
    [intAd loadInterstitialRequest];
}

bool ShowInterstitialAd_platform()
{
    [intAd showInterstitial];
    return true;
}

void SetGoogleAppKey_platform(const char* bannerAdUnitId, const char* interstatialAdUnitId)
{
    _bannerAdUnitId = bannerAdUnitId;
    _interstatialAdUnitId = interstatialAdUnitId;
}


void BannerAdLoad_platform()
{
    [intAd loadBannerRequest];
}

void BannerAdShow_platform()
{
    [intAd.bannerView setHidden:YES];
}

void BannerAdHide_platform()
{
    [intAd.bannerView setHidden:NO];
}

void IsLandscape_platform(bool landscape)
{
    _landscape = landscape;
    
}

void BannerAdPosition_platform(int x, int y)
{
    _point.x = x;
    _point.y = y;
    _pointSet = true;
}

void TestDeviceHashedId_platform(const char* deviceHashId)
{
    intAd.deviceHashId = [[NSString alloc] initWithUTF8String:deviceHashId];
}

void Release_platform()
{
}
