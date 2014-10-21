#include "GameLayer.h"

static int32 _ad(void *systemData, void *userData)
{
    CCLog("---------------------------Ad Timer.");
    BannerAdLoad();
    ShowInterstitialAd();
    s3eTimerSetTimer(30000, _ad, NULL);
    
    return 0;
}

static int32 onAdMobDismiss(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Ad dismissed.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}

static int32 onAdMobWillDismiss(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Ad will dismissed.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}

static int32 onAdMobPresent(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Ad presented.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}

static int32 onAdMobRecieved(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Ad recieved.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}

static int32 onAdMobFailed(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Ad failed.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}

static int32 onAdLeaveApp(void* systemData, void* userData)
{
    CCLog("---------------------------AdMob Leaving app.");
    CCDirector::sharedDirector()->resume();
    
    return 0;
}



GameLayer::~GameLayer()
{
}

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // Add layer as a child to scene
    scene->addChild(layer);

    // Return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    if (!CCLayer::init())
        return false;

    // Create main loop
    this->schedule(schedule_selector(GameLayer::update));

    // COCOS2D TIP
    // Create Cocos2D objects here
    
    if (CGAdMobAvailable()) {
        
        CCLog("---------------------------AdMob setting Key.");
        //Set up both Ad spot keys.
        SetGoogleAppKey("banner_ad_id", "interstatial_ad_id");
        
        //Optional: Un-comment to make it landscape. It does nothing on Android since the smart ads rotate appropiately. On iOS the documentation states I need it to change a property to landscape, but I have not seen a difference.
        //IsLandscape(true);
        
        //CCLog("---------------------------AdMob adding test device.");
        //Optional: Add the device hash id so that you recieve test ads on your test device.
        //TestDeviceHashedId("test-device-id");
        

        CCLog("---------------------------AdMob setting position.");
        //Optional but not tested without: Specify the position of the ad.
        //BannerAdPosition(CG_ADMOB_POSITION_TOP);
        BannerAdPosition(CG_ADMOB_POSITION_BOTTOM);
        
        
        CCLog("---------------------------AdMob callbacks.");
        //Optional: Register callbacks:
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALWILLDISMISS, onAdMobWillDismiss, this);
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALWILLPRESENT, onAdMobPresent, this);
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALRECEIVED, onAdMobRecieved, this);
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALFAILED, onAdMobFailed, this);
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALDISMISS, onAdMobDismiss, this);
        CGAdMobRegister(CG_ADMOB_CALLBACK_INTERSTITIALLEAVEAPP, onAdLeaveApp, this);
        
        
        CCLog("---------------------------AdMob init view.");
        //Required: Set up the views.
        InitAdView();
        
        //Call this once to show banner ad. And if you have not specified a refresh interval, call it every time you need to refresh the banner ad.
        
        CCLog("---------------------------AdMob load banner ad.");
        BannerAdLoad();
        
        
        //Timer to load the next one.
        s3eTimerSetTimer(5000, _ad, NULL);

        
        
    }
    

	// Create Box2D world
	world = new b2World(b2Vec2(0, 100));

    // BOX2D TIP
    // Create Box2D objects here

    return true;
}

void GameLayer::draw()
{
}

void GameLayer::update(float dt)
{
	// Update Box2D world
	world->Step(dt, 6, 3);

    // BOX2D TIP
    // Update objects from box2d coordinates here
}

