NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LDFLAGS = -Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm -lbsd

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = mlx
LIBFT_DIR = libft
INCLUDE_DIR = include libft

MLX = $(MLX_DIR)/mlx_linux.a
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = $(LIBFT) $(MLX)

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

INC = $(addprefix -I, $(INCLUDE_DIR))

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "🔨 Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🛠️  Compiling $<..."
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@echo "📚 Building libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo "📚 Building MiniLibX..."
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "🧹 Cleaning object files..."
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@echo "🗑️  Removing $(NAME)..."
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

analyze:
	@echo "🔍 Running static analysis..."
	@which cppcheck > /dev/null 2>&1 && cppcheck --enable=all $(SRC_DIR)/*.c || echo "⚠️ cppcheck not installed"
	@which clang-tidy > /dev/null 2>&1 && clang-tidy $(SRC_DIR)/*.c -- $(INC) || echo "⚠️ clang-tidy not installed"

memcheck: $(NAME)
	@echo "🔎 Running Valgrind memory check..."
	valgrind --suppressions=mlx.supp --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) test_maps/valid_map.cub

-include $(DEP)

.PHONY: all clean fclean re analyze memcheck
