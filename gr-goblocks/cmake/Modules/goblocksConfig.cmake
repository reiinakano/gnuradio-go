INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_GOBLOCKS goblocks)

FIND_PATH(
    GOBLOCKS_INCLUDE_DIRS
    NAMES goblocks/api.h
    HINTS $ENV{GOBLOCKS_DIR}/include
        ${PC_GOBLOCKS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GOBLOCKS_LIBRARIES
    NAMES gnuradio-goblocks
    HINTS $ENV{GOBLOCKS_DIR}/lib
        ${PC_GOBLOCKS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GOBLOCKS DEFAULT_MSG GOBLOCKS_LIBRARIES GOBLOCKS_INCLUDE_DIRS)
MARK_AS_ADVANCED(GOBLOCKS_LIBRARIES GOBLOCKS_INCLUDE_DIRS)

