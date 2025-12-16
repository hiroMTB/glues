//
// gldef.h
// Created by Hiroshi Matoba on 16.12.25.
// Minimal OpenGL / OpenGL ES function prototypes required by glues.
// Some functions are desktop-GL-only and are provided via compatibility shims.
// Wrote this because ...
// - angle_gl.h doesn't include Desktop GL functions, hence glues doesn't compile.
// - With OpenGl/gl.h, glues does compile, but it causes return type mismatch error when we include angle_gl.h
//

#pragma once

// glues is macOS-only. Fail fast if this header is pulled into other platforms.
#if !defined(__APPLE__)
#  error "glues is macOS-only (Apple platform required)."
#endif

#ifndef GL_API
#define GL_API
#endif

#ifndef GL_APIENTRY
#define GL_APIENTRY
#endif

#include <stdint.h>

typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;
typedef int32_t                khronos_int32_t;
typedef          float         khronos_float_t;

typedef khronos_int8_t GLbyte;
typedef khronos_float_t GLclampf;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_float_t GLfloat;
typedef khronos_int32_t GLfixed;
typedef unsigned int GLenum;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef khronos_uint8_t GLubyte;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef void GLvoid;

#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_LUMINANCE                      0x1909
#define GL_LUMINANCE_ALPHA                0x190A
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_FLOAT                          0x1406
#define GL_NORMAL_ARRAY                   0x8075
#define GL_VERTEX_ARRAY                   0x8074
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_CLIENT_PIXEL_STORE_BIT         0x00000001
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_TEXTURE_COORD_ARRAY            0x8078
#define GL_COLOR_ARRAY                    0x8076

#ifdef __cplusplus
extern "C" {
#endif

GL_API void GL_APIENTRY glBindTexture (GLenum target, GLuint texture);
GL_API void GL_APIENTRY glClear (GLbitfield mask);
GL_API void GL_APIENTRY glClearColorx (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
GL_API void GL_APIENTRY glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GL_API void GL_APIENTRY glColorPointer (GLint size, GLenum type, GLsizei stride, const void *pointer);
GL_API void GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GL_API void GL_APIENTRY glDisable (GLenum cap);
GL_API void GL_APIENTRY glDisableClientState (GLenum array);
GL_API void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GL_API void GL_APIENTRY glEnable (GLenum cap);
GL_API void GL_APIENTRY glEnableClientState (GLenum array);
GL_API void GL_APIENTRY glFinish (void);
GL_API void GL_APIENTRY glFlush (void);
GL_API void GL_APIENTRY glFrustumf (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GL_API void GL_APIENTRY glGenTextures (GLsizei n, GLuint *textures);
GL_API GLenum GL_APIENTRY glGetError (void);
GL_API void GL_APIENTRY glGetFloatv (GLenum pname, GLfloat *params);
GL_API void GL_APIENTRY glGetIntegerv (GLenum pname, GLint *params);
GL_API GLboolean GL_APIENTRY glIsEnabled (GLenum cap);
GL_API void GL_APIENTRY glLightfv (GLenum light, GLenum pname, const GLfloat *params);
GL_API void GL_APIENTRY glLoadIdentity (void);
GL_API void GL_APIENTRY glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
GL_API void GL_APIENTRY glMaterialfv (GLenum face, GLenum pname, const GLfloat *params);
GL_API void GL_APIENTRY glMatrixMode (GLenum mode);
GL_API void GL_APIENTRY glMultMatrixf (const GLfloat *m);
GL_API void GL_APIENTRY glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz);
GL_API void GL_APIENTRY glNormalPointer (GLenum type, GLsizei stride, const void *pointer);
GL_API void GL_APIENTRY glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GL_API void GL_APIENTRY glOrthof (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
GL_API void GL_APIENTRY glPixelStorei (GLenum pname, GLint param);
GL_API void GL_APIENTRY glPointSize (GLfloat size);
GL_API void GL_APIENTRY glPopClientAttrib (void);
GL_API void GL_APIENTRY glPopMatrix (void);
GL_API void GL_APIENTRY glPushClientAttrib (GLbitfield mask);
GL_API void GL_APIENTRY glPushMatrix (void);
GL_API GLbitfield GL_APIENTRY glQueryMatrixxOES (GLfixed *mantissa, GLint *exponent);
GL_API void GL_APIENTRY glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GL_API void GL_APIENTRY glScalef (GLfloat x, GLfloat y, GLfloat z);
GL_API void GL_APIENTRY glShadeModel (GLenum mode);
GL_API void GL_APIENTRY glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const void *pointer);
GL_API void GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GL_API void GL_APIENTRY glTexParameterx (GLenum target, GLenum pname, GLfixed param);
GL_API void GL_APIENTRY glTranslatef (GLfloat x, GLfloat y, GLfloat z);
GL_API void GL_APIENTRY glVertexPointer (GLint size, GLenum type, GLsizei stride, const void *pointer);
GL_API void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);

#ifdef __cplusplus
}
#endif
