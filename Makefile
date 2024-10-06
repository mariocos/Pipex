CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = pipex

SRCS =	pipex.c \
		parsing.c \
		error_handling.c \
		gnl.c \
		libft_utils.c \
		libft_utils_2.c \
		here_doc_handler.c \

OBJS = ${SRCS:.c=.o}

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
