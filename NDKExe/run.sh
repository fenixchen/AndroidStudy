ndk-build || exit
adb push libs/armeabi/hello_world /data/ || exit
adb shell chmod 777 /data/hello_world || exit
echo -e "Execute\n============================"
adb shell /data/hello_world
echo -e "============================"
