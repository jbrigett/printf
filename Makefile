NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror $(INC) -c -o

INC = -I includes/

SRCS_DIR = srcs/

OBJ_DIR = obj/

SRCS = ft_printf.c help.c help_float.c itoa_base.c libft.c libft2.c not_found.c parser.c parser_spec.c print_ae.c print_aefg.c print_all.c print_bxou.c print_c.c print_di.c print_f.c print_g.c print_n.c print_p.c print_percent.c print_s.c print_ws.c ws_help.c help_spec_val.c

CFIND = $(SRCS:%=$(SRCS_DIR)%)

OFILE = $(SRCS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJ)
	@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(CFIND)
	@$(MAKE) $(OFILE)

$(OFILE):
	@$(CC) $(FLAGS) $(OBJ_DIR)$@ $(SRCS_DIR)$(@:%.o=%.c)

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
