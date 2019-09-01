IMAGE_INSTALL_append_rpi += "${@bb.utils.contains('MACHINE_FEATURES', 'rpi-vision', 'lirc lirc-plugins', '', d)}"
