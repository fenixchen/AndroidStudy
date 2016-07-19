#!/bin/sh
PROG=Sync
set -x
adb push /home/tv/ANDROID_OUT/ANDROID/target/product/generic/system/bin/$PROG /data
adb shell chmod 777 /data/$PROG
set +x
echo "====================="
set -x
adb shell /data/$PROG
set +x
