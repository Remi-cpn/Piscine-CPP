# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 13:50:50 by rcompain          #+#    #+#              #
#    Updated: 2026/04/15 13:56:16 by rcompain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
OBJ_DIR		= obj

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC			= megaphone.cpp

OBJ			= ${SRC:%.c=$(OBJ_DIR)/%.o}

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: banner $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\r\033[2K$(CYAN)📝 Compiled project files: $(BOLD)$(GREEN)[OK]$(RESET)"
	@echo "$(BOLD) $(GREEN)\n         Project compiled successfully ✅$(RESET)\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[2K$(CYAN)📝 Compiled project files: %s$(RESET)" "$<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CYAN)Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re banner