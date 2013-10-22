NAME	=	CHIP-8

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c \
		src/SDLmanager.c

OBJS	=	$(SRCS:.c=.o)

##CFLAGS	+=	-W -Wall -Wextra -Werror

LIBS	=	-lSDL

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIBS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all