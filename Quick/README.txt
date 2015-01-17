Instructions:
1. Add the .cpp and .h file to the respective source and include folder in quick.
2. Add the reference to the header file and or the source file to the respective quickuser_tolua.pkg and quickuser.mkf. (Look at already modified files folder if you have a question).
3. Re-compile quick. Make sure you have new files in the target aarch64 and arm folders inside target inside of quick.
4. Should be able to access them from quick.

If you want to use the already modified files please not that these also include Chartboost:
1. Add the .cpp and .h file to the respective source and include folder in quick.
2. Grab the chart boost files here and do the same with those that you did with the adMob.
	https://github.com/agramonte/CGChartboost
3. Replace your aarch64 and arm folder inside target inside quick with the folders under target AlreadyModifiedFiles->target.
4. Replace the files inside of AlreadyModifiedFiles->quick with the same files inside your quick folder.

Note:
Please save your original files. These files have been modified from a clean install of marmalade.

More help:
Look at my youtube video channel:
https://www.youtube.com/user/MrAdrianjgomez/videos

Post a question in the marmalade forums:
https://answers.madewithmarmalade.com/index.html