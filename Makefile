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
		show_alloc_mem.c\
		my_put_nbr.c

SRCS	=	$(addprefix $(SRCDIR), $(SRC))

CC  =   gcc

CFLAGS	=	-Wall -Wextra -g3 -I$(INCLDIR) -fPIC

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc.so

MAC =   libmy_malloc.dylib

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -shared -o $@ $^

$(MAC):     $(OBJS)
	$(CC) -dynamiclib -undefined suppress -flat_namespace -o $@ $^

mac: $(MAC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

cmac: clean
	rm -rf $(MAC)

re: fclean all

.PHONY: all clean fclean re
