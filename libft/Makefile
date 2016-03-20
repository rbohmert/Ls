# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by rbohmert          #+#    #+#              #
#    Updated: 2016/02/20 20:36:43 by rbohmert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	  ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	  ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	  ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstat.c ft_push_back.c \
	  ft_push_front.c ft_create_elem.c get_next_line.c

OBJ = $(SRC:.c=.o)

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@echo "\033[33m----------------------------------\033[0m"
		@echo "\033[36mCompiling in .o\033[0m"
		@$(GCC) -c $(SRC) $(HEAD)
		@echo "\033[36mCreating library\033[0m"
		@ar rc $(NAME) $(OBJ)
		@echo "\033[36mIncrease the search speed\033[0m"
		@ranlib $(NAME)
		@echo "\033[32mLibrary Created\033[0m"
		@echo "\033[33m----------------------------------\033[0m"

clean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31mDeleting all .o\033[31m"
	@rm -rf $(OBJ)
	@echo "\033[32mThe folder is clean !\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

fclean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31mDeleting Library.a and all .o\033[31m"
	@rm -rf $(NAME) $(OBJ)
	@echo "\033[32mThe folder is clean\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

re: fclean all
