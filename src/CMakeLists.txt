# - Set CMake requirements then decalre project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. THis can also be done by removing the 'set' command and 
#   running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON) 

# Set the C++ standard directly
set(CMAKE_CXX_STANDARD 14)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/transformChar.cpp MPAGSCipher/transformChar.hpp 
MPAGSCipher/ProcessCommandLine.cpp MPAGSCipher/ProcessCommandLine.hpp MPAGSCipher/runCaesarCipher.cpp 
MPAGSCipher/runCaesarCipher.hpp)


target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

# Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher 
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )



