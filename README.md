RaspberryPi BSP layer for:
```
raspberrypi0 - kernel 4.9.59 (RPi0)
raspberrypi - kernel 4.9.59 (RPi1)
raspberrypi2 - kernel 4.9.59 (RPi2)
raspberrypi3 - kernel 4.9.59 (RPi3)
```
How does it work? Simply with PLi's OE!

Use https://github.com/OpenPLi/openpli-oe-core (develop branch) with Ubuntu 16.04.3 LTS as your base, Open a terminal inside "openpli-oe-core" folder and enter:
```
wget https://raw.githubusercontent.com/PLi-metas/PLiPi/master/PLiPi-pyro.sh
sh PLiPi-pyro.sh
```
You must run PLiPi-pyro.sh only once!

Edit PLi's "Makefile" and add "meta-raspberrypi" after "meta-lcoal".

If you're going to build on a distro which features glibc 2.26 or newer (such as Fedora 27 or Arch),
then please add the following line to your meta-openpli/conf/distro/openpli.conf file:
```
LOCALE_GENERATION_WITH_CROSS-LOCALEDEF_forcevariable = "0"
```
See: https://bugzilla.yoctoproject.org/show_bug.cgi?id=12265

For latest updates you need to open a terminal inside "meta-raspberrypi" folder and enter:
```
git pull origin pyro
```
each time you do "make update" for the OE.

Experimental machines:
```
raspberrypi3-64 - kernel 4.9.59 (RPi3-64Bit)
```
We're independent so if you think you can help you're welcome to send us merge requests.
