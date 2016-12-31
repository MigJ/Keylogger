CC	=	gcc

NAME	=	Keylogger

SRC	=	src/edit_mail.c 	\
		src/input.c   		\
		src/write.c		\

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
