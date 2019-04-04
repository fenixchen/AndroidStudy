#!/bin/sh

PROG=spwp
adb push /opt/ANDROID_OUT/Nougat/target/product/generic/system/bin/$PROG /data
adb shell chmod 777 /data/$PROG
echo "====================="
adb shell /data/$PROG
