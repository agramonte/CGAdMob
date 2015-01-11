CGAdMob
==========
Extremely simplistic implementation of the AdMob Api.

Platform Support: Android, iOS (Library 6.12.2).
Built with Marmalade version: 7.4.3.

Instructional video for the Quick bindings can be found here:
http://youtu.be/BL5s2Emrs7U

NOTE: For both Quick and C++ if you are including the Facebook extension you need to comment out the android-support deployment in the s3eFacebook.mkf:

# android-external-jars=third-party/facebook-android-sdk/libs/android-support-v4.jar

Instructions (test project demonstrates other options):

1. Add the project CGAdMob.

2. In the project mob make sure you add the gps_app_id requirements.
	
	android-extra-strings='(gps_app_id,0)(app_id,fb_app_id)' — If using facebook.
	
	or

	android-extra-strings='(gps_app_id,0)' — If not using Facebook.


3. Set the a banner ad unit and an interstitial ad unitId:

SetGoogleAppKey("banner ad unit id", "interstitial ad unit id”);

4. Initialize the entire thing:

InitAdView()

5. Show banner ad:

BannerAdLoad();

6. Show interstitial:

ShowInterstitialAd();

7. Make sure to release it before your app closes.

Release();





