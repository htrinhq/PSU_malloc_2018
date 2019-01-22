##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

INCLDIR	= includes/

SRCDIR	= sources/

SRC	=	main.c

SRCS	=	$(addprefix $(SRCDIR), $(SRC))

CFLAGS	=	-Wall -Wextra -g3 -I$(INCLDIR)

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
