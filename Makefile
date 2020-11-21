SRC_DIR =	src
INC_DIR =	include

ENG_DIR =	lib/engine

SRC =		$(SRC_DIR)/main.c			\
			$(SRC_DIR)/example.c		\
			$(SRC_DIR)/moving_rect.c	\
			$(SRC_DIR)/game.c			\

OBJ =		$(SRC:.c=.o)

NAME =		example

CFLAGS +=	-I $(ENG_DIR)/include	\
			-I $(INC_DIR)			\

LDFLAGS +=	-L $(ENG_DIR)		\
			-lengine			\
			-lcsfml-system		\
			-lcsfml-window		\
			-lcsfml-graphics	\

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(ENG_DIR)
			gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			make clean -C $(ENG_DIR)
			rm -f $(OBJ)

fclean:		clean
			make fclean -C $(ENG_DIR)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all $(NAME) clean fclean re
