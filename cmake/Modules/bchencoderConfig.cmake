INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_BCHENCODER bchencoder)

FIND_PATH(
    BCHENCODER_INCLUDE_DIRS
    NAMES bchencoder/api.h
    HINTS $ENV{BCHENCODER_DIR}/include
        ${PC_BCHENCODER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BCHENCODER_LIBRARIES
    NAMES gnuradio-bchencoder
    HINTS $ENV{BCHENCODER_DIR}/lib
        ${PC_BCHENCODER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/bchencoderTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BCHENCODER DEFAULT_MSG BCHENCODER_LIBRARIES BCHENCODER_INCLUDE_DIRS)
MARK_AS_ADVANCED(BCHENCODER_LIBRARIES BCHENCODER_INCLUDE_DIRS)
