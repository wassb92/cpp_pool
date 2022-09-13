##
## EPITECH PROJECT, 2022
## Haskell Rush
## File description:
## Makefile
##

SRC     =	pushswap_checker.hs

NAME    =	pushswap_checker

CC	=	ghc

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

.PHONY: clean fclean re

clean:
	rm -f *.hi
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re:	fclean all