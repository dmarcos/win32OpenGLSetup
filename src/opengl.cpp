#include "utils.h"

#define GL_NUM_EXTENSIONS                 0x821D

#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D

#define GL_TEXTURE_3D                     0x806F

#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7

#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B

#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA

#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_TEXTURE_WRAP_R                 0x8072

#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_SRGB8_ALPHA8                   0x8C43

#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83

#define GL_TEXTURE_2D_ARRAY               0x8C1A

#define GL_FRAMEBUFFER                    0x8D40
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5

#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_DEPTH_COMPONENT32F             0x8CAC

#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96

#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_R11F_G11F_B10F                 0x8C3A

#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_MAX_SAMPLES                    0x8D57
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F

global_variable GLenum OpenGLAllColorAttachments[] = {
    GL_COLOR_ATTACHMENT0,
    GL_COLOR_ATTACHMENT1,
    GL_COLOR_ATTACHMENT2,
    GL_COLOR_ATTACHMENT3,
    GL_COLOR_ATTACHMENT4,
    GL_COLOR_ATTACHMENT5,
    GL_COLOR_ATTACHMENT6,
    GL_COLOR_ATTACHMENT7,
    GL_COLOR_ATTACHMENT8,
    GL_COLOR_ATTACHMENT9,
    GL_COLOR_ATTACHMENT10,
    GL_COLOR_ATTACHMENT11,
    GL_COLOR_ATTACHMENT12,
    GL_COLOR_ATTACHMENT13,
    GL_COLOR_ATTACHMENT14,
    GL_COLOR_ATTACHMENT15,
    GL_COLOR_ATTACHMENT16,
    GL_COLOR_ATTACHMENT17,
    GL_COLOR_ATTACHMENT18,
    GL_COLOR_ATTACHMENT19,
    GL_COLOR_ATTACHMENT20,
    GL_COLOR_ATTACHMENT21,
    GL_COLOR_ATTACHMENT22,
    GL_COLOR_ATTACHMENT23,
    GL_COLOR_ATTACHMENT24,
    GL_COLOR_ATTACHMENT25,
    GL_COLOR_ATTACHMENT26,
    GL_COLOR_ATTACHMENT27,
    GL_COLOR_ATTACHMENT28,
    GL_COLOR_ATTACHMENT29,
    GL_COLOR_ATTACHMENT30,
    GL_COLOR_ATTACHMENT31,
};

void Clear()
{
  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void RenderTriangle()
{
  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };
  GLuint VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glUseProgram(OpenGL.BasicProg);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRender()
{
  Clear();
  RenderTriangle();
}

internal GLuint
OpenGLCreateProgram(char *HeaderCode, char *VertexCode, char *FragmentCode)
{
  GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLchar *VertexShaderCode[] =
  {
      HeaderCode,
      VertexCode,
  };
  glShaderSource(VertexShaderID, ArrayCount(VertexShaderCode), VertexShaderCode, 0);
  glCompileShader(VertexShaderID);

  GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  GLchar *FragmentShaderCode[] =
  {
      HeaderCode,
      FragmentCode,
  };
  glShaderSource(FragmentShaderID, ArrayCount(FragmentShaderCode), FragmentShaderCode, 0);
  glCompileShader(FragmentShaderID);

  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID, VertexShaderID);
  glAttachShader(ProgramID, FragmentShaderID);
  glLinkProgram(ProgramID);

  glValidateProgram(ProgramID);
  GLint Linked = false;
  glGetProgramiv(ProgramID, GL_LINK_STATUS, &Linked);
  if(!Linked)
  {
    GLsizei Ignored;
    char VertexErrors[4096];
    char FragmentErrors[4096];
    char ProgramErrors[4096];
    glGetShaderInfoLog(VertexShaderID, sizeof(VertexErrors), &Ignored, VertexErrors);
    glGetShaderInfoLog(FragmentShaderID, sizeof(FragmentErrors), &Ignored, FragmentErrors);
    glGetProgramInfoLog(ProgramID, sizeof(ProgramErrors), &Ignored, ProgramErrors);
    OutputDebugStringA(VertexErrors);
  }

  return(ProgramID);
}

internal opengl_info
OpenGLGetInfo(b32 ModernContext)
{
  opengl_info Result = {};

  Result.ModernContext = ModernContext;
  Result.Vendor = (char *)glGetString(GL_VENDOR);
  Result.Renderer = (char *)glGetString(GL_RENDERER);
  Result.Version = (char *)glGetString(GL_VERSION);
  if(Result.ModernContext)
  {
    Result.ShadingLanguageVersion = (char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
  }
  else
  {
    Result.ShadingLanguageVersion = "(none)";
  }

  Result.Extensions = (char *)glGetString(GL_EXTENSIONS);

  for(char *At = Result.Extensions;
      *At;
      )
  {
    while(IsWhitespace(*At)) {++At;}
    char *End = At;
    while(*End && !IsWhitespace(*End)) {++End;}

    umm Count = End - At;

    if(0) {}
    else if(StringsAreEqual(Count, At, "GL_EXT_texture_sRGB")) {Result.GL_EXT_texture_sRGB=true;}
    else if(StringsAreEqual(Count, At, "GL_EXT_framebuffer_sRGB")) {Result.GL_EXT_framebuffer_sRGB=true;}
    else if(StringsAreEqual(Count, At, "GL_ARB_framebuffer_sRGB")) {Result.GL_EXT_framebuffer_sRGB=true;}
    else if(StringsAreEqual(Count, At, "GL_ARB_framebuffer_object")) {Result.GL_ARB_framebuffer_object=true;}

    At = End;
  }

  char *MajorAt = Result.Version;
  char *MinorAt = 0;
  for(char *At = Result.Version;
      *At;
      ++At)
  {
    if(At[0] == '.')
    {
        MinorAt = At + 1;
        break;
    }
  }

  s32 Major = 1;
  s32 Minor = 0;
  if(MinorAt)
  {
    Major = S32FromZ(MajorAt);
    Minor = S32FromZ(MinorAt);
  }

  if((Major > 2) || ((Major == 2) && (Minor >= 1)))
  {
    Result.GL_EXT_texture_sRGB = true;
  }

  return(Result);
}

internal opengl_info
OpenGLInit(opengl_info Info, b32 FramebufferSupportsSRGB)
{
  OpenGL.DefaultInternalTextureFormat = GL_RGBA8;
  if(FramebufferSupportsSRGB && Info.GL_EXT_texture_sRGB && Info.GL_EXT_framebuffer_sRGB)
  {
    OpenGL.DefaultInternalTextureFormat = GL_SRGB8_ALPHA8;
    glEnable(GL_FRAMEBUFFER_SRGB);
  }

  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  char *HeaderCode = R"FOO(
  #version 130
  // Header code
  )FOO";

  char *VertexCode = R"FOO(
  void main(void)
  {
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
  }
  )FOO";

  char *FragmentCode = R"FOO(
  out vec4 FragColor;
  void main(void)
  {
    FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
  }
  )FOO";

  OpenGL.BasicProg = OpenGLCreateProgram(HeaderCode, VertexCode, FragmentCode);
  return(Info);
}
