# CMakeList.txt: cppserverstudio 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)


project ("HooLog")


# 使能 C++11
# Enable C++11
set(CMAKE_CXX_STANDARD 11)

#设置子目录
#Set subdirectories
set(SUB_DIR_LIST "HooLog")

foreach(SUB_DIR ${SUB_DIR_LIST})
    #遍历源文件
    #Traverse source file
    aux_source_directory(src/${SUB_DIR} SRC_LIST)
    include_directories(src/${SUB_DIR} INC_LIST)
endforeach()

#安装目录
#Installation directory
if(WIN32)
    set(INSTALL_PATH_LIB $ENV{HOME}/${PROJECT_NAME}/lib)
    set(INSTALL_PATH_INCLUDE $ENV{HOME}/${PROJECT_NAME}/include)
else()
    set(INSTALL_PATH_LIB lib)
    set(INSTALL_PATH_INCLUDE include)
endif()


add_subdirectory(tests)
