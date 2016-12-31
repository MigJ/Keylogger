##
## Makefile for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/
##
## Made by Nathan Tréhout
## Login   <nathan.trehout@epitech.eu>
##
## Started on  Sat Dec 31 15:30:40 2016 Nathan Tréhout
## Last update Sat Dec 31 15:30:44 2016 Nathan Tréhout
##

CC	=	gcc

NAME	=	Keylogger

SRC	=	src/edit_mail.c 	\
		src/input.c   		\
		src/write.c		\
		src/convert_pass.c	\
		src/ressources.c	\
		src/tools.c		\

LIB	=	-L lib -lmy

CFLAGS	=	-I./inc/ -W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
