SRC_DIR =	src

SRC =		$(SRC_DIR)/main.c				\
			$(SRC_DIR)/engine/engine.c		\
			$(SRC_DIR)/engine/pipeline.c	\
			$(SRC_DIR)/engine/window.c		\
			$(SRC_DIR)/engine/keyboard.c	\
			$(SRC_DIR)/engine/settings.c	\

OBJ =		$(SRC:.c=.o)

NAME =		engine

CFLAGS +=	-I include			\
			-I include/engine	\

LDFLAGS +=	-lcsfml-graphics	\
			-lcsfml-window		\
			-lcsfml-audio		\
			-lcsfml-system		\
			-W					\
			-Wall				\
			-Wextra				\

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all $(NAME) clean fclean re
