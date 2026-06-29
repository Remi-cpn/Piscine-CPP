# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 13:50:50 by rcompain          #+#    #+#              #
#    Updated: 2026/06/29 10:09:20 by rcompain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	Span
CC			= 	c++
CFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -g
RM			= 	rm -f
OBJ_DIR		= 	obj

# ——— Sources ——————————————————————————————————————————————————————————————— #
SRC			= main.cpp \
			  Span.cpp

OBJ			= ${SRC:%.cpp=$(OBJ_DIR)/%.o}

# ——— Rules ————————————————————————————————————————————————————————————————— #
all: $(NAME)

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
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re