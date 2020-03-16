inline b32
IsEndOfLine(char C)
{
  b32 Result = ((C == '\n') ||
                (C == '\r'));

  return(Result);
}

inline b32
IsWhitespace(char C)
{
  b32 Result = ((C == ' ') ||
                (C == '\t') ||
                (C == '\v') ||
                (C == '\f') ||
                IsEndOfLine(C));

  return(Result);
}

inline b32
StringsAreEqual(umm ALength, char *A, char *B)
{
  b32 Result = false;

  if(B)
  {
    char *At = B;
    for(umm Index = 0;
        Index < ALength;
        ++Index, ++At)
    {
      if((*At == 0) ||
         (A[Index] != *At))
      {
         return(false);
      }
    }

    Result = (*At == 0);
  }
  else
  {
    Result = (ALength == 0);
  }

  return(Result);
}

internal s32
S32FromZInternal(char **AtInit)
{
  s32 Result = 0;

  char *At = *AtInit;
  while((*At >= '0') &&
        (*At <= '9'))
  {
    Result *= 10;
    Result += (*At - '0');
    ++At;
  }

  *AtInit = At;

  return(Result);
}

internal s32
S32FromZ(char *At)
{
  char *Ignored = At;
  s32 Result = S32FromZInternal(&At);
  return(Result);
}

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))