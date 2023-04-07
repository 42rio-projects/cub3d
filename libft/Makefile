SRCS	= ft_isdigit.c ft_strlen.c ft_bzero.c ft_strdup.c ft_strchr.c ft_strncmp.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_atol.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR_RC 	= ar rc

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@${AR_RC} ${NAME} ${OBJS}
			@echo "\033[32m 💯 | Libft created."

all:		$(NAME)

clean:
			@${RM} ${OBJS}
			@${RM} ${OBJS_BONUS}
			@echo "\033[33m 🧹 | Libft cleaned."

fclean:		clean
			@${RM} ${NAME}
			@echo "\033[33m 🌪️  | Libft all cleaned."

re:		fclean all

.PHONY:		all clean fclean re
