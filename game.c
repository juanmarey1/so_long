/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:47:54 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:47:56 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_key(int key, t_game *game)
{
	if (key == ESC)
		ft_destroy_game(game);
	else if (key == W || key == UP)
		ft_move_player(game, '|', -1);
	else if (key == S || key == DOWN)
		ft_move_player(game, '|', 1);
	else if (key == A || key == LEFT)
		ft_move_player(game, '-', -1);
	else if (key == D || key == RIGHT)
		ft_move_player(game, '-', 1);
	return (0);
}
