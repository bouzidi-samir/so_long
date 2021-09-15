/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:44:49 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/14 12:55:06 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_blocs(t_bloc element, t_data *game, int x, int y)
{
	int	w;
	int	h;

	element.img = mlx_xpm_file_to_image(game->mlx, game->path.vide, &w, &h);
	game->fond = element;
	mlx_put_image_to_window(game->mlx, game->win, element.img, x, y);
	if (element.type == '1')
		element.img = mlx_xpm_file_to_image(game->mlx, game->path.mur, &w, &h);
	if (element.type == 'P')
	{
		element.img = mlx_xpm_file_to_image(game->mlx, game->path.play, &w, &h);
		game->player = element;
	}
	if (element.type == 'C')
		element.img = mlx_xpm_file_to_image(game->mlx, game->path.obj, &w, &h);
	if (element.type == 'E')
	{
		element.img = mlx_xpm_file_to_image(game->mlx, game->path.exit, &w, &h);
		game->exit_img = element.img;
	}
	mlx_put_image_to_window(game->mlx, game->win, element.img, x, y);
}

void	map_parsing(t_mapform *mapcheck, t_bloc **mapgame, t_data *game)
{
	int	x;
	int	y;
	int	cx;
	int	cy;

	y = 0;
	cy = 0;
	while (y < mapcheck->height)
	{
		cx = -SIZE_BLOC;
		x = 0;
		while (x < mapcheck->width)
		{
			cx += SIZE_BLOC;
			mapgame[y][x].type = mapcheck->map[y][x];
			mapgame[y][x].x = cx;
			mapgame[y][x].y = cy;
			put_blocs(mapgame[y][x], game, cx, cy);
			x++;
		}
		cy += SIZE_BLOC;
		y++;
	}
}
