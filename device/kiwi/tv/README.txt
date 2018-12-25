1. Put this folder to <ANDROID_ROOT>/device/kiwi/tv
2. cd <ANDROID_ROOT>
3. source build/envsetup.sh
4. source cache.sh
5. lunch
6. select kiwi_tv-userdebug
7. make -j8
8. emulator   					# default memory, skin
   emulator -verbose -debug,all -show-kernel 	# more debug information
   emulator -skin WVGA800 			# select skin in directory: development/tools/emulator/skins
   emulator -memory 2048			# memory size
