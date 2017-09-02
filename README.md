# beagleboneblackened

Purpose of this project is to be familiar with BeagleBone Black development board.

Reference material:

http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide


## First boot

host$ ssh debian@192.168.7.2


Debian GNU/Linux 8

BeagleBoard.org Debian Image 2016-05-13

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian

default username:password is [debian:temppwd]

debian@192.168.7.2's password:

Last login: Fri May  5 17:55:58 2017 from 192.168.7.1

beagle$

beagle$ uname -a

Linux beaglebone 4.4.9-ti-r25 #1 SMP Thu May 5 23:08:13 UTC 2016 armv7l GNU/Linux

beagle$

## U-Boot

=> tftp 0x81000000 kakkatesti
link up on port 0, speed 100, full duplex
Using cpsw device
TFTP from server 192.168.8.1; our IP address is 192.168.8.2
Filename 'kakkatesti'.
Load address: 0x81000000
Loading: 
	 7.8 KiB/s
done
Bytes transferred = 25 (19 hex)
=>

## Cross compile for ARM in the host x86_64 system (Ubuntu 16.04 x86_64 LTS)

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- distclean

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- xconfig

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- zImage

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- am335x-boneblack.dtb

## Build in target (BeagleBone Black)

This is fast start for kernel development if you need just try how simple kernel module works. No need to install crosstools to build ARM architecture on x86 host system.

It's worth to mention that installing crosstools and cross compiling for ARM in host system is recommended!

### Build module
beagle$ ~/dev/hello$ make

### Install module
beagle$~/dev/hello$ sudo insmod hello.ko

### Check kernel log
beagle$~/dev/hello$ tail /var/log/kern.log

May  5 19:14:57 beaglebone kernel: [ 5378.641538] Hello, developer! Module loaded

### Remove module
beagle$~/dev/hello$ sudo rmmod hello

### Check kernel log
beagle$~/dev/hello$ tail /var/log/kern.log

May  5 19:16:02 beaglebone kernel: [ 5443.701192] Goodbye, developer! Module removed
