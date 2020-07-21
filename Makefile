NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror $(INC) -c -o

INC = -I includes/

SRCS_DIR = srcs/

OBJ_DIR = obj/

SRCS = ft_printf.c help.c help_float.c itoa_base.c libft.c libft2.c not_found.c parser.c parser_spec.c print_ae.c print_aefg.c print_all.c print_bxou.c print_c.c print_di.c print_f.c print_g.c print_n.c print_p.c print_percent.c print_s.c print_ws.c ws_help.c

CFIND = $(SRCS:%=$(SRCS_DIR)%)

OFILE = $(SRCS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
	@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
	@ranlib $(NAME)
	@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
	@$(MAKE) $(OFILE)

$(OFILE):
	@$(CC) $(FLAGS) $(OBJ_DIR)$@ $(SRCS_DIR)$(@:%.o=%.c)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo Cleaned ft_printf object files

fclean: clean
	@/bin/rm -f $(NAME)
	@echo Cleaned $(NAME)

re: fclean all
