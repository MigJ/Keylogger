CC	=	gcc -g

NAME	=	Keylogger

SRC	=	*.c

LIB	=

CFLAGS	=	-I./includes/ -W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L lib -lmy

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
