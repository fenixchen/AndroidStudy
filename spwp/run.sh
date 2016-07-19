#!/bin/sh

PROG=spwp
adb push /home/tv/ANDROID_OUT/ANDROID/target/product/generic/system/bin/$PROG /data
adb shell chmod 777 /data/$PROG
echo "====================="
adb shell /data/$PROG
