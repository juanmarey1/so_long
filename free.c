/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:47:46 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:47:47 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (game->map_line)
		free(game->map_line);
	i = 0;
	if (game->world)
	{
		while (game->world[i])
		{
			free(game->world[i]);
			i++;
		}
		free(game->world);
	}
	i = 0;
	if (game->world_cpy)
	{
		while (game->world_cpy[i] != NULL)
		{
			free(game->world_cpy[i]);
			i++;
		}
		free(game->world_cpy);
	}
}

void	ft_free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_destroy_sprites(t_game *game)
{
	if (game->sprites.player)
		mlx_destroy_image(game->mlx_ptr, game->sprites.player);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx_ptr, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx_ptr, game->sprites.floor);
	if (game->sprites.coin)
		mlx_destroy_image(game->mlx_ptr, game->sprites.coin);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx_ptr, game->sprites.exit);
}

void	ft_free_game(t_game *game)
{
	ft_destroy_sprites(game);
	if (game->world)
		ft_free_double_array(game->world);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

int	ft_destroy_game(t_game *game)
{
	ft_free_game(game);
	if (game->win == 0)
		printf(DEFEAT_MESSAGE);
	exit (0);
	return (0);
}
