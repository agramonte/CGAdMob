/*
 * iphone-specific implementation of the CGAdMob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "CGAdMob_internal.h"

extern "C"{
#import "GADBannerView.h"
}

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

@interface CGAdMob : NSObject<GADInterstitialDelegate>
@property (nonatomic, strong) GADInterstitial *interstitial;
@property (nonatomic, strong) GADBannerView  *bannerView;
@property (nonatomic) const char *interstatialAdId;
@property (nonatomic, retain) NSString *deviceHashId;
@property (nonatomic) bool interstitialError;
@end

@implementation CGAdMob


/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialDidReceiveAd:(GADInterstitial *)ad
{
    
}

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(GADInterstitial *)ad
    didFailToReceiveAdWithError:(GADRequestError *)error{
    
    NSString *info;
    info = [NSString stringWithFormat:
            @"--------------------------------------- Failed to receive interstitial ad."];
    

    s3eDebugOutputString([info UTF8String]);

    self.interstitialError = true;

}


/// Called just before presenting an interstitial. After this method finishes the interstitial will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the interstitial is on screen (e.g. to visit the App
/// Store from a link on the interstitial).
- (void)interstitialWillPresentScreen:(GADInterstitial *)ad{
    
}

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(GADInterstitial *)ad{
    
}

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(GADInterstitial *)ad{
    
    NSString *info;
    info = [NSString stringWithFormat:
            @"--------------------------------------- Interstitial dismissed."];
    

    s3eDebugOutputString([info UTF8String]);

    s3eEdkGetUIViewController().view = s3eEdkGetUIView();
    
}

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)interstitialWillLeaveApplication:(GADInterstitial *)ad{
    
}



-(void)loadInterstitialRequest{
    
    GADRequest *request = [GADRequest request];
    request.testDevices = @[ self.deviceHashId];
    [self.interstitial loadRequest:request];
    self.interstitial.delegate = self;
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
        self.interstitialError = false;
        
        
        self.initInterstitial;
        self.loadInterstitialRequest;
        
    } else if (self.interstitialError) {
        
        self.initInterstitial;
        self.loadInterstitialRequest;
        
        info = [NSString stringWithFormat:
                @"------------------------Last request failed calling new one."];
        
    } else {
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
bool _displayBannerAdBottom = false;


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
        
        if (_displayBannerAdBottom) {
            
            CGSize adSize = CGSizeFromGADAdSize(kGADAdSizeSmartBannerLandscape);
            
            CGPoint origin = CGPointMake(0.0, s3eEdkGetUIViewController().view.frame.size.height - adSize.height);
            
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerLandscape origin:(CGPoint)origin];
        }else{
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerLandscape];
        }
        
    } else
    {
        if (_displayBannerAdBottom) {
            
            CGSize adSize = CGSizeFromGADAdSize(kGADAdSizeSmartBannerPortrait);
            
            CGPoint origin = CGPointMake(0.0, s3eEdkGetUIViewController().view.frame.size.height - adSize.height);
            
            intAd.bannerView = [[GADBannerView alloc] initWithAdSize:kGADAdSizeSmartBannerPortrait origin:origin];
            
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
    _displayBannerAdBottom = true;
}

void TestDeviceHashedId_platform(const char* deviceHashId)
{
    intAd.deviceHashId = [[NSString alloc] initWithUTF8String:deviceHashId];
}

void Release_platform()
{
}
