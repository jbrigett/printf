cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_library(printf ft_printf.c ft_printf.h parser.c print_di.c help.c itoa_base.c print_bxou.c print_aefg.c print_ae.c print_f.c print_g.c parser_spec.c help_float.c print_c.c print_s.c print_ws.c ws_help.c print_all.c print_p.c print_n.c not_found.c print_percent.c)