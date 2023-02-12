NAME = cub3D

BUILD = unitTests/build

FLAGS = -Wall -Wextra -Werror -g

CC = cc

SRC_DIR = ./src/

SRCS = cub3d.c check_arguments.c

FUNCS = $(addprefix $(SRC_DIR), $(SRCS))

RM = rm -rf

all:		$(NAME)

$(NAME):	$(FUNCS)
			@$(CC) $(FLAGS) $(FUNCS) -o $(NAME)
			@echo "\033[32m 💯 | cub3d created."

${BUILD}:
			cd unitTests && cmake -S . -B build

test: ${BUILD}
			cd unitTests && cmake --build build
			cd unitTests/build && ctest --output-on-failure

clean:
			@${RM} ${NAME}.dSYM
			@echo "\033[33m 🧹  | cub3d cleaned."

fclean: 	clean
			@$(RM) $(NAME)
			@echo "\033[33m 🌪️  | cub3d all cleaned."

re:			fclean all

.PHONY:		all clean fclean re
