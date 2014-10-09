#!/bin/bash
set -e
if [ "$CONFIGURATION" = "Debug" -o "$CONFIGURATION" = "Debug ARM" ]; then echo "skipping for debug builds" && exit 0; fi
if [ "$CONFIGURATION" = "Debug ARM" -o "$CONFIGURATION" = "Release ARM" ]; then echo "skipping for arm builds" && exit 0; fi
export GCC_THUMB_SUPPORT='NO'
PATH="/Applications/Marmalade.app/Contents/tools/gcc/x86/android_osx/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/gcc/darwin/bin":$PATH
PATH="/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin":$PATH
PATH="/opt/local/bin":$PATH
s3e_plink -l "/Users/adriangomez/OneDrive/Development/CGAdmobExample/build_cgadmobexample_xcode/build/${CONFIGURATION}${EFFECTIVE_PLATFORM_NAME}/CGAdmobExample.s86"
