SRCS	= map/map.c so_long.c misc2.c \
			ft_split.c check.c floodfill.c window.c collision.c event.c misc.c

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Wextra

CC		= gcc

RM		= rm -rf

all:	$(NAME)

%.o:	 %.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@
			
$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:	
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all
