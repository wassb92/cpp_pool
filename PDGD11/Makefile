##
## EPITECH PROJECT, 2022
## cpppool
## File description:
## Makefile
##

SRC	=

SRC_TEST	=	tests/test_one.cpp	\
				ex00/Picture.cpp	\
				ex00/Toy.cpp	\

OBJ	=	$(SRC:.cpp=.o)
NAME	=	binary
TEST_NAME	=	unitest
RM	=	rm -f
CFLAGS	=	-I./include/ -L.
LDFLAGS	=	-lm
ERROR	=	-Wall -Wextra
DEBUG	=	-g3
CC	=	g++
TFLAGS	=	--coverage -lcriterion

all:

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest :
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(LDFLAGS) $(TFLAGS) $(CFLAGS)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

.PHONY:	all clean fclean tests_run unitest

re:	fclean all