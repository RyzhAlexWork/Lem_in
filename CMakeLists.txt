cmake_minimum_required(VERSION 3.15)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -g")

aux_source_directory(srcs/Lem-in LEMIN_SRC)
aux_source_directory(libft/printf PRINTF_SRC)

add_executable(Lem-in ${LEMIN_SRC} ${PRINTF_SRC} srcs/GetNextLine/get_next_line.c)

aux_source_directory(libft LIBFT_SRC)

add_library(libft STATIC ${LIBFT_SRC})

include_directories(srcs/GetNextLine)
include_directories(libft/includes)
include_directories(libft/printf)
include_directories(includes)

find_library(LIBFT libft cmake-build-debug)
target_link_libraries(Lem-in LINK_PUBLIC ${LIBFT})