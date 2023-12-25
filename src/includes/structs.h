/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:55:04 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 02:41:52 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		available;
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
	int			wall_error;
	t_player	player;
	t_block		collectible;
	t_block		exit;
	char		door_valid;
	t_block		vilan;
	int			move_count;
	char		*moves_text;
}	t_game;
