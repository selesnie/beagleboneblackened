# beagleboneblackened

Purpose of this project is to be familiar with BeagleBone Black development board.

Reference material:

http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide


## First boot from eMMC (BeagleBone Black flash memory)

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

## Cross compile for ARM in the host x86_64 system (Ubuntu 16.04 x86_64 LTS)

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- distclean && make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- xconfig

host$ make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- zImage && make -j$(nproc) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- am335x-boneblack.dtb

## Boot cross compiled kernel and filesystem using U-Boot

U-Boot SPL 2016.03-00001-gd12d09f (Mar 17 2016 - 16:16:15)
Trying to boot from MMC
bad magic


U-Boot 2016.03-00001-gd12d09f (Mar 17 2016 - 16:16:15 -0500), Build: jenkins-github_Bootloader-Builder-351

       Watchdog enabled
I2C:   ready
DRAM:  512 MiB
Reset Source: Global external warm reset has occurred.
Reset Source: Global warm SW reset has occurred.
Reset Source: Power-on reset has occurred.
MMC:   OMAP SD/MMC: 0, OMAP SD/MMC: 1
Using default environment

Net:   <ethaddr> not set. Validating first E-fuse MAC
cpsw, usb_ether
Press SPACE to abort autoboot in 2 seconds

=> setenv ipaddr 192.168.8.2

=> setenv serverip 192.168.8.1

=> setenv bootargs root=/dev/nfs rw ip=192.168.8.2 console=ttyO0 nfsroot=192.168.8.1:/home/daigo/linux-kernel-labs/modules/nfsroot

=> tftp 0x81000000 zImage

link up on port 0, speed 100, full duplex
Using cpsw device
TFTP from server 192.168.8.1; our IP address is 192.168.8.2
Filename 'zImage'.
Load address: 0x81000000
Loading: #################################################################
	 #################################################################
	 #################################################################
	 #################################################################
	 #################################################################
	 #################################################################
	 #################################################################
	 ############################
	 3.2 MiB/s
done
Bytes transferred = 7078408 (6c0208 hex)

=> tftp 0x82000000 am335x-boneblack.dtb

link up on port 0, speed 100, full duplex
Using cpsw device
TFTP from server 192.168.8.1; our IP address is 192.168.8.2
Filename 'am335x-boneblack.dtb'.
Load address: 0x82000000
Loading: ###
	 1.1 MiB/s
done
Bytes transferred = 34184 (8588 hex)

=> bootz 0x81000000 - 0x82000000

Kernel image @ 0x81000000 [ 0x000000 - 0x6c0208 ]
Flattened Device Tree blob at 82000000
   Booting using the fdt blob at 0x82000000
   Loading Device Tree to 8fff4000, end 8ffff587 ... OK

Starting kernel ...

