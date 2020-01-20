EXTRA_OECONF_append_rpi += " CPPFLAGS='-I${STAGING_INCDIR}/interface/vcos/pthreads \
                                   -I${STAGING_INCDIR}/interface/vmcs_host/linux'"

# if using bcm driver enable dispmanx

PACKAGECONFIG_append_rpi += " dispmanx"

PACKAGECONFIG_GL_rpi = "egl gles2"

PACKAGECONFIG_append_rpi[dispmanx] += "--enable-dispmanx,--disable-dispmanx,userland"
