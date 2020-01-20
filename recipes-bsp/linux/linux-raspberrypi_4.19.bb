require linux-raspberrypi.inc

LINUX_VERSION = "4.19.95"

SRCREV = "0d72d83ec92acda1e8cbad0d4213a5ec2b3f2e1b"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "43990b8e4bad1409bcc0ba80d542e8e7"
SRC_URI[sha256sum] = "2e408b5638250a5ba6004b175f46d25f7858e4d38889a1292660a44354971d0a"
