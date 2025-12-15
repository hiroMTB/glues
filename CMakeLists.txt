cmake_minimum_required(VERSION 3.16)

project(glues LANGUAGES C CXX)

# Build a static library by default (recommended for linking into many plugins)
option(GLUES_BUILD_SHARED "Build glues as a shared library" OFF)

# Compile definitions used by glues
add_compile_definitions(LIBRARYBUILD)

# For our ANGLE/EGL build we do NOT want SDL's GL header path assumptions.
add_compile_definitions(__USE_SDL_GLES__=1)

# Includes
add_library(glues_obj OBJECT)

target_include_directories(glues_obj
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${CMAKE_CURRENT_SOURCE_DIR}/source/libnurbs/internals
    ${CMAKE_CURRENT_SOURCE_DIR}/source/libnurbs/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/source/libnurbs/nurbtess
)

#
# Source files
file(GLOB SRC_C
  ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
)
file(GLOB SRC_CC
  ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc
)

set(SRC ${SRC_C} ${SRC_CC})
file(GLOB TESS_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/source/libtess/*.c
)
file(GLOB_RECURSE NURBS_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/source/libnurbs/*.cc
)

target_sources(glues_obj PRIVATE ${SRC} ${TESS_SRC} ${NURBS_SRC})

# Reasonable language defaults
set_target_properties(glues_obj PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)


add_library(glues STATIC $<TARGET_OBJECTS:glues_obj>)
add_library(glues::glues ALIAS glues)

# Public include dirs/defs propagate to consumers

target_link_libraries(glues PUBLIC glues_obj)

# ----------------------------
# Install into glues/out/<Config>
# ----------------------------
include(GNUInstallDirs)

# If the user didn't set an install prefix, default to <source>/out
# and put outputs under out/lib/<Config>/...
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/out" CACHE PATH "" FORCE)
endif()

set(_GLUES_CFG "$<IF:$<BOOL:$<CONFIG>>,$<CONFIG>,${CMAKE_BUILD_TYPE}>")

install(TARGETS glues
  ARCHIVE DESTINATION "lib/${_GLUES_CFG}"
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/source/
  DESTINATION "include"
  FILES_MATCHING
    PATTERN "*.h"
    PATTERN "../include/*.h"
    PATTERN "libnurbs" EXCLUDE
    PATTERN "libnurbs/*" EXCLUDE
    PATTERN "libtess" EXCLUDE
    PATTERN "libtess/*" EXCLUDE
)


# ----------------------------
# Auto-install after build
# ----------------------------
option(GLUES_AUTO_INSTALL "Run cmake --install automatically after building glues" ON)

if(GLUES_AUTO_INSTALL)
  add_custom_command(TARGET glues POST_BUILD
    COMMAND "${CMAKE_COMMAND}" --install "${CMAKE_BINARY_DIR}" --prefix "${CMAKE_INSTALL_PREFIX}" --config "$<CONFIG>"
    COMMENT "Auto-installing glues into ${CMAKE_INSTALL_PREFIX}"
    VERBATIM
  )
endif()
