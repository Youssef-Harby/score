# set(CMAKE_C_COMPILER /usr/bin/clang)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(ISCORE_COTIRE_DISABLE_UNITY True)
set(ISCORE_SANITIZE True)
#set(ISCORE_DISABLE_ADDONS True)
include(travis/static-debug)
include(all-plugins)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(ISCORE_COTIRE False)
endif()
