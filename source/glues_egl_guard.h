//
// Created by Hiroshi Matoba on 14.12.25.
//

#pragma once

#ifndef TARGET_EGL
#error "glues GLU headers are EGL-only. Use the system GLU headers for non-EGL builds."
#endif

#include "OpenGlMock.h"

#ifndef GLAPI
  #define GLAPI GL_API
#endif

#ifndef APIENTRY
  #define APIENTRY
#endif

#ifndef APIENTRYP
  #define APIENTRYP APIENTRY *
#endif