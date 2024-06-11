/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:40:45 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/06/10 12:40:50 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define ARGC_ERR			"Invalid number of arguments"
# define INVALID_MAP_NAME	"Invalid map name"
# define INV_FILE			"Cannot open the file"
# define EMPTY_MAP			"Map cannot be empty!"
# define MAP_ERROR          "Invalid map"
# define ERR_PATH			"Map has no path in order to solve the game!"

# define ERR_MLX_PTR		"Error at mlx_ptr malloc"
# define ERR_WIN_PTR		"Error at win_ptr malloc"

# define SP_ERROR_WALL		"Invalid wall png"
# define SP_ERROR_FLOOR		"Invalid floor png"
# define SP_ERROR_COIN		"Invalid coin png"
# define SP_ERROR_EXIT		"Invalid exit png"
# define SP_ERROR_PLAYER	"Invalid player png"

# define ERR_MALLOC			"Malloc failed to allocate the memory"

# define WIN_MESSAGE		"You won!"
# define DEFEAT_MESSAGE     "You gave up..."

#endif
