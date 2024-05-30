#include "inc/so_long.h"

void	check_path(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->world_cpy[j] != NULL)
	{
		i = 0;
		while (game->world_cpy[j][i])
		{
			if (game->world_cpy[j][i] != '1' && game->world_cpy[j][i] != 'A')
				ft_error_map(ERR_PATH, game);
			i++;
		}
		j++;
	}
}

void	ft_floodfill(char **world, t_game *game, int x, int y)
{
	if ((x < 0 || x >= game->col) || (y < 0 || y >= game->line))
		return ;
	if (world[y][x] == 'A' || world[y][x] == '1')
		return ;
	world[y][x] = 'A';

	ft_floodfill(world, game, x + 1, y);
	ft_floodfill(world, game, x, y + 1);
	ft_floodfill(world, game, x - 1, y);
	ft_floodfill(world, game, x, y - 1);
}

void	find_init_position(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->world[j] != NULL)
	{
		i = 0;
		while (game->world[j][i])
		{
			if (game->world[j][i] == 'P')
			{
				game->point.x = i;
				game->point.y = j;
			}
			i++;
		}
		j++;
	}
}

void	map_cpy(t_game *game)
{
	int	j;

	j = 0;
	game->world_cpy = (char **)malloc(sizeof(char *) * (game->line + 1));
	if (!(game->world_cpy))
		ft_error_map(ERR_MALLOC, game);
	find_init_position(game);
	while (game->world[j] != NULL)
	{
		game->world_cpy[j] = ft_strdup(game->world[j]);
		if (!(game->world_cpy[j]))
			ft_error_map(ERR_MALLOC, game);
		j++;
	}
	game->world_cpy[j] = NULL;
	ft_floodfill(game->world_cpy, game, game->point.x, game->point.y);
	check_path(game);
}