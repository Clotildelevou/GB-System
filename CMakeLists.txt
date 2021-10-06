# ==========================================
#            Various definitions
# ==========================================

cmake_minimum_required(VERSION 3.15)
project(gb-emulator VERSION 1.0.0 LANGUAGES C)

#Verbose option
set(CMAKE_VERBOSE_MAKEFILE OFF)

#Test option
option(ENABLE_TESTS "Build tests along with the library" ON)


set(SOURCE_ROOT "${PROJECT_SOURCE_DIR}/src")
set(EXC_TST "${PROJECT_SOURCE_DIR}/build")
set(CFLAGS -Wextra -Werror -pedantic -std=c99 -I${SOURCE_ROOT})
set(LDFLAGS_TEST -fsanitize=address -lcriterion)

# ==========================================
#             Libraries
# ==========================================

# The name of all the libs in the project.
# If you want to add a lib, add its name to this variable
set(LIBS
        gameboy
        cpu
        )

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

# gameboy

file(GLOB_RECURSE GB_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/gameboy/*.c")
add_library(gameboy STATIC ${GB_SOURCES})
target_compile_options(gameboy PRIVATE ${CFLAGS})

# cpu
file(GLOB_RECURSE CPU_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/cpu/*.c")
add_library(cpu STATIC ${CPU_SOURCES})
target_compile_options(cpu PRIVATE ${CFLAGS})

# this is how you are supposed to link a librairie
# file(GLOB_RECURSE LIB_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/lib/*.c")
# add_library(lib STATIC ${LIB_SOURCES})
# target_compile_options(lib PRIVATE ${CFLAGS})
# target_link_libraries(lib PRIVATE cpu)


# ==========================================
#             Test executables
# ==========================================

if (ENABLE_TESTS)

    include (CTest)

    ######Lib2
    ####file(GLOB_RECURSE#LIB2_TESTS#RELATIVE#${CMAKE_SOURCE_DIR}
    ########"tests/unit_tests/lib2/*.c")
    ####add_executable(lib2_unit#${LIB2_TESTS})
    ####target_compile_options(lib2_unit#PRIVATE#${CFLAGS})
    ####target_link_libraries(lib2_unit#PRIVATE#lib2#lib1)
    ####target_link_options(lib2_unit#PRIVATE#${LDFLAGS_TEST})
    ####add_test(NAME#lib2_unit#COMMAND#${EXC_TST}/lib2_unit)

endif()

# ==========================================
#           Final executable
# ==========================================

add_executable(gb_emulator src/main.c)
target_link_libraries(gb_emulator PRIVATE ${LIBS}) # you can add other librairies path if necessary
target_compile_options(gb_emulator PRIVATE ${CFLAGS})
