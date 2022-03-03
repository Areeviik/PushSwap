NAME = push_swap

SRCS = push_swap.c\
		lists.c\
		instructions.c\
		parsing.c\
		utils.c\
		error.c\
		rotate_commands.c\
		split.c\
		indexing.c\
		alg5.c\
		markup1.c\
		alg100.c\


OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc -g

%.o: %c
		$(CC) $(CFLAGS) -c $< -o $@


all: ${NAME}

${NAME} :  ${OBJS}
		${CC} ${CFLAGS}  -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re