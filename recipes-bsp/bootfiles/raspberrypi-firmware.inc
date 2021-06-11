RPIFW_DATE = "20210525"

SRCREV = "afdb60cc1a8a4aa0c6af68f02b6c1efe6256ba5d"

RPIFW_SRC_URI = "https://github.com/raspberrypi/firmware/archive/${SRCREV}.tar.gz"

SRC_URI[md5sum] = "3a565bfb9fbcf87f99207cd66e7d20fe"
SRC_URI[sha256sum] = "9cf22b741a108a4715e0a46d92f8c362eb2335a929b1807e85047235befdd85f"

RPIFW_S = "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"

PV = "${RPIFW_DATE}+git${SRCREV}"
