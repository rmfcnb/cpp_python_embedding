find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

include_directories(
        include
        ${CMAKE_SOURCE_DIR}/parser/include)

add_library(pythonparser SHARED
        src/pythonparser.cpp
        src/asdf.py)

find_package (Python)

target_link_libraries(pythonparser ${PYTHON_LIBRARIES})

target_compile_options(pythonparser PUBLIC -Wno-unknown-pragmas)

set(ENV{PYTHONPATH} "${CMAKE_SOURCE_DIR}/src")
message(STATUS "the value of PYTHONPATH: " $ENV{PYTHONPATH})

install(TARGETS pythonparser DESTINATION ${INSTALL_PARSER_DIR})