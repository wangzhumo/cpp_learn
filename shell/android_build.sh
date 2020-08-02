#!/bin/bash

# NDK path
export NDK_ROOT=/home/wangzhumo/Library/Android/android-ndk-r20b

# TOOLCHAIN cross-complie tool gcc
export TOOLCHAIN=$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin

# android api
export API=21

# systoot
export SYSROOT=$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot

# ARCH
ARCH=aarch64
PLATFORM=aarch64

# TARGET
TARGET=$PLATFORM-linux-android

# prefix
PREFIX=/home/wangzhumo/Library/ffmpeg-4.2.2/android/$CPU

# FLAGS complie flags
FLAGS="-D__ANDROID_API__=$API -Os -fPIC -DANDROID "

function build_android()
{

	echo "Compiling FFmpeg for $CPU"
	./configure \
		--prefix=$PREFIX \
		--cc=$CC \
		--cxx=$CXX \
		--ld=$TOOLCHAIN/$TARGET$API-clang \
		--target-os=android \
		--arch=$ARCH \
		--cross-prefix=$CROSS_PREFIX \
		--enable-cross-compile \
		--enable-shared \
		--enable-jni \
		--cpu=$CPU \
		--enable-runtime-cpudetect \
		--disable-asm \
		--sysroot=$SYSROOT \
		--extra-cflags="$FLAGS $OPTIMIZE_CFLAGS " \
		--extra-ldflags="$ADDI_LIDFLAGS " \
		$ADDITIONAL_CONFIGURE_FLAG


	make clean
	echo "FFmpeg for $CPU completed"
}


#armv7-a
ARCH=arm
CPU=armv7-a
CC=$TOOLCHAIN/armv7a-linux-androideabi$API-clang
CXX=$TOOLCHAIN/armv7a-linux-androideabi$API-clang++
CROSS_PREFIX=$TOOLCHAIN/arm-linux-androideabi-
OPTIMIZE_CFLAGS="-mfloat-abi=softfp -mfpu=vfp -marm -march=$CPU "

build_android

#x86
ARCH=x86
CPU=x86
CC=$TOOLCHAIN/i686-linux-android$API-clang
CXX=$TOOLCHAIN/i686-linux-android$API-clang++
CROSS_PREFIX=$TOOLCHAIN/i686-linux-android-
OPTIMIZE_CFLAGS="-march=i686 -mtune=intel -mssse3 -mfpmath=sse -m32"

# build_android

#x86_64
ARCH=x86_64
CPU=x86-64
CC=$TOOLCHAIN/x86_64-linux-android$API-clang
CXX=$TOOLCHAIN/x86_64-linux-android$API-clang++
CROSS_PREFIX=$TOOLCHAIN/x86_64-linux-android-
OPTIMIZE_CFLAGS="-march=$CPU -msse4.2 -mpopcnt -m64 -mtune=intel"

# build_android
