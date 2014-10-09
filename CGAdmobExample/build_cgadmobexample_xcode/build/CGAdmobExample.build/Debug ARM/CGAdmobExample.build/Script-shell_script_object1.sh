#!/bin/bash
set -e
if [ "$CONFIGURATION" = "Release" -o "$CONFIGURATION" = "Release ARM" ]; then echo "skipping for release builds" && exit 0; fi
if [ "$CONFIGURATION" = "Debug ARM" -o "$CONFIGURATION" = "Release ARM" ]; then echo "skipping for arm builds" && exit 0; fi
export GCC_THUMB_SUPPORT='NO'
PATH="/Applications/Marmalade.app/Contents/tools/gcc/x86/android_osx/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/gcc/darwin/bin":$PATH
PATH="/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin":$PATH
PATH="/opt/local/bin":$PATH
cd "/Applications/Marmalade.app/Contents/s3e/loader/osx"
/usr/bin/python ./postlink.py "${TARGET_BUILD_DIR}/${EXECUTABLE_NAME}" "/Users/adriangomez/OneDrive/Development/CGAdmobExample/build_cgadmobexample_xcode/build/${CONFIGURATION}${EFFECTIVE_PLATFORM_NAME}/CGAdmobExample.s86"
