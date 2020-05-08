require linux-raspberrypi.inc

LINUX_VERSION = "4.19.118"

SRCREV = "fe2c7bf4cad4641dfb6f12712755515ab15815ca"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "5ff7f122b14e9e36c3299b2ee45ee53b"
SRC_URI[sha256sum] = "ca458e01428927cc12e13e4ef0de219902feeba5fd7f6bcb5056ce33c4688e90"

SRC_URI += "file://0001-perf-Make-perf-able-to-build-with-latest-libbfd.patch"

# We need to change the PR when we change defconfig but not needed when we upgrade the kernel to a higher version.
MACHINE_KERNEL_PR_append = "-dvb"
