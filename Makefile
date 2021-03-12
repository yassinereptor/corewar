NAME = cor
LIBFT_FILE = libft.a

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./includes/
LIBFT_INC = $(LIBFT_DIR)/
OBJ_DIR = ./obj

LFLAG = 

LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

HEADERS = $(INC_DIR)cor.h $(INC_DIR)op.h

SRC_FILES = cursor_related.c error_related.c let_the_game_begin.c little_to_big_endian.c main.c op.c parsing_related.c player_related.c tools_related.c vm_related.c

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))

CC = gcc
CFLAGS = -g #-Wall -Werror -Wextra
INC = -I $(INC_DIR) -I $(LIBFT_INC)

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all: lib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_SRC)
	@$(CC) $(OBJ_SRC) $(LIBFT) $(LFLAG) -o $(NAME)
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

lib:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all