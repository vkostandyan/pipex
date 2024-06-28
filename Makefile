NAME = pipex
CFLAGS = -Wall -Wextra -Werror 
CC = cc #-fsanitize=address
SRCS =	main.c \
		cmd.c \
		free.c \
		utils.c \

HEADER = 	pipex.h \
			libft.h 

LIBFT = ft_join.c \
		ft_split.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_putstr_fd.c 

SRCS_DIR = ./sources/
HEADER_DIR = ./includes/
LIBFT_DIR = ./libft/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))

SRCS += $(LIBFT)

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} ${MLX} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
