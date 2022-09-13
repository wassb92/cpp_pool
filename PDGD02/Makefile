##
## EPITECH PROJECT, 2022
## Haskell day 2
## File description:
## Makefile
##

SRC	=	DoOp.hs	\

SRC_TEST	=	\

OBJ	=	$(SRC:.c=.hi)
NAME	=	doop
TEST_NAME	=	unitest
RM	=	rm -f
CFLAGS	=	-I./include/ -L.
ERROR	=	-Wall -Wextra
DEBUG	=	-g3
CC	=	ghc
TFLAGS	=	--coverage -lcriterion
LDFLAGS	=	-lm

all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS)

clean:
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.o
	$(RM) *.hi

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest :
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(TFLAGS) $(CFLAGS)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

.PHONY:	all clean fclean tests_run unitest

re:	fclean all