RPIFW_DATE = "20201119"

SRCREV = "bff705fffe59ad3eea33999beb29c3f26408de40"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "6b4b5d54f6adf7615b900a81e2d790bf"
SRC_URI[sha256sum] = "e60363ce94c4a78e4a2d41c982a887ac9d31c4997fe793c37ab5690beed3078d"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
