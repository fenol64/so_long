/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:12:08 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/28 02:40:42 by fnascime         ###   ########.fr       */
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
# include "structs.h"

// UTILS
void	ft_sleep(int seconds);
void	map_error(int error_code);
void	ft_putmatrix(char **matrix);
char	*ft_strjoin_free(char *s1, char *s2, int free_str);
int		ft_free_matrix(char **matrix);
size_t	ft_matrix_len(char **matrix);
int		error(void);

// HOOKS
void	free_game(t_game *game, int freelib);
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
void	atack_enemy(t_game *game);

// MAP VALIDATIONS
int		validade_extension(char *map_path);
int		validate_map(char *map, t_game *game);

// MAP PARSER
void	get_map_dimensions(char **map_str, t_game *game);
int		check_map(char *map_path, t_game *game);
void	render_map(t_game *game);

// UTILS
#endif