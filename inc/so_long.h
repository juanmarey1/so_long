#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "messages.h"
# include "../mlx/mlx.h"

# define WALL_SP	"./images/wall.xpm"
# define FLOOR_SP	"./images/floor.xpm"
# define PLAYER_SP	"./images/player.xpm"
# define EXIT_SP	"./images/exit.xpm"
# define COIN_SP	"./images/coin.xpm"

# ifndef SP_SIZE
#  define SP_SIZE 64
# endif

# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define ESC	65307

typedef struct  s_point {
	int	x;
	int	y;
}	t_point;

typedef struct  s_sprites {
	void	*wall;
	void	*floor;
	void	*coin;
	void	*player;
	void	*exit;
}	t_sprites;

typedef struct  s_game {
	int			fd;
	char		*map_line;
	char		**world;
	char		**world_cpy;
	int			col;
	int			line;
	int			coins;
	int			initial;
	int			exit;
	t_point		point;
	t_sprites	sprites;
	void		*mlx_ptr;
	void		*win_ptr;
	int			moves;
}	t_game;


void	map_line_making(t_game *game, char *map_name);
void	map_cpy(t_game *game);

void	convert_xpm_to_images(t_game *game, int size);

void	ft_error_map(char *str, t_game *game);
void	ft_error_game(char *str, t_game *game);

int		ft_key(int key, t_game *game);
void	ft_move_player(t_game *game, char movement, int direction);

void	ft_free_double_array(char **str);
void	ft_free_map(t_game *game);
int		ft_destroy_game(t_game *game);
void	ft_free_game(t_game *game);


#endif