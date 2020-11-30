# if using bcm driver enable dispmanx

PACKAGECONFIG_append_rpi = " dispmanx"

DEPENDS_append_rpi = " userland"

PACKAGECONFIG_GL_rpi = "egl gles2"

OPENVISIONGSTEAMERBASE = "normal"

OPENVISIONGSTEAMERBASE_rpi = "rpi"

require openvision-gstreamerbase-${OPENVISIONGSTEAMERBASE}.inc
