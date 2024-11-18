CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = pipex

SRCS =	pipex.c \
		pipex_utils.c \

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
