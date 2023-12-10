/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:12:08 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/10 07:54:17 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../../libs/libft/includes/libft.h"
# include "../../libs/mlx/mlx.h"
# include "key_constants.h"

typedef struct s_player
{
	void	*img;
	int		x;
	int		y;
    int		amount;
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
	void		*map_img;
    int			map_width;
    int			map_height;
	t_player	player;
	t_block		collectible;
	t_block		exit;
	int			enimies;
	int			move_count;
	char		*moves_text;
}	t_game;

// UTILS
int	error(void);

// HOOKS
int	close_hook(t_game *game);
int	key_hook(int keycode, t_game *game);

// MAP PARSER
int	check_map(char *map_path, t_game *game);

#endif