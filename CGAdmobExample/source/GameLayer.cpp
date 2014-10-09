#include "GameLayer.h"

static int32 _ad(void *systemData, void *userData)
{
    CCLog("---------------------------Ad Timer.");
    BannerAdLoad();
    ShowInterstitialAd();
    s3eTimerSetTimer(30000, _ad, NULL);
    
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
        
        //Set up both Ad spot keys.
        SetGoogleAppKey("banner app id", "interstatial app id");
        
        //Optional: Un-comment to make it landscape. It does nothing on Android since the smart ads rotate appropiately. On iOS the documentation states I need it to change a property to landscape, but I have not seen a difference.
        //IsLandscape(true);
        
        //Optional: Specify the position of the ad. On iOS the add will be placed as specified. On Android increasing the y axis will result in the ad being placed at the bottom.
        //BannerAdPosition(0, 200);
        
        //Optional: Add the device hash id so that you recieve test ads on your test device.
        //TestDeviceHashedId("your device test hash here.");
        
        //Set up the views.
        InitAdView();
        
        //Call this once to show banner ad. And if you have not specified a refresh interval, call it every time you need to refresh the banner ad.
        BannerAdLoad();
        
        //Timer to load the next one.
        s3eTimerSetTimer(30000, _ad, NULL);
        
        //Show Interstitial.
        ShowInterstitialAd();
        
        
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

