/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:48:46 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:48:48 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_check_new_tile(t_game *game)
{
	if (game->world[game->point.y][game->point.x] == 'E' && game->coins == 0)
	{
		ft_printf(WIN_MESSAGE);
		ft_destroy_game(game);
	}
	if (game->world[game->point.y][game->point.x] == 'C')
	{
		game->world[game->point.y][game->point.x] = '0';
		game->coins--;
	}
}

void	ft_old_player_tile(t_game *game)
{
	if (game->world[game->point.y][game->point.x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites.exit, SP_SIZE * game->point.x,
			SP_SIZE * game->point.y);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites.floor, SP_SIZE * game->point.x,
			SP_SIZE * game->point.y);
	}
}

void	ft_move_player(t_game *game, char movement, int direction)
{
	if (movement == '|')
	{
		if (game->world[game->point.y + direction][game->point.x] == '1')
			return ;
		ft_old_player_tile(game);
		game->point.y = game->point.y + direction;
	}
	if (movement == '-')
	{
		if (game->world[game->point.y][game->point.x + direction] == '1')
			return ;
		ft_old_player_tile(game);
		game->point.x = game->point.x + direction;
	}
	game->moves++;
	ft_printf("Number of movements: %d\n", game->moves);
	ft_check_new_tile(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprites.player, SP_SIZE * game->point.x, SP_SIZE * game->point.y);
}
