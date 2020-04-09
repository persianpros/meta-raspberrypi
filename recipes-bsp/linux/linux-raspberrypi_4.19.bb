require linux-raspberrypi.inc

LINUX_VERSION = "4.19.114"

SRCREV = "9517c36b92e6ad6802326c3ecbf6eed28c2f3fba"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "212530a26eaa8c1e267220ef99fc9616"
SRC_URI[sha256sum] = "efd3323ecc30bda503bd4ded66d5af209c67e9022b7f76a5f2a533d3f0f6477f"

SRC_URI += "file://0001-perf-Make-perf-able-to-build-with-latest-libbfd.patch"
