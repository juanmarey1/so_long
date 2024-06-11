NAME = so_long #NOMBRE EJECUTABLE

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

LIBFT_DIR = libft #NOMBRES DIRECTORIOS CON MAKEFILE
MLX_DIR = mlx
INC_DIR = inc

SOURCES = errors.c free.c game.c main.c map_making.c map_path.c sprites.c player_movement.c 
OBJECTS = $(SOURCES:.c=.o)

INCLUDE = -I inc -I libft -I mlx #-I BUSCA LAS LIBRERÍAS EN LAS CARPETAS SELECCIONADAS

LIBFT = $(LIBFT_DIR)/libft.a
LIBRARY = -L $(LIBFT_DIR) -L $(MLX_DIR) -lft -lmlx -lXext -lX11

%.o: %.c #It tells make how to build a .o from a .c (It is a prerequisite to have a .c to create a .o)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS) maker #Hace objetos, mlx y libft. Después lo compila y lo pasa todo a objetos creando el ejecutable so_long
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) $(LIBRARY) -o $(NAME)
	@echo "$(NAME) created"

maker:
	@make -C mlx
	@make -C libft

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJECTS)
	@echo "Objects removed"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

run: all clean

.PHONY: all clean fclean re run maker