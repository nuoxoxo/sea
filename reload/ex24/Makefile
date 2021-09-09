NAME	:=	libft.a
HEADER	:=	includes
SRCS	:=	srcs/ft_putchar.c \
    		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c
OBJS	:=	${SRCS:c=o}
CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -I includes
RM	:=	rm -f

# Above : macros
# Below : targets

all	:	${NAME}
%.o	:	%.c
			${CC} ${CFLAGS} -c $< -o ${<:c=o}
${NAME}	:	${OBJS}	
			ar rc	${NAME} ${OBJS}
clean	:	
			${RM} ${OBJS}
fclean	:	clean
			${RM} ${NAME}
re	:	fclean all
.PHONY	:	all clean fclean re

# -I adds include directory of header files.
# $< used in the "recipe" means "the first prerequisite" ie the 1st thing after the : in the line above.
