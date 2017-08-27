# beagleboneblackened

Purpose of this project is to be familiar with BeagleBone Black development board.

## First boot

$ ssh debian@192.168.7.2


Debian GNU/Linux 8

BeagleBoard.org Debian Image 2016-05-13

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian

default username:password is [debian:temppwd]

debian@192.168.7.2's password:

Last login: Fri May  5 17:55:58 2017 from 192.168.7.1

debian@beaglebone:~$

debian@beaglebone:~$ uname -a

Linux beaglebone 4.4.9-ti-r25 #1 SMP Thu May 5 23:08:13 UTC 2016 armv7l GNU/Linux

debian@beaglebone:~$


## Build kernel image for BeagleBone Black

$ git clone https://github.com/torvalds/linux.git

$ cd linux

$ git checkout -b 4.9.y stable/linux-4.9.y

$ make -j$(nproc) ARCH=arm CROSS_COMPILE=/usr/bin/arm-linux-gnueabi- xconfig

$ make -j$(nproc) ARCH=arm CROSS_COMPILE=/usr/bin/arm-linux-gnueabi- zImage

$ make -j$(nproc) ARCH=arm CROSS_COMPILE=/usr/bin/arm-linux-gnueabi- am335x-boneblack.dtb
