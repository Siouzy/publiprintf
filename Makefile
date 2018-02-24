# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/05 13:21:17 by srepelli     #+#   ##    ##    #+#        #
#    Updated: 2018/02/22 14:58:37 by srepelli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putstr.c \
	   ft_countchar.c \
	   ft_nblen.c \
	   ft_atoi.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_charpos.c \
	   ft_itoa_base.c \
	   ft_itoa.c \
	   ft_strsub.c\
	   ft_strcmp.c \
	   ft_strnew.c \
	   ft_strlen.c \
	   ft_putstrn.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strcat.c \
	   ft_strcpy.c \
	   ft_charstrstr.c \
	   ft_strdel.c \
	   ft_unicode.c \
	   ft_printf.c \
	   ft_precision.c \
	   ft_taille.c \
	   ft_indic.c \
	   ft_attributs.c \
	   ft_largmin.c \
	   isattrib.c \
	   indiclist1.c \
	   indiclist2.c \
	   indiclist3.c \
	   attriblist.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEAD = -I ./

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) $(HEAD) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
