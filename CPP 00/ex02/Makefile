# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 13:50:50 by rcompain          #+#    #+#              #
#    Updated: 2026/04/16 16:00:22 by rcompain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	test
CC			= 	c++
CFLAGS		= 	-Wall -Wextra -Werror -std=c++98
RM			= 	rm -f
OBJ_DIR		= 	obj

# ——— Sources ——————————————————————————————————————————————————————————————— #
SRC			= Account.cpp \
			  tests.cpp

OBJ			= ${SRC:%.cpp=$(OBJ_DIR)/%.o}

# ——— Rules ————————————————————————————————————————————————————————————————— #
all: banner $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Project compiled successfully ✅"

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