require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "900790847a10954e7dcaeb4fe86d37ba0d7e73a2"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "07072d35903171dbd14cc56abb84d805"
SRC_URI[sha256sum] = "5e7956b503d6deaf270ad78aff83f70dd0fc4366ccc4fe6c4fac3926fe747e9a"
