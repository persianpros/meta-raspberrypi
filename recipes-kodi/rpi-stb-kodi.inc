require recipes-mediacenter/kodi/stb-kodi_19.bb

PROVIDES += "virtual/kodi"
RPROVIDES_${PN} += "virtual/kodi"
PROVIDES += "kodi"
RPROVIDES_${PN} += "kodi"

EXTRA_OECMAKE += " \
    -DCORE_PLATFORM_NAME=x11 \
    -DAPP_RENDER_SYSTEM=gl \
"
