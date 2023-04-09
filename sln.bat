SET CMAKE_PATH=C:\Program Files\CMake\bin
del CMakeFiles /s /f /q
"%CMAKE_PATH%\cmake" -G "Visual Studio 16 2019" -A x64
pause