[    0.000000] Booting Linux on physical CPU 0x0
[    0.000000] Linux version 4.9.44 (daigo@daigo-UX32VD) (gcc version 5.4.0 20160609 (Ubuntu/Linaro 5.4.0-6ubuntu1~16.04.4) ) #1 SMP Sun Aug 27 13:06:40 EEST 2017
[    0.000000] CPU: ARMv7 Processor [413fc082] revision 2 (ARMv7), cr=10c5387d
[    0.000000] CPU: PIPT / VIPT nonaliasing data cache, VIPT aliasing instruction cache
[    0.000000] OF: fdt:Machine model: TI AM335x BeagleBone Black
[    0.000000] efi: Getting EFI parameters from FDT:
[    0.000000] efi: UEFI not found.
[    0.000000] cma: Reserved 64 MiB at 0x9b800000
[    0.000000] Memory policy: Data cache writeback
[    0.000000] CPU: All CPU(s) started in SVC mode.
[    0.000000] AM335X ES2.1 (sgx neon)
[    0.000000] percpu: Embedded 14 pages/cpu @df9ae000 s26636 r8192 d22516 u57344
[    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 129540
[    0.000000] Kernel command line: root=/dev/nfs rw ip=192.168.8.2 console=ttyO0 nfsroot=192.168.8.1:/home/daigo/linux-kernel-labs/modules/nfsroot
[    0.000000] PID hash table entries: 2048 (order: 1, 8192 bytes)
[    0.000000] Dentry cache hash table entries: 65536 (order: 6, 262144 bytes)
[    0.000000] Inode-cache hash table entries: 32768 (order: 5, 131072 bytes)
[    0.000000] Memory: 433984K/522240K available (9216K kernel code, 1126K rwdata, 3872K rodata, 2048K init, 342K bss, 22720K reserved, 65536K cma-reserved, 0K highmem)
[    0.000000] Virtual kernel memory layout:
[    0.000000]     vector  : 0xffff0000 - 0xffff1000   (   4 kB)
[    0.000000]     fixmap  : 0xffc00000 - 0xfff00000   (3072 kB)
[    0.000000]     vmalloc : 0xe0000000 - 0xff800000   ( 504 MB)
[    0.000000]     lowmem  : 0xc0000000 - 0xdfe00000   ( 510 MB)
[    0.000000]     pkmap   : 0xbfe00000 - 0xc0000000   (   2 MB)
[    0.000000]     modules : 0xbf000000 - 0xbfe00000   (  14 MB)
[    0.000000]       .text : 0xc0208000 - 0xc0c00000   (10208 kB)
[    0.000000]       .init : 0xc1100000 - 0xc1300000   (2048 kB)
[    0.000000]       .data : 0xc1300000 - 0xc14199a0   (1127 kB)
[    0.000000]        .bss : 0xc141b000 - 0xc1470bb8   ( 343 kB)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
[    0.000000] Hierarchical RCU implementation.
[    0.000000] 	Build-time adjustment of leaf fanout to 32.
[    0.000000] 	RCU restricting CPUs from NR_CPUS=16 to nr_cpu_ids=1.
[    0.000000] RCU: Adjusting geometry for rcu_fanout_leaf=32, nr_cpu_ids=1
[    0.000000] NR_IRQS:16 nr_irqs:16 16
[    0.000000] IRQ: Found an INTC at 0xfa200000 (revision 5.0) with 128 interrupts
[    0.000000] OMAP clockevent source: timer2 at 24000000 Hz
[    0.000013] sched_clock: 32 bits at 24MHz, resolution 41ns, wraps every 89478484971ns
[    0.000031] clocksource: timer1: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 79635851949 ns
[    0.000041] OMAP clocksource: timer1 at 24000000 Hz
[    0.003344] clocksource_probe: no matching clocksources found
[    0.003509] Console: colour dummy device 80x30
[    0.003547] Calibrating delay loop... 997.78 BogoMIPS (lpj=2494464)
[    0.059272] pid_max: default: 32768 minimum: 301
[    0.059397] Mount-cache hash table entries: 1024 (order: 0, 4096 bytes)
[    0.059410] Mountpoint-cache hash table entries: 1024 (order: 0, 4096 bytes)
[    0.060097] CPU: Testing write buffer coherency: ok
[    0.060439] CPU0: thread -1, cpu 0, socket -1, mpidr 0
[    0.060493] Setting up static identity map for 0x80300000 - 0x80300098
[    0.063601] EFI services will not be available.
[    0.063854] Brought up 1 CPUs
[    0.063867] SMP: Total of 1 processors activated (997.78 BogoMIPS).
[    0.063874] CPU: All CPU(s) started in SVC mode.
[    0.065239] devtmpfs: initialized
[    0.074638] VFP support v0.3: implementor 41 architecture 3 part 30 variant c rev 3
[    0.075206] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 9556302231375000 ns
[    0.075239] futex hash table entries: 256 (order: 2, 16384 bytes)
[    0.078980] pinctrl core: initialized pinctrl subsystem
[    0.081197] NET: Registered protocol family 16
[    0.083176] DMA: preallocated 256 KiB pool for atomic coherent allocations
[    0.099532] omap_hwmod: debugss: _wait_target_disable failed
[    0.152856] cpuidle: using governor menu
[    0.159742] OMAP GPIO hardware version 0.1
[    0.175785] No ATAGs?
[    0.175810] hw-breakpoint: debug architecture 0x4 unsupported.
[    0.176201] omap4_sram_init:Unable to allocate sram needed to handle errata I688
[    0.176212] omap4_sram_init:Unable to get sram pool needed to handle errata I688
[    0.179697] Serial: AMBA PL011 UART driver
[    0.198953] edma 49000000.edma: TI EDMA DMA engine driver
[    0.202334] vgaarb: loaded
[    0.203188] SCSI subsystem initialized
[    0.203752] usbcore: registered new interface driver usbfs
[    0.203815] usbcore: registered new interface driver hub
[    0.203875] usbcore: registered new device driver usb
[    0.204552] omap_i2c 44e0b000.i2c: could not find pctldev for node /ocp/l4_wkup@44c00000/scm@210000/pinmux@800/pinmux_i2c0_pins, deferring probe
[    0.204602] omap_i2c 4819c000.i2c: could not find pctldev for node /ocp/l4_wkup@44c00000/scm@210000/pinmux@800/pinmux_i2c2_pins, deferring probe
[    0.205186] pps_core: LinuxPPS API ver. 1 registered
[    0.205195] pps_core: Software ver. 5.3.6 - Copyright 2005-2007 Rodolfo Giometti <giometti@linux.it>
[    0.205219] PTP clock support registered
[    0.205372] EDAC MC: Ver: 3.0.0
[    0.208071] clocksource: Switched to clocksource timer1
[    0.217934] NET: Registered protocol family 2
[    0.218657] TCP established hash table entries: 4096 (order: 2, 16384 bytes)
[    0.218706] TCP bind hash table entries: 4096 (order: 3, 32768 bytes)
[    0.218766] TCP: Hash tables configured (established 4096 bind 4096)
[    0.218827] UDP hash table entries: 256 (order: 1, 8192 bytes)
[    0.218846] UDP-Lite hash table entries: 256 (order: 1, 8192 bytes)
[    0.218982] NET: Registered protocol family 1
[    0.219455] RPC: Registered named UNIX socket transport module.
[    0.219469] RPC: Registered udp transport module.
[    0.219475] RPC: Registered tcp transport module.
[    0.219482] RPC: Registered tcp NFSv4.1 backchannel transport module.
[    0.220409] hw perfevents: enabled with armv7_cortex_a8 PMU driver, 5 counters available
[    0.222995] workingset: timestamp_bits=30 max_order=17 bucket_order=0
[    0.233303] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[    0.234342] NFS: Registering the id_resolver key type
[    0.234383] Key type id_resolver registered
[    0.234390] Key type id_legacy registered
[    0.234435] ntfs: driver 2.1.32 [Flags: R/O].
[    0.236102] Block layer SCSI generic (bsg) driver version 0.4 loaded (major 248)
[    0.236118] io scheduler noop registered
[    0.236125] io scheduler deadline registered
[    0.236306] io scheduler cfq registered (default)
[    0.239613] libphy: mdio_driver_register: phy-bcm-ns2-pci
[    0.240643] pinctrl-single 44e10800.pinmux: 142 pins at pa f9e10800 size 568
[    0.310602] Serial: 8250/16550 driver, 4 ports, IRQ sharing disabled
[    0.313574] SuperH (H)SCI(F) driver initialized
[    0.314333] msm_serial: driver initialized
[    0.314634] omap_uart 44e09000.serial: no wakeirq for uart0
[    0.314794] 44e09000.serial: ttyO0 at MMIO 0x44e09000 (irq = 158, base_baud = 3000000) is a OMAP UART0
[    0.996898] console [ttyO0] enabled
[    1.001029] STMicroelectronics ASC driver initialized
[    1.008372] omap_rng 48310000.rng: OMAP Random Number Generator ver. 20
[    1.016526] [drm] Initialized
[    1.034536] brd: module loaded
[    1.044042] loop: module loaded
[    1.054404] libphy: Fixed MDIO Bus: probed
[    1.059973] CAN device driver interface
[    1.065592] e1000e: Intel(R) PRO/1000 Network Driver - 3.2.6-k
[    1.071746] e1000e: Copyright(c) 1999 - 2015 Intel Corporation.
[    1.078036] igb: Intel(R) Gigabit Ethernet Network Driver - version 5.4.0-k
[    1.085348] igb: Copyright (c) 2007-2014 Intel Corporation.
[    1.153152] davinci_mdio 4a101000.mdio: davinci mdio revision 1.6
[    1.159570] davinci_mdio 4a101000.mdio: detected phy mask fffffffe
[    1.167038] libphy: 4a101000.mdio: probed
[    1.171323] davinci_mdio 4a101000.mdio: phy[0]: device 4a101000.mdio:00, driver SMSC LAN8710/LAN8720
[    1.182874] cpsw 4a100000.ethernet: Detected MACID = 38:d2:69:75:db:dc
[    1.191712] pegasus: v0.9.3 (2013/04/25), Pegasus/Pegasus II USB Ethernet driver
[    1.199648] usbcore: registered new interface driver pegasus
[    1.205660] usbcore: registered new interface driver asix
[    1.211366] usbcore: registered new interface driver ax88179_178a
[    1.217792] usbcore: registered new interface driver cdc_ether
[    1.223960] usbcore: registered new interface driver smsc75xx
[    1.230038] usbcore: registered new interface driver smsc95xx
[    1.236104] usbcore: registered new interface driver net1080
[    1.242075] usbcore: registered new interface driver cdc_subset
[    1.248319] usbcore: registered new interface driver zaurus
[    1.254223] usbcore: registered new interface driver cdc_ncm
[    1.261775] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
[    1.268676] ehci-pci: EHCI PCI platform driver
[    1.273400] ehci-platform: EHCI generic platform driver
[    1.279081] ehci-orion: EHCI orion driver
[    1.283436] SPEAr-ehci: EHCI SPEAr driver
[    1.287737] ehci-st: EHCI STMicroelectronics driver
[    1.292990] ehci-exynos: EHCI EXYNOS driver
[    1.297519] ehci-atmel: EHCI Atmel driver
[    1.301842] tegra-ehci: Tegra EHCI driver
[    1.306187] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
[    1.312704] ohci-pci: OHCI PCI platform driver
[    1.317431] ohci-platform: OHCI generic platform driver
[    1.323097] ohci-omap3: OHCI OMAP3 driver
[    1.327410] SPEAr-ohci: OHCI SPEAr driver
[    1.331743] ohci-st: OHCI STMicroelectronics driver
[    1.336980] ohci-atmel: OHCI Atmel driver
[    1.341772] usbcore: registered new interface driver usb-storage
[    1.349615] mousedev: PS/2 mouse device common for all mice
[    1.358266] i2c /dev entries driver
[    1.372021] sdhci: Secure Digital Host Controller Interface driver
[    1.378596] sdhci: Copyright(c) Pierre Ossman
[    1.384201] omap_hsmmc 48060000.mmc: Got CD GPIO
[    1.469099] Synopsys Designware Multimedia Card Interface Driver
[    1.476363] sdhci-pltfm: SDHCI platform and OF driver helper
[    1.485056] ledtrig-cpu: registered to indicate activity on CPUs
[    1.491914] usbcore: registered new interface driver usbhid
[    1.497793] usbhid: USB HID core driver
[    1.504918] NET: Registered protocol family 10
[    1.510957] sit: IPv6, IPv4 and MPLS over IPv4 tunneling driver
[    1.517953] NET: Registered protocol family 17
[    1.522660] can: controller area network core (rev 20120528 abi 9)
[    1.529379] NET: Registered protocol family 29
[    1.534062] can: raw protocol (rev 20120528)
[    1.538539] can: broadcast manager protocol (rev 20161123 t)
[    1.544473] can: netlink gateway (rev 20130117) max_hops=1
[    1.550216] random: fast init done
[    1.554375] Key type dns_resolver registered
[    1.559110] omap_voltage_late_init: Voltage driver support not added
[    1.565942] ThumbEE CPU extension supported.
[    1.570445] Registering SWP/SWPB emulation handler
[    1.608169] tps65217 0-0024: TPS65217 ID 0xe version 1.2
[    1.614534] at24 0-0050: 32768 byte 24c256 EEPROM, writable, 1 bytes/write
[    1.622079] omap_i2c 44e0b000.i2c: bus 0 rev0.11 at 400 kHz
[    1.645631] mmc1: new high speed MMC card at address 0001
[    1.652087] mmcblk1: mmc1:0001 M62704 3.56 GiB 
[    1.657683] mmcblk1boot0: mmc1:0001 M62704 partition 1 2.00 MiB
[    1.664268] mmcblk1boot1: mmc1:0001 M62704 partition 2 2.00 MiB
[    1.671889]  mmcblk1: p1
[    1.729693] omap_i2c 4819c000.i2c: bus 2 rev0.11 at 100 kHz
[    1.737573] cpufreq: cpufreq_online: CPU0: Running at unlisted freq: 1000000 KHz
[    1.745438] cpu cpu0: dev_pm_opp_set_rate: failed to find current OPP for freq 1000000000 (-34)
[    1.756320] cpufreq: cpufreq_online: CPU0: Unlisted initial frequency changed to: 720000 KHz
[    1.766290] hctosys: unable to open rtc device (rtc0)
[    1.786010] net eth0: initializing cpsw version 1.12 (0)
[    1.868699] SMSC LAN8710/LAN8720 4a101000.mdio:00: attached PHY driver [SMSC LAN8710/LAN8720] (mii_bus:phy_addr=4a101000.mdio:00, irq=-1)
[    1.887634] IPv6: ADDRCONF(NETDEV_UP): eth0: link is not ready
[    3.963897] cpsw 4a100000.ethernet eth0: Link is Up - 100Mbps/Full - flow control rx/tx
[    3.972587] IPv6: ADDRCONF(NETDEV_CHANGE): eth0: link becomes ready
[    3.988159] IP-Config: Guessing netmask 255.255.255.0
[    3.993555] IP-Config: Complete:
[    3.996986]      device=eth0, hwaddr=38:d2:69:75:db:dc, ipaddr=192.168.8.2, mask=255.255.255.0, gw=255.255.255.255
[    4.008230]      host=192.168.8.2, domain=, nis-domain=(none)
[    4.014369]      bootserver=255.255.255.255, rootserver=192.168.8.1, rootpath=
[    4.157615] VFS: Mounted root (nfs filesystem) on device 0:12.
[    4.164931] devtmpfs: mounted
[    4.176713] Freeing unused kernel memory: 2048K
Starting logging: OK
Initializing random number generator... done.
Starting network...
ip: RTNETLINK answers: File exists
Starting dropbear sshd: OK

Welcome to Buildroot

buildroot login: root

beagle$
