##
## EPITECH PROJECT, 2022
## cpp project
## File description:
## Makefile
##

SRC	=	my_convert_temp.cpp	\

SRC_TEST	=	\

OBJ	=	$(SRC:.cpp=.o)
NAME	=	my_convert_temp
TEST_NAME	=	unitest
RM	=	rm -f
CXXFLAGS += -std=c++20 -I./include/ -L.
ERROR	=	-Wall -Wextra
DEBUG	=	-g3
CC	=	g++
TFLAGS	=	--coverage -lcriterion

all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CXXFLAGS) $(ERROR) $(SRC)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest :
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(TFLAGS) $(CXXFLAGS)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

.PHONY:	all clean fclean tests_run unitest

re:	fclean all