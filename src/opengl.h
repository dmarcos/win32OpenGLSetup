struct opengl_info
{
  b32 ModernContext;

  char *Vendor;
  char *Renderer;
  char *Version;
  char *ShadingLanguageVersion;
  char *Extensions;

  b32 GL_EXT_texture_sRGB;
  b32 GL_EXT_framebuffer_sRGB;
  b32 GL_ARB_framebuffer_object;
};

struct open_gl
{
  b32 SupportsSRGBFramebuffer;
  GLuint DefaultInternalTextureFormat;
  GLuint BasicProg;
};
