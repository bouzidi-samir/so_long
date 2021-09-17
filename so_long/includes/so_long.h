/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:48 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/17 10:04:34 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE_BLOC 33
# define GAUCHE 0
# define DROITE 2
# define HAUT 13
# define BAS 1

# include "so_long.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

typedef struct s_mapform
{
	char	**map;
	char	*characters;
	int		height;
	int		width;
	char	*top;
	char	*bottom;
	int		player;
	int		colectible;
	int		exit;
	char	*error_message;
	int		error;
}	t_mapform;

typedef struct s_bloc
{
	void	*img;
	char	type;
	int		x;
	int		y;
}	t_bloc;

typedef struct s_path
{
	char	*vide;
	char	*mur;
	char	*play;
	char	*obj;
	char	*exit;
}	t_path;

typedef struct s_data
{
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	void			*img;
	void			*exit_img;
	int				end;
	char			touch;
	struct s_path	path;
	struct s_bloc	**map;
	struct s_bloc	player;
	struct s_bloc	fond;
	int				colectible;
	int				score;
}	t_data;

int		init_map(char *file, t_mapform *mapcheck);
int		check_map(char *file, t_mapform *mapcheck);
int		count_lines(char *file);
int		fill_map(char *file, t_mapform *mapcheck);
void	free_map(t_mapform *mapcheck);
int		check_characters(t_mapform *mapcheck);
int		check_square(t_mapform *mapcheck);
int		check_wall(t_mapform *mapcheck);
int		init_game(t_mapform *mapcheck, t_data *game);
void	map_parsing(t_mapform *mapcheck, t_bloc **mapgame, t_data *game);
int		get_tab(t_data *game, t_mapform *mapcheck);
void	put_blocs(t_bloc element, t_data *game, int x, int y);
int		moove_player(int keycode, t_data *game);
void	free_tab(t_data *game);
void	left_right(t_data *game, int keycode, int x, int y);
void	top_bottom(t_data *game, int keycode, int x, int y);
int		end_game(t_data *game);
int	check_victory(t_data *game);
void	get_image_direction(int keycode, t_data *game);
int	key_release(int keycode, t_data *game);

#endif
