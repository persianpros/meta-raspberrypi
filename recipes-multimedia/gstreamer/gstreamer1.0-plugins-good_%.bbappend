# Just a comment line to avoid PAK archive (application/x-pak)

PACKAGECONFIG_append_rpi = " rpicamsrc v4l2 v4l2-probe"

OPENVISIONGSTEAMERGOOD = "normal"

OPENVISIONGSTEAMERGOOD_rpi = "rpi"

require openvision-gstreamergood-${OPENVISIONGSTEAMERGOOD}.inc
