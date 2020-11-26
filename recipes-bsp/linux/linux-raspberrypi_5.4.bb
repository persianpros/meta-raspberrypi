require linux-raspberrypi.inc

LINUX_VERSION = "${KERNELVERSION}"

SRCREV = "9797f1a4938c20139b00a25de93cc99efb5c291b"

S_rpi = "${WORKDIR}/linux-${SRCREV}"

SRC_URI[md5sum] = "01ee6701dfde85b45f9af160153ceda0"
SRC_URI[sha256sum] = "ad6c146a5ea6e4948513f2cbead845d63e01186cb6488cd2707ed8ec35ef72e3"

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
