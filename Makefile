NAME= pipex.a
SRC= ./srcs/search_path.c ./srcs/utils.c ./pipex.c
FLAGS= gcc -Wextra -Werror -Wall
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@clear
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"
	@make -sC ./libft/
	@make bonus -sC ./libft/
	@cp libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@$(FLAGS) $(SRC) libft.a -o pipex

all: $(NAME)

clean:
	@clear
	@echo "\n\033[36m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"
	@rm -f $(NAME) $(OBJ)
	@make -sC ./libft/ fclean

fclean: clean
		@rm -rf libft.a
		@rm -rf pipex

re: fclean all

.PHONY: all clean re run