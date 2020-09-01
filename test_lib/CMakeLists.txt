find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

include_directories(
        include
        ${CMAKE_SOURCE_DIR}/test_lib/include)

add_executable(test
        src/lib.cpp
        src/asdf.py)

find_package (Python)

target_link_libraries(test ${PYTHON_LIBRARIES})

target_compile_options(test PUBLIC -Wno-unknown-pragmas)

set(ENV{PYTHONPATH} "${CMAKE_SOURCE_DIR}/src")
message(STATUS "the value of PYTHONPATH: " $ENV{PYTHONPATH})

install(TARGETS test DESTINATION ${INSTALL_PARSER_DIR})