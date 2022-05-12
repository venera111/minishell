# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 17:26:47 by qestefan          #+#    #+#              #
#    Updated: 2022/05/12 11:24:19 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g -Wall -Wextra -Werror
NAME_PROJECT = minishell
CC = gcc

#paths
HEADER = includes
LIB_DIR = ./libft/
LIB_NAME = libft/libft.a
LIB_HEADER = libft
DIR = ./source/
BUILT = ./source/builtins/
PARS = ./source/parser/

#source
SRCS = $(DIR)main.c $(DIR)free.c $(DIR)error.c
BUILT_SRC = $(BUILT)echo.c $(BUILT)cd.c $(BUILT)cd_utils.c
PARS_SRC = $(PARS)list_init.c $(PARS)make_envp_list.c

OBJS = $(SRCS:.c=.o)
OBJB = $(BUILT_SRC:.c=.o)
OBJP = $(PARS_SRC:.c=.o)

#compile
.c.o:
	$(CC) $(FLAGS) -c -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)

$(NAME_PROJECT): $(OBJS) $(OBJB) $(OBJP)
		$(CC) $(FLAGS) -I$(HEADER) $(OBJS) $(OBJB) $(OBJP) -L. $(LIB_NAME) -o $(NAME_PROJECT)

all: $(LIBFT) $(NAME_PROJECT)

clean:
	rm -rf $(OBJS) $(OBJB) $(OBJP)

fclean: clean
	# make fclean -C $(LIB_DIR) я добавлю авто-компиляцию libft
	rm -rf $(NAME_PROJECT)
re: fclean all

norm:
	norminette source/*.c includes/*.h

.PHONY: all clean fclean re norm