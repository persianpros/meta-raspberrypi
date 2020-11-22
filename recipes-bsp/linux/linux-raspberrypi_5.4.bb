require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "b8681a08ba16b15cc9f010bef2a24ffac0b054d1"
SRCREV_meta = "d626f9108d590d41e82b97cbffc380aa699e86e1"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "d10f8eb0ba6423afe5e4c2c1f59d82d3"
SRC_URI[sha256sum] = "a01cb69aedec9ac5a6d19a0e7c6149d6bdd3085e4fa7b131b4ecf9e2496e67dd"

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
