##
## EPITECH PROJECT, 2021
## day05
## File description:
## makefile
##

SRC	=	my_string.c	\
		assign.c	\
		append.c	\
		at.c	\
		clear.c	\
		length.c	\
		compare.c	\
		copy.c	\
		c_str.c	\
		empty.c	\
		find.c	\
		insert.c	\
		to_int.c	\
		split.c	\
		print.c	\
		join.c	\

SRC_TEST	=	\

OBJ	=	$(SRC:.c=.o)
NAME	=	libstring.a
TEST_NAME	=	unitest
RM	=	rm -f
ERROR	=	-std=gnu17 -Wall -Wextra -Werror
DEBUG	=	-g3
CC	=	gcc
TFLAGS	=	--coverage -lcriterion
LDFLAGS	=	-lm


all:	$(NAME)
$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

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