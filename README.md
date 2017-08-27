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

## Build in target

This is fast start for kernel development if you need just try how simple kernel module works. No need to install crosstools to build ARM architecture on x86 host system.

It's worth to mention that installing crosstools and cross compiling for ARM in host system is recommended!

### Build module
debian@beaglebone:~/dev/hello$ make

### Install module
debian@beaglebone:~/dev/hello$ sudo insmod hello.ko

### Check kernel log
debian@beaglebone:~/dev/hello$ tail /var/log/kern.log

May  5 18:17:50 beaglebone kernel: [ 1951.525671] Hello Foobar from driver init.

### Remove module
debian@beaglebone:~/dev/hello$ sudo rmmod hello

### Check kernel log
debian@beaglebone:~/dev/hello$ tail /var/log/kern.log

May  5 18:19:11 beaglebone kernel: [ 2033.199746] Goodbye, Foobar!
