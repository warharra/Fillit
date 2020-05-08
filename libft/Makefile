# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warharra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 16:22:22 by warharra          #+#    #+#              #
#    Updated: 2019/04/30 15:05:33 by warharra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_strlen.c ft_isascii.c ft_putchar.c ft_putstr.c ft_strsplit.c\
		ft_strcpy.c ft_strjoin.c ft_strncmp.c ft_isdigit.c ft_memcmp.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_strdel.c ft_strlcat.c\
		ft_strncpy.c ft_strstr.c ft_atoi.c ft_isprint.c ft_memcpy.c \
		ft_putendl.c ft_strcat.c ft_strdup.c ft_strnew.c ft_strsub.c \
		ft_bzero.c ft_memdel.c ft_putendl_fd.c ft_strchr.c ft_putnbr_fd.c\
		ft_strequ.c ft_strmap.c ft_strnequ.c ft_strtrim.c ft_isalnum.c \
		ft_memalloc.c ft_memmove.c ft_putnbr.c ft_strclr.c ft_striter.c \
		ft_strmapi.c ft_strnstr.c ft_tolower.c ft_isalpha.c ft_memccpy.c \
		ft_memset.c ft_strcmp.c ft_striteri.c ft_strncat.c  ft_memchr.c\
		ft_strrchr.c ft_toupper.c ft_lstnew.c ft_strlcat.c ft_itoa.c\
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		search_and_replace.c ft_capitalize.c ft_strrev.c\
		ft_split_whitespaces.c ft_len.c ft_strchrn.c

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -Iincludes $(FLAGS) -c $(SRCS) 
	ar rc $(NAME) $(SRCS:.c=.o)
	ranlib $(NAME)

clean:
	rm -rf $(SRCS:.c=.o)

fclean: clean
	rm -rf $(NAME)


re: fclean all
