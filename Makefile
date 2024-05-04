NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
		string_utils.c \
		ft_split.c \
		free.c \
		pipex_utils.c \
		childs.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} pipex.h Makefile
	@${CC} ${CFLAGS} main.c ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
	