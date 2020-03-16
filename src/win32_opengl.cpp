#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include "types.h"

global_variable s64 GlobalPerfCountFrequency;
global_variable bool GlobalRunning;

typedef char GLchar;
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;

typedef void WINAPI gl_tex_image_2d_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void WINAPI gl_bind_framebuffer(GLenum target, GLuint framebuffer);
typedef void WINAPI gl_gen_framebuffers(GLsizei n, GLuint *framebuffers);
typedef void WINAPI gl_framebuffer_texture_2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef GLenum WINAPI gl_check_framebuffer_status(GLenum target);
typedef void WINAPI gl_bind_buffer(GLenum target, GLuint buffer);
typedef void WINAPI gl_blit_framebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void WINAPI gl_buffer_data(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
typedef void WINAPI gl_attach_shader(GLuint program, GLuint shader);
typedef void WINAPI gl_compile_shader(GLuint shader);
typedef GLuint WINAPI gl_create_program(void);
typedef GLuint WINAPI gl_create_shader(GLenum type);
typedef void WINAPI gl_enable_vertex_attrib_array(GLuint index);
typedef GLuint WINAPI gl_gen_buffers(GLsizei n, GLuint * buffers);
typedef void WINAPI gl_link_program(GLuint program);
typedef void WINAPI gl_shader_source(GLuint shader, GLsizei count, GLchar **string, GLint *length);
typedef void WINAPI gl_use_program(GLuint program);
typedef void WINAPI gl_get_program_info_log(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void WINAPI gl_get_shader_info_log(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void WINAPI gl_validate_program(GLuint program);
typedef void WINAPI gl_get_program_iv(GLuint program, GLenum pname, GLint *params);
typedef GLint WINAPI gl_get_uniform_location (GLuint program, const GLchar *name);
typedef void WINAPI gl_uniform_4fv(GLint location, GLsizei count, const GLfloat *value);
typedef void WINAPI gl_uniform_matrix_4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void WINAPI gl_uniform_1i(GLint location, GLint v0);
typedef void WINAPI gl_vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);

global_variable gl_tex_image_2d_multisample *glTexImage2DMultisample;
global_variable gl_bind_framebuffer *glBindFramebuffer;
global_variable gl_gen_framebuffers *glGenFramebuffers;
global_variable gl_framebuffer_texture_2D *glFramebufferTexture2D;
global_variable gl_check_framebuffer_status *glCheckFramebufferStatus;
global_variable gl_bind_buffer *glBindBuffer;
global_variable gl_blit_framebuffer *glBlitFramebuffer;
global_variable gl_buffer_data *glBufferData;
global_variable gl_attach_shader *glAttachShader;
global_variable gl_compile_shader *glCompileShader;
global_variable gl_create_program *glCreateProgram;
global_variable gl_create_shader *glCreateShader;
global_variable gl_enable_vertex_attrib_array *glEnableVertexAttribArray;
global_variable gl_gen_buffers *glGenBuffers;
global_variable gl_link_program *glLinkProgram;
global_variable gl_shader_source *glShaderSource;

global_variable gl_use_program *glUseProgram;
global_variable gl_get_program_info_log *glGetProgramInfoLog;
global_variable gl_get_shader_info_log *glGetShaderInfoLog;
global_variable gl_validate_program *glValidateProgram;
global_variable gl_get_program_iv *glGetProgramiv;
global_variable gl_get_uniform_location *glGetUniformLocation;
global_variable gl_uniform_4fv *glUniform4fv;
global_variable gl_uniform_matrix_4fv *glUniformMatrix4fv;
global_variable gl_uniform_1i *glUniform1i;
global_variable gl_vertex_attrib_pointer *glVertexAttribPointer;

typedef BOOL WINAPI wgl_swap_interval_ext(int interval);
global_variable wgl_swap_interval_ext *wglSwapIntervalEXT;

#include "opengl.h"

global_variable open_gl OpenGL;
#include "opengl.cpp"

struct win32_window_dimension
{
  int Width;
  int Height;
};

inline LARGE_INTEGER
Win32GetWallClock(void)
{
  LARGE_INTEGER Result;
  QueryPerformanceCounter(&Result);
  return(Result);
}

inline real32
Win32GetSecondsElapsed(LARGE_INTEGER Start, LARGE_INTEGER End)
{
  real32 Result = ((real32)(End.QuadPart - Start.QuadPart) /
                   (real32)GlobalPerfCountFrequency);
  return(Result);
}

internal void
OpenGLLoadFunctionPointers(opengl_info Info, b32 ModernContext)
{
  if(Info.GL_ARB_framebuffer_object)
  {
    glBindFramebuffer = (gl_bind_framebuffer *)wglGetProcAddress("glBindFramebuffer");
    glGenFramebuffers = (gl_gen_framebuffers *)wglGetProcAddress("glGenFramebuffers");
    glFramebufferTexture2D = (gl_framebuffer_texture_2D *)wglGetProcAddress("glFramebufferTexture2D");
    glCheckFramebufferStatus = (gl_check_framebuffer_status *)wglGetProcAddress("glCheckFramebufferStatus");
  }

  glTexImage2DMultisample = (gl_tex_image_2d_multisample *)wglGetProcAddress("glTexImage2DMultisample");
  glBindBuffer = (gl_bind_buffer *)wglGetProcAddress("glBindBuffer");
  glBlitFramebuffer = (gl_blit_framebuffer *)wglGetProcAddress("glBlitFramebuffer");
  glBufferData = (gl_buffer_data *)wglGetProcAddress("glBufferData");

  glAttachShader = (gl_attach_shader *)wglGetProcAddress("glAttachShader");
  glCompileShader = (gl_compile_shader *)wglGetProcAddress("glCompileShader");
  glCreateProgram = (gl_create_program *)wglGetProcAddress("glCreateProgram");
  glCreateShader = (gl_create_shader *)wglGetProcAddress("glCreateShader");
  glEnableVertexAttribArray = (gl_enable_vertex_attrib_array *)wglGetProcAddress("glEnableVertexAttribArray");
  glGenBuffers = (gl_gen_buffers *)wglGetProcAddress("glGenBuffers");
  glLinkProgram = (gl_link_program *)wglGetProcAddress("glLinkProgram");
  glShaderSource = (gl_shader_source *)wglGetProcAddress("glShaderSource");
  glUseProgram = (gl_use_program *)wglGetProcAddress("glUseProgram");
  glGetProgramInfoLog = (gl_get_program_info_log *)wglGetProcAddress("glGetProgramInfoLog");
  glGetShaderInfoLog = (gl_get_shader_info_log *)wglGetProcAddress("glGetShaderInfoLog");
  glValidateProgram = (gl_validate_program *)wglGetProcAddress("glValidateProgram");
  glGetProgramiv = (gl_get_program_iv *)wglGetProcAddress("glGetProgramiv");
  glGetUniformLocation = (gl_get_uniform_location *)wglGetProcAddress("glGetUniformLocation");
  glUniform4fv = (gl_uniform_4fv *)wglGetProcAddress("glUniform4fv");
  glUniformMatrix4fv = (gl_uniform_matrix_4fv *)wglGetProcAddress("glUniformMatrix4fv");
  glUniform1i = (gl_uniform_1i *)wglGetProcAddress("glUniform1i");
  glVertexAttribPointer = (gl_vertex_attrib_pointer *)wglGetProcAddress("glVertexAttribPointer");
  wglSwapIntervalEXT = (wgl_swap_interval_ext *)wglGetProcAddress("wglSwapIntervalEXT");
}

internal void
Win32InitOpenGL(HWND Window)
{
  HDC WindowDC = GetDC(Window);

  PIXELFORMATDESCRIPTOR DesiredPixelFormat = {};
  DesiredPixelFormat.nSize = sizeof(DesiredPixelFormat);
  DesiredPixelFormat.nVersion = 1;
  DesiredPixelFormat.iPixelType = PFD_TYPE_RGBA;
  DesiredPixelFormat.dwFlags = PFD_SUPPORT_OPENGL|PFD_DRAW_TO_WINDOW|PFD_DOUBLEBUFFER;
  DesiredPixelFormat.cColorBits = 32;
  DesiredPixelFormat.cAlphaBits = 8;
  DesiredPixelFormat.iLayerType = PFD_MAIN_PLANE;

  int SuggestedPixelFormatIndex = ChoosePixelFormat(WindowDC, &DesiredPixelFormat);
  PIXELFORMATDESCRIPTOR SuggestedPixelFormat;
  DescribePixelFormat(WindowDC, SuggestedPixelFormatIndex,
                      sizeof(SuggestedPixelFormat), &SuggestedPixelFormat);
  SetPixelFormat(WindowDC, SuggestedPixelFormatIndex, &SuggestedPixelFormat);

  HGLRC OpenGLRC = wglCreateContext(WindowDC);
  if(wglMakeCurrent(WindowDC, OpenGLRC))
  {
    b32 ModernContext = true;
    opengl_info Info = OpenGLGetInfo(ModernContext);
    OpenGLLoadFunctionPointers(Info, ModernContext);

    if(wglSwapIntervalEXT)
    {
      wglSwapIntervalEXT(1);
    }

    OpenGLInit(Info, OpenGL.SupportsSRGBFramebuffer);
  }
  else
  {
    OutputDebugStringA("GL failure!");
  }
  ReleaseDC(Window, WindowDC);
}

internal win32_window_dimension
Win32GetWindowDimension(HWND Window)
{
  win32_window_dimension Result;

  RECT ClientRect;
  GetClientRect(Window, &ClientRect);
  Result.Width = ClientRect.right - ClientRect.left;
  Result.Height = ClientRect.bottom - ClientRect.top;

  return(Result);
}

internal void
Win32ProcessPendingMessages() {
  MSG Message;
  while (PeekMessage(&Message, 0, 0, 0, PM_REMOVE))
  {
    switch (Message.message)
    {
      case WM_QUIT:
      {
        GlobalRunning = false;
      } break;

      case WM_SYSKEYDOWN:
      case WM_SYSKEYUP:
      case WM_KEYDOWN:
      case WM_KEYUP:
      {

      } break;

      default:
      {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
      } break;
    }
  }
}

LRESULT CALLBACK
Win32MainWindowCallback(HWND window,
                        UINT message,
                        WPARAM wParam,
                        LPARAM lParam)
{
  LRESULT result = 0;

  switch(message) {
    case WM_CLOSE:
    {
      GlobalRunning = false;
    } break;

    case WM_DESTROY:
    {
      GlobalRunning = false;
    } break;

    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYDOWN:
    case WM_KEYUP:
    {

    } break;

    case WM_PAINT:
    {
      PAINTSTRUCT paint;
      HDC deviceContext = BeginPaint(window, &paint);
      EndPaint(window, &paint);
    } break;
    default:
    {
      result = DefWindowProc(window, message, wParam, lParam);
    } break;
  }

  return (result);
}

int CALLBACK
  WinMain(
    HINSTANCE instance,
    HINSTANCE prevInstance,
    LPSTR     commandLine,
    int       showCode
  ) {

  WNDCLASS windowClass = {};

  windowClass.style = CS_OWNDC|CS_HREDRAW;
  windowClass.lpfnWndProc = Win32MainWindowCallback;
  windowClass.hInstance = instance;
  windowClass.lpszClassName = "DaliWindowClass";

  LARGE_INTEGER PerfCountFrequencyResult;
  QueryPerformanceFrequency(&PerfCountFrequencyResult);
  GlobalPerfCountFrequency = PerfCountFrequencyResult.QuadPart;

  UINT DesiredSchedulerMS = 1;
  bool32 SleepIsGranular = (timeBeginPeriod(DesiredSchedulerMS) == TIMERR_NOERROR);

  uint32 WindowHeight = 600;
  uint32 WindowWidth = 800;
  if (RegisterClass(&windowClass)) {
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = WindowWidth;
    rect.bottom = WindowHeight;
    AdjustWindowRectEx(&rect, WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, FALSE, 0);

    HWND Window =
      CreateWindowEx(
        0,
        windowClass.lpszClassName,
        "OpenGL Sample",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rect.right - rect.left, // Width
        rect.bottom - rect.top, // Height
        0,
        0,
        instance,
        0);
      if(Window)
      {
        int MonitorRefreshHz = 60;
        HDC RefreshDC = GetDC(Window);
        int Win32RefreshRate = GetDeviceCaps(RefreshDC, VREFRESH);
        if (Win32RefreshRate > 1)
        {
          MonitorRefreshHz = Win32RefreshRate;
        }
        real32 GameUpdateHz = (MonitorRefreshHz / 2.0f);
        real32 TargetSecondsPerFrame = 1.0f / (real32) GameUpdateHz;
        LARGE_INTEGER LastCounter = Win32GetWallClock();

        Win32InitOpenGL(Window);

        GlobalRunning = true;
        while (GlobalRunning)
        {
          HDC deviceContext = GetDC(Window);

          Win32ProcessPendingMessages();

          win32_window_dimension WindowDimensions = Win32GetWindowDimension(Window);

          OpenGLRender();

          SwapBuffers(deviceContext);
          ReleaseDC(Window, deviceContext);

          LARGE_INTEGER WorkCounter = Win32GetWallClock();
          real32 WorkSecondsElapsed = Win32GetSecondsElapsed(LastCounter, WorkCounter);

          // Fixed frame rate
          real32 SecondsElapsedForFrame = WorkSecondsElapsed;
          if (SecondsElapsedForFrame < TargetSecondsPerFrame) {
            if (SleepIsGranular) {
               DWORD SleepMS = (DWORD)(1000.0f * (TargetSecondsPerFrame - SecondsElapsedForFrame));
              if (SleepMS > 0)
              {
                Sleep(SleepMS);
              }
            }

            real32 TestSecondsElapsedForFrame = Win32GetSecondsElapsed(LastCounter, Win32GetWallClock());

            while (SecondsElapsedForFrame < TargetSecondsPerFrame)
            {
              SecondsElapsedForFrame = Win32GetSecondsElapsed(LastCounter, Win32GetWallClock());
            }
          }
          else
          {
            // MISSED FRAME!
          }
        }
      } else {
        // logging
      }
  } else {
    // logging
  }
  return(0);
}