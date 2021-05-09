# Avoid pack file
PACKAGECONFIG_GLESV2_rpi = " ${@bb.utils.contains('DISTRO_FEATURES', 'x11', '', 'glesv2', d)}"

PACKAGECONFIG_append_rpi = " egl ${PACKAGECONFIG_GLESV2}"
