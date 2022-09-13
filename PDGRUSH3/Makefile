##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MODULES =	src/modules/OS.cpp	\
			src/modules/Name.cpp	\
			src/modules/Time.cpp	\
			src/modules/MonitorCore.cpp 	\
			src/modules/TerminalMode.cpp	\
			src/modules/MonitorRam.cpp 	\
			src/modules/MonitorNet.cpp 	\
			src/modules/MonitorProcess.cpp 	\
			src/modules/Uptime.cpp

GRAPHICAL_FILES	=	src/graphical/sfml.cpp \
					src/graphical/init_widgets.cpp \
					src/graphical/toolbar.cpp \
					src/graphical/toolbarOnClick.cpp	\

TEXT_FILES	=

SRC	=	$(MODULES)	\
		$(GRAPHICAL_FILES)	\
		$(TEXT_FILES)	\
		src/MyGKrellm.cpp	\
		main.cpp	\

SRC_TEST	=	tests/test_one.cpp	\

OBJ		=	$(SRC:.cpp=.o)
NAME		=	MyGKrellm
TEST_NAME	=	unitest
RM		=	rm -f
CPPFLAGS	=	-I./include
ERROR	=	-W -Wall -Wextra
TFLAGS	=	--coverage -lcriterion
GRAPHICS	=	-lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window
TEXT	=	-lncurses
CC		=	g++

all:	$(NAME)
$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(ERROR) $(GRAPHICS) $(TEXT)

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

re:		clean all

.PHONY:	all clean fclean tests_run unitest
