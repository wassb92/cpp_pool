##
## EPITECH PROJECT, 2022
## ex00
## File description:
## Makefile
##

SRC	=	z.c	\

SRC_TEST	=	\

OBJ	=	$(SRC:.c=.o)
NAME	=	z
TEST_NAME	=	unitest
RM	=	rm -f
CFLAGS	=	-I./include/ -L.
ERROR	=	-std=gnu17 -Wall -Wextra -Werror
DEBUG	=	-g3
CC	=	gcc
TFLAGS	=	--coverage -lcriterion
LDFLAGS	=	-lm

all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(ERROR) $(SRC) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

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