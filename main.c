/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:48:05 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/05/30 21:48:07 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	check_parameters(int n, char **args, t_game *game)
{
	int		i;
	int		len;
	char	*map_name;

	i = 0;
	if (n != 2)
		ft_error_map(ARGC_ERR, game);
	map_name = args[1];
	len = ft_strlen(args[1]);
	while (i < len - 4)
	{
		i++;
		map_name++;
	}
	if (len < 5 || ft_strncmp(map_name, ".ber", 4) != 0)
		ft_error_map(INVALID_MAP_NAME, game);
}

void	ft_init_parameters(t_game *game)
{
	game->map_line = NULL;
	game->world = NULL;
	game->world_cpy = NULL;
	game->coins = 0;
	game->exit = 0;
	game->initial = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->sprites.wall = NULL;
	game->sprites.floor = NULL;
	game->sprites.coin = NULL;
	game->sprites.player = NULL;
	game->sprites.exit = NULL;
	game->moves = 0;
}

void	ft_init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_game(ERR_MLX_PTR, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->col * SP_SIZE,
			game->line * SP_SIZE, "So_long");
	if (!game->win_ptr)
		ft_error_game(ERR_WIN_PTR, game);
}

void	run_game(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, ft_key, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, ft_destroy_game, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	system("leaks -q");
	ft_init_parameters(&game);
	check_parameters(argc, argv, &game);
	map_line_making(&game, argv[1]);
	ft_init_game(&game);
	convert_xpm_to_images(&game, SP_SIZE);
	run_game(&game);
	return (0);
}
