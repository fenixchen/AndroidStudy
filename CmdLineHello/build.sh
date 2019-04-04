#!/bin/sh

set -x

export ANDROID_JAR=/opt/Nougat/prebuilts/sdk/current/android.jar

aapt package -f -m -J src -M AndroidManifest.xml -S res -I $ANDROID_JAR

javac -d obj -source 1.7 -target 1.7 -bootclasspath $ANDROID_JAR src/com/example/helloandroid/*.java

dx --dex --output=bin/classes.dex obj

aapt package -f -m -F bin/hello.unaligned.apk -M AndroidManifest.xml -S res -I $ANDROID_JAR


cp bin/classes.dex .

aapt add bin/hello.unaligned.apk classes.dex 

rm classes.dex


zipalign -f 4 bin/hello.unaligned.apk bin/hello.apk

java -jar apksigner.jar sign --ks mykey.keystore bin/hello.apk

adb install -r bin/hello.apk

adb shell am start -n com.example.helloandroid/.MainActivity

set +x
