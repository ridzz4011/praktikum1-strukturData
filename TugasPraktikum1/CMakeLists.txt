cmake_minimum_required(VERSION 3.27.7)
project(TugasPraktikum1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(TugasPraktikum1 main.cpp

               src/functionMisc/clearscreen/clearscreen.cpp
               src/functionMisc/loading/loading.cpp
               src/functionMisc/pauseconsole/pauseconsole.cpp
               src/functionMisc/intro/intro.cpp
               
               src/functionTugas/groupArray/groupArray.cpp
               src/functionTugas/pointer/pointer.cpp)

target_include_directories(TugasPraktikum1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
