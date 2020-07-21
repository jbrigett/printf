cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_library(printf ft_printf.c includes/ft_printf.h srcs/parser.c srcs/print_di.c srcs/help.c srcs/itoa_base.c srcs/print_bxou.c srcs/print_aefg.c srcs/print_ae.c srcs/print_f.c srcs/print_g.c srcs/parser_spec.c srcs/help_float.c srcs/print_c.c srcs/print_s.c srcs/print_ws.c srcs/ws_help.c srcs/print_all.c srcs/print_p.c srcs/print_n.c srcs/not_found.c srcs/print_percent.c)