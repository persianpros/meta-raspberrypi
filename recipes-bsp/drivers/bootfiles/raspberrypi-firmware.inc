RPIFW_DATE ?= "20191122"
SRCREV ?= "204245361ea7b903494de666c4028dd7f21ee56e"
RPIFW_SRC_URI ?= "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[md5sum] = "9a66d949db6f11ae09f1f1cb57db91e9"
SRC_URI[sha256sum] = "43f349627d1adb65099585111fbbdbe7ccf1dff7daba3943034657dd26f33fd6"

PV = "${RPIFW_DATE}+git${SRCREV}"
