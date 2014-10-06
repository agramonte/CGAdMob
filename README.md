CGAdMob
==========
Extremely simplistic implementation of the AdMob Api.

Version: 1.0.01

Platform Support: Android 

Instructions:

1. Add the project CGAdMob

2. Set the a banner ad unit and an interstitial ad unitId:

SetGoogleAppKey("banner ad unit id", "interstitial ad unit id”);

3. Initialize the entire thing:

InitAdView()

3. Show banner ad (only at the top at the moment):

BannerAdLoad();

4. Show interstitial:

ShowInterstitialAd();

6. Make sure to release it before your app closes.

Release();


