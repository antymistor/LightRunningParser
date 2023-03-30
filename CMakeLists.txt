cmake_minimum_required(VERSION 3.6)
project(LRP LANGUAGES C CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 11)
# ====================================== define marco ======================================
macro(build_module_clear name)
    set(${name}_cflags "")
    set(${name}_includes "")
    set(${name}_ldflags "")
    set(${name}_ldlibs "")
    set(${name}_type "")
    set(${name}_source_file "")
endmacro(build_module_clear)


macro(build_clear name)
    build_module_clear(${name})
    set(module_name ${name})
    message(STATUS "====begin module [${name}]====")
endmacro(build_clear)

macro(add_includes)
    list(APPEND ${module_name}_includes ${ARGN})
endmacro(add_includes)

macro(add_src_files)
    list(APPEND ${module_name}_source_file ${ARGN})
endmacro(add_src_files)

macro(build_binary name)
    add_executable(${name} ${${name}_source_file})
    build_target_helper(${name})
endmacro(build_binary)

macro(build_target_helper name)
    foreach (flag ${${name}_cflags})
        target_compile_definitions(${name} PUBLIC ${flag})
    endforeach (flag)

    foreach (dir ${${name}_includes})
        target_include_directories(${name} PUBLIC ${dir})
    endforeach (dir)

    foreach (ldflag ${${name}_ldflags})
        set_target_properties(${name} PROPERTIES LINK_FLAGS ${ldflag})
    endforeach (ldflag)

    foreach (lib ${${name}_ldlibs})
        target_link_libraries(${name} PUBLIC ${lib})
    endforeach (lib)

    foreach (lib ${${name}_whole_ldlibs})
        target_link_libraries(${name} PUBLIC -Wl,-whole-archive ${lib} -Wl,--no-whole-archive)
    endforeach (lib)

endmacro(build_target_helper)
# ======================================    START  ======================================
build_clear(LRP)

# ====================================== print info ======================================
message (Module Name   :  ${module_name})
message (Target Sytem  :  ${CMAKE_SYSTEM_NAME})
# ====================================== set include path ======================================
add_includes(src/LRP)
add_includes(src/UTILS)
#======================================    set src path   ======================================
set(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
file(GLOB_RECURSE lrpsrc ${CMAKE_CURRENT_SOURCE_DIR}/src/LRP/*.cpp)
file(GLOB_RECURSE lrputils ${CMAKE_CURRENT_SOURCE_DIR}/src/UTILS/*.cpp)
add_src_files(
        ${main}
        ${lrpsrc}
        ${lrputils}
)
build_binary(LRP)