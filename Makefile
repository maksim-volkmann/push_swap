# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goldman <goldman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:31:03 by mvolkman          #+#    #+#              #
#    Updated: 2024/04/11 17:25:24 by goldman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Exclusive source files for push_swap
PUSH_SWAP_SRC = \
	push_swap.c \

# Exclusive source files for checker
CHECKER_SRC = \
	bonus/bonus_checker.c \

# Shared source files between push_swap and checker
SHARED_SRC = \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	process_and_init.c \
	utility.c \
	get_and_assign_index.c \
	small_sort.c \
	big_sort.c \
	clean_up.c \

# Object files
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
SHARED_OBJ = $(SHARED_SRC:.c=.o)

# Library directories and flags for libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories for libft
INCLUDES = -I$(LIBFT_DIR)/include \
			-I./include

# Output executable name
NAME = push_swap
BONUS_NAME = checker

# Colors used for terminal output.
GREEN = \033[0;32m
BLUE = \033[0;34m
ORANGE = \033[38;5;214m
RED = \033[0;31m
YELLOW = \033[0;33m
WHITE = \033[0;37m

# Rules
all: $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(WHITE)"

$(NAME): $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(LIBFT)
	@echo "$(BLUE)Building $(NAME)$(WHITE)"
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)$(NAME) created successfully!$(WHITE)"

$(LIBFT):
	@echo "$(BLUE)Building $(LIBFT)$(WHITE)"
	make -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) compiled successfully!$(WHITE)"
	
$(BONUS_NAME): $(CHECKER_OBJ) $(SHARED_OBJ) $(LIBFT)
	@echo "$(BLUE)Building $(BONUS_NAME)$(WHITE)"
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(CHECKER_OBJ) $(SHARED_OBJ) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)$(BONUS_NAME) created successfully!$(WHITE)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "$(GREEN)Compiled $< successfully!$(WHITE)"

clean:
	@echo "$(RED)Cleaning object files...$(WHITE)"
	rm -f $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(SHARED_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning binaries...$(WHITE)"
	rm -f $(NAME) $(BONUS_NAME)
	@if [ -d "42Barcelona-PushSwap-ProChecker" ]; then \
		echo "$(ORANGE)Deleting visualizer folder...$(WHITE)"; \
		rm -rf 42Barcelona-PushSwap-ProChecker; \
	fi
	@if [ -f "pro_checker" ]; then \
		echo "$(ORANGE)Deleting pro_checker binary...$(WHITE)"; \
		rm -f pro_checker; \
	fi
	make -C $(LIBFT_DIR) fclean


re: fclean all

# Downloading and building visualizer
v:
	@if [ ! -d "42Barcelona-PushSwap-ProChecker" ]; then \
		echo "$(YELLOW)Downloading visualizer...$(WHITE)"; \
		git clone --recursive https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker.git; \
	else \
		echo "$(YELLOW)Visualizer already downloaded.$(WHITE)"; \
	fi
	@if [ ! -f "pro_checker" ]; then \
		echo "$(BLUE)Building visualizer...$(WHITE)"; \
		cd 42Barcelona-PushSwap-ProChecker && make; \
		if [ -f "pro_checker" ]; then \
			echo "$(YELLOW)Moving pro_checker...$(WHITE)"; \
			mv pro_checker ../pro_checker; \
		else \
			echo "$(RED)Error: pro_checker not found after building visualizer.$(WHITE)"; \
		fi; \
	else \
		echo "$(YELLOW)pro_checker already exists in destination.$(WHITE)"; \
	fi
	@echo "$(YELLOW)Returning to parent directory...$(WHITE)"
	cd ..
	@echo "$(BLUE)Commands to run visualizer with random numbers:$(WHITE)"
	@echo "$(WHITE)🐸	ARG=\$$(ruby -e \"puts (0..500).to_a.shuffle.join(' ')\"); ./push_swap \$${ARG} | ./pro_checker \$${ARG}	🐸"

# Cleaning visualizer
vclean:
	@echo "$(RED)Cleaning visualizer...$(WHITE)"
	@if [ -d "42Barcelona-PushSwap-ProChecker" ]; then \
		echo "$(ORANGE)Deleting visualizer folder...$(WHITE)"; \
		rm -rf 42Barcelona-PushSwap-ProChecker; \
	fi
	@if [ -f "pro_checker" ]; then \
		echo "$(ORANGE)Deleting pro_checker binary...$(WHITE)"; \
		rm -f pro_checker; \
	fi

.PHONY: all clean fclean re v vclean bonus


# # Compiler and flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# # Exclusive source files for push_swap
# PUSH_SWAP_SRC = \
# 	push_swap.c \

# # Exclusive source files for checker
# CHECKER_SRC = \
# 	bonus/bonus_checker.c \

# # Shared source files between push_swap and checker
# SHARED_SRC = \
# 	swap.c \
# 	push.c \
# 	rotate.c \
# 	reverse_rotate.c \
# 	process_and_init.c \
# 	utility.c \
# 	get_and_assign_index.c \
# 	small_sort.c \
# 	big_sort.c \
# 	clean_up.c \

# # Object files
# PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
# CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
# SHARED_OBJ = $(SHARED_SRC:.c=.o)

# # Library directories and flags for libft
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# # Include directories for libft
# INCLUDES = -I$(LIBFT_DIR)/include \
# 			-I./include

# # Output executable name
# NAME = push_swap
# BONUS_NAME = checker

# # Colors used for terminal output.
# GREEN = \033[0;32m
# BLUE = \033[0;34m
# ORANGE = \033[38;5;214m
# RED = \033[0;31m
# YELLOW = \033[0;33m
# WHITE = \033[0;37m

# # Rules
# all: $(NAME)
# 	@echo "$(GREEN)$(NAME) compiled successfully!$(WHITE)"

# # $(NAME): $(OBJ) $(LIBFT)
# $(NAME): $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(LIBFT)
# 	@echo "$(BLUE)Building $(NAME)$(WHITE)"
# # $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) -Iinclude
# 	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(LIBFT) $(INCLUDES)
# 	@echo "$(GREEN)$(NAME) created successfully!$(WHITE)"

# $(LIBFT):
# 	@echo "$(BLUE)Building $(LIBFT)$(WHITE)"
# 	make -C $(LIBFT_DIR)

# bonus: $(BONUS_NAME)
# 	@echo "$(GREEN)$(BONUS_NAME) compiled successfully!$(WHITE)"
	
# # $(BONUS_NAME): $(OBJ) $(BONUS_OBJ) $(LIBFT)
# $(BONUS_NAME): $(CHECKER_OBJ) $(SHARED_OBJ) $(LIBFT)
# 	@echo "$(BLUE)Building $(BONUS_NAME)$(WHITE)"
# #$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) $(LIBFT) -Iinclude
# $(CC) $(CFLAGS) -o $(BONUS_NAME) $(CHECKER_OBJ) $(SHARED_OBJ) $(LIBFT) $(INCLUDES)
# 	@echo "$(GREEN)$(BONUS_NAME) created successfully!$(WHITE)"

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
# 	@echo "$(GREEN)Compiled $< successfully!$(WHITE)"

# clean:
# 	@echo "$(RED)Cleaning object files...$(WHITE)"
# 	rm -f $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(SHARED_OBJ)
# 	make -C $(LIBFT_DIR) clean

# fclean: clean
# 	@echo "$(RED)Cleaning binaries...$(WHITE)"
# 	rm -f $(NAME) $(BONUS_NAME)
# 	@if [ -d "42Barcelona-PushSwap-ProChecker" ]; then \
# 		echo "$(ORANGE)Deleting visualizer folder...$(WHITE)"; \
# 		rm -rf 42Barcelona-PushSwap-ProChecker; \
# 	fi
# 	@if [ -f "pro_checker" ]; then \
# 		echo "$(ORANGE)Deleting pro_checker binary...$(WHITE)"; \
# 		rm -f pro_checker; \
# 	fi
# 	make -C $(LIBFT_DIR) fclean


# re: fclean all

# # Downloading and building visualizer
# v:
# 	@if [ ! -d "42Barcelona-PushSwap-ProChecker" ]; then \
# 		echo "$(YELLOW)Downloading visualizer...$(WHITE)"; \
# 		git clone --recursive https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker.git; \
# 	else \
# 		echo "$(YELLOW)Visualizer already downloaded.$(WHITE)"; \
# 	fi
# 	@if [ ! -f "pro_checker" ]; then \
# 		echo "$(BLUE)Building visualizer...$(WHITE)"; \
# 		cd 42Barcelona-PushSwap-ProChecker && make; \
# 		if [ -f "pro_checker" ]; then \
# 			echo "$(YELLOW)Moving pro_checker...$(WHITE)"; \
# 			mv pro_checker ../pro_checker; \
# 		else \
# 			echo "$(RED)Error: pro_checker not found after building visualizer.$(WHITE)"; \
# 		fi; \
# 	else \
# 		echo "$(YELLOW)pro_checker already exists in destination.$(WHITE)"; \
# 	fi
# 	@echo "$(YELLOW)Returning to parent directory...$(WHITE)"
# 	cd ..
# 	@echo "$(BLUE)Commands to run visualizer with random numbers:$(WHITE)"
# 	@echo "$(WHITE)🐸	ARG=\$$(ruby -e \"puts (0..500).to_a.shuffle.join(' ')\"); ./push_swap \$${ARG} | ./pro_checker \$${ARG}	🐸"

# # Cleaning visualizer
# vclean:
# 	@echo "$(RED)Cleaning visualizer...$(WHITE)"
# 	@if [ -d "42Barcelona-PushSwap-ProChecker" ]; then \
# 		echo "$(ORANGE)Deleting visualizer folder...$(WHITE)"; \
# 		rm -rf 42Barcelona-PushSwap-ProChecker; \
# 	fi
# 	@if [ -f "pro_checker" ]; then \
# 		echo "$(ORANGE)Deleting pro_checker binary...$(WHITE)"; \
# 		rm -f pro_checker; \
# 	fi

# .PHONY: all clean fclean re v vclean bonus