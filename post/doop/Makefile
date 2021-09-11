NAME	:=	do-op
SRCS	:=	do-op.c utils.c
#SRCS	:=	$(*.c)
#OBJS	:=	$(SRC:c=o)
CC	:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -I .
RM	:=	rm -f

all	:	@$(NAME)
do-op	:	$(SRCS)
		@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
clean	:	
		@$(RM) $(NAME)
