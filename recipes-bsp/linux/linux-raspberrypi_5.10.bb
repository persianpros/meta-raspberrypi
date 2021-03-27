require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "3e55254ce6f792372bbfe90f77006e75467c1dfe"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "78733033b0a519a202f996f5a6d95673"
SRC_URI[sha256sum] = "9cbb5c3bed564fb33574fb6ecfe829b4a1ccc0e281d7c53a4a806f8b9e8c66ea"
