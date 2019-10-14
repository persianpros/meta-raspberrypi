require linux-raspberrypi.inc

LINUX_VERSION = "4.19.79"

SRCREV = "047589b6dcd5dfd9673a995c5d36ec4073e578b5"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "7dd4de606a8cfcb1dd8c0aab115472f9"
SRC_URI[sha256sum] = "f617730cd3a3ca35351259cc58105d95a4d106b8a2971386c81dab073c0fbd15"
