CGAdMob
==========
Extremely simplistic implementation of the AdMob Api.

Platform Support: Android, iOS (Library 7.0).

Built with Marmalade version: 7.5 and iOS 8 SDK

Instructions (test project demonstrates other options):

1. Add the project CGAdMob

2. Add the extra string value to deployment section. If you are using a function that needs an Id you need to replace the 0 with your id. Otherwise 0 is fine for AdMob.

deployment{
	android-extra-strings='(gps_app_id,0)' 
}

2. Set the a banner ad unit and an interstitial ad unitId:

SetGoogleAppKey("banner ad unit id", "interstitial ad unit id”);

3. Initialize the entire thing:

InitAdView()

4. Show banner ad:

BannerAdLoad();

5. Show interstitial:

ShowInterstitialAd();

6. Make sure to release it before your app closes.

Release();


