SRC_DIR =	src
INC_DIR =	include

SRC =		$(SRC_DIR)/engine.c		\
			$(SRC_DIR)/pipeline.c	\
			$(SRC_DIR)/window.c		\
			$(SRC_DIR)/keyboard.c	\
			$(SRC_DIR)/settings.c	\

OBJ =		$(SRC:.c=.o)

NAME =		libengine.a

CFLAGS +=	-I $(INC_DIR)		\
			-W					\
			-Wall				\
			-Wextra				\

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all $(NAME) clean fclean re
