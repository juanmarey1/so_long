/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:49:41 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:49:42 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	put_images_on_window(t_game *game, int j)
{
	int	i;

	while (++j < game->line)
	{
		i = -1;
		while (++i < game->col)
		{
			if (game->world[j][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites.wall, SP_SIZE * i, SP_SIZE * j);
			else if (game->world[j][i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites.coin, SP_SIZE * i, SP_SIZE * j);
			else if (game->world[j][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites.exit, SP_SIZE * i, SP_SIZE * j);
			else if (game->world[j][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites.player, SP_SIZE * i, SP_SIZE * j);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites.floor, SP_SIZE * i, SP_SIZE * j);
		}
	}
}

void	convert_xpm_to_images(t_game *game, int size)
{
	int	j;

	j = -1;
	game->sprites.player = mlx_xpm_file_to_image(
			game->mlx_ptr, PLAYER_SP, &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(
			game->mlx_ptr, WALL_SP, &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(
			game->mlx_ptr, FLOOR_SP, &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(
			game->mlx_ptr, EXIT_SP, &size, &size);
	game->sprites.coin = mlx_xpm_file_to_image(
			game->mlx_ptr, COIN_SP, &size, &size);
	if (!game->sprites.floor)
		ft_error_game(SP_ERROR_FLOOR, game);
	if (!game->sprites.player)
		ft_error_game(SP_ERROR_PLAYER, game);
	if (!game->sprites.wall)
		ft_error_game(SP_ERROR_WALL, game);
	if (!game->sprites.exit)
		ft_error_game(SP_ERROR_EXIT, game);
	if (!game->sprites.coin)
		ft_error_game(SP_ERROR_COIN, game);
	put_images_on_window(game, j);
}
