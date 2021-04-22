RPIFW_DATE = "20210421"

SRCREV = "2ac4de4eaac5c1d1b25acec4a5e0a9fdb16f0c91"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "43c92418c2634d4c0c8ce3da696dcad5"
SRC_URI[sha256sum] = "c687aa1b5127a8dc0773e8aefb1f009f24bf71ccb4c9e8b40a1d46cbbb7bee0c"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
