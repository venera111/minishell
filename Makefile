# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 17:26:47 by qestefan          #+#    #+#              #
#    Updated: 2022/05/11 19:38:22 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME_PROJECT = minishell
LIB_DIR = ./libft/
LIB_NAME = libft/libft.a
LIB_HEADER = libft
CC = gcc
HEADER = includes
DIR = ./source/
BUILT = ./source/builtins/
SRCS = $(DIR)main.c $(DIR)clear.c
BUILT_SRC = $(BUILT)echo.c
OBJS = $(SRCS:.c=.o)
OBJB = $(BUILT_SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(NAME_PROJECT)

$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)
$(NAME_PROJECT): $(OBJS) $(OBJB)
		$(CC) $(FLAGS) -I$(HEADER) $(OBJS) $(OBJB) -L. $(LIB_NAME) -o $(NAME_PROJECT)

clean:
	rm -rf $(OBJS) $(OBJB)

fclean: clean
	# make fclean -C $(LIB_DIR) добавить компиляцию libft
	rm -rf $(NAME_PROJECT)
re: fclean all

norm:
	norminette source/*.c includes/*.h

.PHONY: all clean fclean re norm