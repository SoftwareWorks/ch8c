cmake_minimum_required(VERSION 2.6)

project(ch8c)

set(CMAKE_BUILD_TYPE debug)

set(files
        defines.h
        x/functions.cpp x/functions.h
        x/labels.cpp x/labels.h
        x/program.cpp x/program.h
        x/scope.h
        x/statement.h x/statements.cpp x/statements.h
        x/variable.h x/variables.cpp x/variables.h
        )
#x/parser/parser.cpp x/parser/parser.h
#x/parser/parser.tab.cpp x/parser/parser.tab.h
#x/parser/lexer.h x/parser/lexer.cpp

add_executable(ch8c ${files} main.cpp)

target_include_directories(ch8c PRIVATE . x x/parser)

set_property(TARGET ch8c PROPERTY CXX_STANDARD 17)

