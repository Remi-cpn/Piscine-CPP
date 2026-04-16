# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 13:50:50 by rcompain          #+#    #+#              #
#    Updated: 2026/04/16 09:31:13 by rcompain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	phonebook
CC			= 	c++
CFLAGS		= 	-Wall -Wextra -Werror -std=c++98
RM			= 	rm -f
OBJ_DIR		= 	obj

# ——— Sources ——————————————————————————————————————————————————————————————— #
SRC			= Phonebook.class.cpp \
			  main.cpp

OBJ			= ${SRC:%.cpp=$(OBJ_DIR)/%.o}

# ——— Rules ————————————————————————————————————————————————————————————————— #
all: banner $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BOLD) $(GREEN)\n         Project compiled successfully ✅$(RESET)\n"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# ——— Cleanup ——————————————————————————————————————————————————————————————— #
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re banner