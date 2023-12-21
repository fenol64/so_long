/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:12:08 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/17 02:14:14 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../../libs/libft/includes/libft.h"
# include "../../libs/mlx/mlx.h"
# include "constants.h"

typedef struct s_player
{
	void	*img_up;
	void	*img_left;
	void	*img_right;
	void	*img_down;
	int		x;
	int		y;
	int		amount;
	char	direction;

}	t_player;

typedef struct s_block
{
	void	*img;
	int		amount;
}	t_block;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*floor_img;
	void		*wall_img;
	int			map_width;
	int			map_height;
	t_player	player;
	t_block		collectible;
	t_block		exit;
	t_block		vilan;
	int			move_count;
	char		*moves_text;
}	t_game;

// UTILS
int		error(void);

// HOOKS
int		close_hook(t_game *game);
int		key_hook(int keycode, t_game *game);

// IMAGE HANDLER
void	load_image(t_game *game, void **img_ptr, char *path);
int		load_images(t_game *game);
void	put_img(t_game *game, void *img_ptr, int x, int y);

// PLAYER MOVEMENT
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// MAP PARSER
int		check_map(char *map_path, t_game *game);
void	render_map(t_game *game);

#endif