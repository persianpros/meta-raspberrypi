IMAGE_INSTALL_append = " \
	${@bb.utils.contains('MACHINE_FEATURES', 'plipi', 'lirc', '', d)} \
	"
