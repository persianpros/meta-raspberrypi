require linux-raspberrypi.inc

LINUX_VERSION = "4.19.97"

SRCREV = "63739afcdd3662e9f9e1f04c81b63b743a12f9d1"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "abb7acb0bc7077ef8ccba1107a9371ca"
SRC_URI[sha256sum] = "0d6c6afc1216e00c195d3943d1b87f6b2c890f3bf0fa076a4b6accac9f46654e"
