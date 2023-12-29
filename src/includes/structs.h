/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:55:04 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/29 13:35:35 by fnascime         ###   ########.fr       */
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
	void	*frame_1;
	void	*frame_2;
	void	*frame_3;
	void	*frame_4;
	void	*frame_5;
	void	*frame_6;
	void	*frame_7;
	void	*frame_8;
	void	*frame_9;
	void	*frame_10;
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
	int			door_opened;
	t_block		vilan;
	int			move_count;
	char		*moves_text;
}	t_game;
