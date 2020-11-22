# Just a comment line to avoid PAK archive (application/x-pak)

PACKAGECONFIG[rpicamsrc] = "-Drpicamsrc=enabled -Drpi-header-dir=${STAGING_INCDIR} -Drpi-lib-dir=${STAGING_LIBDIR},-Drpicamsrc=disabled,userland"
PACKAGECONFIG[v4l2] = "-Dv4l2=enabled,-Dv4l2=disabled,"
PACKAGECONFIG[v4l2-probe] = "-Dv4l2-probe=true,-Dv4l2=false,"
PACKAGECONFIG[v4l2-libv4l2] = "-Dv4l2-libv4l2=enabled,-Dv4l2-libv4l2=disabled,"
PACKAGECONFIG[v4l2-gudev] = "-Dv4l2-gudev=enabled,-Dv4l2-gudev=disabled,"
