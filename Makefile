NAME=cub3D
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
LDFLAGS=-Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm -lbsd
SRC_DIR=src
OBJ_DIR=obj
MLX_DIR = mlx
MLX = $(MLX_DIR)/mlx_linux.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = -Iinclude -Ilibft
all: $(NAME)
$(NAME): $(LIBFT) $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
