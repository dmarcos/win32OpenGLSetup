# Handmade OpenGL

Setting up OpenGL on Win32 from scratch. No GLEW / GLFW / GLU or any other helper libraries.

Inspired by [Handmade Hero](https://handmadehero.org/)

# Build Steps

I'm working on Windows 10 I hope the steps apply to other versions of Windows.

- Download and Install [Visual Studio Community](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx). Make sure to select ```Comon Tools For Visual C++``` from the feature list so the C compiler gets installed.

![Common Tools for Visual C++](http://blogs.msdn.com/cfs-filesystemfile.ashx/__key/communityserver-blogs-components-weblogfiles/00-00-00-65-69/6406._5F00_aaimage003.png)

- Make sure to run ```vcvarsall.bat x64``` so the compiler(cl) and the debugger(devenv) are available in the Windows(TM) terminal. In my machine ```vcvarsall.bat``` lives in ```C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat```. You will have to run the script each time you start a console. To automate the process you can create a ```startup.bat``` script that gets automatically run each time a console starts.

- Run the ```build.bat``` script included in the repo to build your program
- If compilation goes right you will get the executable in the build directory
- You can run the program in the debugger by doing ```devenv build/main.exe```




