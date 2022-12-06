cmake_minimum_required(VERSION 3.20.1)

# set(CMAKE_TOOLCHAIN_FILE $ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake)
# set(ANDROID_ABI "arm64-v8a")
# set(ANDROID_STL "c++_static")
# set(ANDROID_NATIVE_API_LEVEL "android-21")

project(plygrd)


set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -g -O0")

# include_directories (${useHello_SOURCE_DIR})
#  link_directories(${PROJECT_SOURCE_DIR})#${PROJECT_SOURCE_DIR}
message("-----z-xxx:$ENV{ANDROID_NDK}")

file(GLOB files *.cpp */*.cpp)
foreach (file ${files})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
  add_executable (${exe} ${file})
  message(\ \ \ \ --\ ${exe}.cpp \ will\ be\ to \ ${exe})
endforeach ()