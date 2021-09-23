NAME	:=	phonebook
SRCS	:=	{wildcard *.cpp}
CC	:=	clang++ -Wall -Werror -Wextra

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
