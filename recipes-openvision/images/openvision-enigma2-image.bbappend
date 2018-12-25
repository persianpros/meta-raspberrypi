IMAGE_INSTALL_append += "\
	${@bb.utils.contains('MACHINE_FEATURES', 'rpi-pli', 'lirc lirc-plugins', '', d)} \
	"
