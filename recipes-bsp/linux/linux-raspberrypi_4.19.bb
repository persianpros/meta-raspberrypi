require linux-raspberrypi.inc

LINUX_VERSION = "4.19.108"

SRCREV = "2fab54c74bf956951e61c6d4fe473995e8d07010"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "c407b01bc78f37b1eca99ebeaedf2d42"
SRC_URI[sha256sum] = "bc92c569bbdb53744dee458827c64119a16ee5267cdcba851e1832c3a174571c"

SRC_URI += "file://0001-perf-Make-perf-able-to-build-with-latest-libbfd.patch"
