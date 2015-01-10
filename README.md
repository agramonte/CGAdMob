CGAdMob
==========
Extremely simplistic implementation of the AdMob Api.

Platform Support: Android, iOS (Library 6.12.2).

Instructional video for the Quick bindings can be found here:
http://youtu.be/BL5s2Emrs7U

Built with Marmalade version: 7.4.3.

Instructions (test project demonstrates other options):

1. Add the project CGAdMob

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





