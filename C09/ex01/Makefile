SRCS    = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS    = ${SRCS:.c=.o}
INCLUDES = includes
NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
LIBC    = ar rc
LIBR    = ranlib
RM      = rm -f

all:    ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re
