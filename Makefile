# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warharra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 10:17:18 by warharra          #+#    #+#              #
#    Updated: 2019/05/22 17:31:21 by warharra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC  = check_and_initialise.c check_file.c check_form.c\
        main.c place_forme.c tab.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
LIBFT = libft
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C $(LIBFT) libft.a
	gcc -c -Iincludes  $(SRC) 
	gcc $(FLAGS) -Iincludes $(OBJ) -o $(NAME) $(LIB)

clean:
	make -C $(LIBFT) $@
	rm -rf $(OBJ)
	rm -rf libft.a

fclean: clean
	make -C $(LIBFT) $@
	rm -f $(NAME)

re: fclean all
norme:
	norminette $(SRC)
