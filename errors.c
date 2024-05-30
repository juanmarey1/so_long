#include "inc/so_long.h"

void	ft_error_map(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_free_map(game);
	exit(1);
}

void	ft_error_game(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_free_game(game);
	exit(1);
}