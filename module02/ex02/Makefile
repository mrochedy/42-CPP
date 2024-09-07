NAME = a.out

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = objs

SRCS =	main.cpp Fixed.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# ANSI color codes
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[1;97m
BLUE = \033[1;34m
CYAN = \033[1;36m
RED = \033[1;31m
RESET = \033[0m

COL1 = \033[38;2;255;204;153m # Orange pastel
COL2 = \033[38;2;255;214;140m # Orange clair pastel
COL3 = \033[38;2;255;224;128m # Orange-jaune pastel
COL4 = \033[38;2;255;234;115m # Jaune-orangé pastel
COL5 = \033[38;2;255;244;102m # Jaune clair pastel
COL6 = \033[38;2;255;255;153m # Jaune pastel

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@printf "$(GREEN)Compilation complete!$(RESET)\n"
	@printf "\n$(COL1)███████╗██╗  ██╗ ██████╗ ██████╗ \n"
	@printf "$(COL2)██╔════╝╚██╗██╔╝██╔═████╗╚════██╗\n"
	@printf "$(COL3)█████╗   ╚███╔╝ ██║██╔██║ █████╔╝\n"
	@printf "$(COL4)██╔══╝   ██╔██╗ ████╔╝██║██╔═══╝ \n"
	@printf "$(COL5)███████╗██╔╝ ██╗╚██████╔╝███████╗\n"
	@printf "$(COL6)╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝$(RESET)\n\n"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)Cleaned object files.$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)Removed executable.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
