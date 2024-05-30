/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:48:20 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:48:21 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	map_check_interior(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->world[j])
	{
		i = 0;
		while (game->world[j][i])
		{
			if ((game->world[j][i] != 'C' && game->world[j][i] != 'E') &&
					(game->world[j][i] != 'P' && game->world[j][i] != '1') &&
						(game->world[j][i] != '0' && game->world[j][i] != '\n'))
				ft_error_map(INV_MAP_INTERIOR, game);
			if (game->world[j][i] == 'C')
				game->coins++;
			if (game->world[j][i] == 'E')
				game->exit++;
			if (game->world[j][i] == 'P')
				game->initial++;
			i++;
		}
		j++;
	}
	if ((game->coins == 0 || game->exit != 1) || game->initial != 1)
		ft_error_map(INV_MAP_INTERIOR, game);
}

void	map_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->col - 1)
	{
		if (game->world[0][i] != '1' || game->world[(game->line) - 1][i] != '1')
			ft_error_map(MAP_NO_WALLS, game);
		i++;
	}
	i = 0;
	while (i < game->line)
	{
		if (game->world[i][0] != '1' || game->world[i][(game->col) - 1] != '1')
			ft_error_map(MAP_NO_WALLS, game);
		i++;
	}
}

void	check_map_size(t_game *game)
{
	int	aux;
	int	i;

	i = -1;
	game->world = ft_split(game->map_line, '\n');
	while (game->world[++i])
	{
		if (game->world[i][ft_strlen(game->world[i]) - 1] == 13)
			game->world[i][ft_strlen(game->world[i]) - 1] = 0;
	}
	game->col = 0;
	aux = 0;
	game->line = 1;
	while (game->world[game->line] != NULL && game->world[0] != NULL)
	{
		aux = ft_strlen(game->world[game->line - 1]);
		game->col = ft_strlen(game->world[game->line]);
		if (game->col != aux)
			ft_error_map(MAP_NOT_RECT, game);
		game->line++;
	}
	if (game->line <= 2 || game->col <= 2)
		ft_error_map(MAP_TOO_SMALL, game);
	map_walls(game);
	map_check_interior(game);
}

void	map_line_making(t_game *game, char *map_name)
{
	char	*line;

	game->fd = open(map_name, O_RDONLY);
	if (game->fd < 0)
		ft_error_map(INV_FILE, game);
	line = get_next_line(game->fd);
	game->map_line = ft_strdup(line);
	while (line != NULL && line[0] != '\n')
	{
		free(line);
		line = get_next_line(game->fd);
		game->map_line = ft_strjoin(game->map_line, line);
	}
	free(line);
	if (game->map_line == NULL || game->map_line[0] == '\n')
		ft_error_map(EMPTY_MAP, game);
	close(game->fd);
	check_map_size(game);
	free(game->map_line);
	map_cpy(game);
	ft_free_double_array(game->world_cpy);
}
