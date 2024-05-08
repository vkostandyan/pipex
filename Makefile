NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = 	cmd.c \
		free.c \
		utils.c \
		./libft/ft_join.c \
		./libft/ft_split.c \
		./libft/ft_strlen.c \
		./libft/ft_strncmp.c \
		./libft/ft_strlcpy.c \
		./libft/ft_putstr_fd.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} pipex.h Makefile
	@${CC} ${CFLAGS} main.c ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS} outfile

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re