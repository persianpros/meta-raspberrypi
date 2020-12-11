require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "a80c030ec58faae839cab30a483eacb86ae7bc7e"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "608bbc0f55903a37ed40d99845579961"
SRC_URI[sha256sum] = "5eccd155cbe8c3a75291f13d0b798d593b7157b739cd3e9c1da56820b71394eb"

SRC_URI += "file://0001-Revert-selftests-bpf-Skip-perf-hw-events-test-if-the.patch \
	file://0002-Revert-selftests-bpf-Fix-perf_buffer-test-on-systems.patch \
	file://0001-Add-Silicon-Labs-SI2183.patch \
	file://0002-Add-Airoha-Technology-AV201x.patch \
	file://0003-Add-TBS-5520SE.patch \
	file://0001-Add-linux-version.h-and-update-uapi-frontends.h.patch \
	file://0002-Update-dvb_frontend.h.patch \
	file://0001-Update-dvb-usb.h-and-uapi-frontend.h.patch \
	file://0001-Update-dvb-usb.h.patch \
	file://0001-Register-and-unregister-second-frontend-for-dvb-s.patch \
	"
