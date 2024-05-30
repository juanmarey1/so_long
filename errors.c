/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:47:30 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:47:32 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
