#!/bin/sh

case "$1" in
	start)
		echo -n "rpi-vtunerc"
		mkdir /dev/misc
		ln -s /dev/vtunerc0 /dev/misc/vtuner0
		;;
	*)
		;;
esac

exit 0
