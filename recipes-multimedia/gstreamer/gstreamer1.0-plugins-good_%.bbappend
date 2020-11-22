FILESEXTRAPATHS_prepend := "${THISDIR}/gstreamer1.0-plugins-good:"

SRC_URI_append_rpi = " file://0001-Link-rpicamsrc-with-vchostif.patch"

PACKAGECONFIG_append_rpi = " rpicamsrc v4l2 v4l2-probe"

OPENVISIONGSTEAMERGOOD = "normal"

OPENVISIONGSTEAMERGOOD_rpi = "rpi"

require openvision-gstreamergood-${OPENVISIONGSTEAMERGOOD}.inc
