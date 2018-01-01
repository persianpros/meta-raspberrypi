RaspberryPi BSP layer for:
```
raspberrypi0 - kernel 4.9.50 (RPi0)
raspberrypi - kernel 4.9.50 (RPi1)
raspberrypi2 - kernel 4.9.50 (RPi2)
raspberrypi3 - kernel 4.9.50 (RPi3)
```
How does it work? Simply with PLi's OE!

Use https://github.com/OpenPLi/openpli-oe-core (pyro branch) with Ubuntu 16.04.3 LTS as your base, Open a terminal inside "openpli-oe-core" folder and enter:
```
wget https://raw.githubusercontent.com/RaspberryPLi/PLiPi/master/PLiPi-pyro.sh
sh PLiPi-pyro.sh
```
You must run PLiPi-pyro.sh only once!

Edit PLi's "Makefile" and add "meta-raspberrypi" after "meta-lcoal".

For latest updates you need to open a terminal inside "meta-raspberrypi" folder and enter:
```
git pull origin pyro
```
each time you do "make update" for the OE.

Experimental machines:
```
raspberrypi3-64 - kernel 4.9.50 (RPi3-64Bit)
```
We're independent so if you think you can help you're welcome to send us merge requests.
