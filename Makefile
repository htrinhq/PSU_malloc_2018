##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

INCLDIR	= includes/

SRCDIR	= sources/

SRC	=	realloc.c\
		free.c\
		malloc.c\
		show_alloc_mem.c

SRCS	=	$(addprefix $(SRCDIR), $(SRC))

CC  =   gcc

CFLAGS	=	-Wall -Wextra -g3 -I$(INCLDIR) -fPIC

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -shared -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
