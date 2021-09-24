NAME	:=	ft_tail
SRCS	:=	${wildcard *.c}
#SRCS	:=	ft_tail.c
CC	:=	gcc -Wall -Werror -Wextra -I .

all	:	$(NAME)
$(NAME)	:
		@$(CC) $(SRCS) -o $(NAME)
#run	:
#		./$(NAME)
clean	:
		@rm -f $(NAME)
fclean	:	clean
re	:	fclean all
.PHONY	:	all clean fclean re 
