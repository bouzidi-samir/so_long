/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:44:49 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/19 14:02:52 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image_direction(int keycode, t_data *g)
{
	int	h;
	int	w;

	if (keycode == GAUCHE)
	{
		g->path.pla = "img/mario_gauche1.xpm";
		g->pl.im = mlx_xpm_file_to_image(g->mlx, g->path.pla, &w, &h);
	}
	if (keycode == DROITE)
	{
		g->path.pla = "img/mario_droite1.xpm";
		g->pl.im = mlx_xpm_file_to_image(g->mlx, g->path.pla, &w, &h);
	}
	if (keycode == BAS)
	{
		g->path.pla = "img/mario_bas1.xpm";
		g->pl.im = mlx_xpm_file_to_image(g->mlx, g->path.pla, &w, &h);
	}
	if (keycode == HAUT)
	{
		g->path.pla = "img/mario_haut1.xpm";
		g->pl.im = mlx_xpm_file_to_image(g->mlx, g->path.pla, &w, &h);
	}
}

void	put_blocs(t_bloc element, t_data *g, int x, int y)
{
	int	w;
	int	h;

	element.im = mlx_xpm_file_to_image(g->mlx, g->path.vide, &w, &h);
	g->fo = element;
	mlx_put_image_to_window(g->mlx, g->win, element.im, x, y);
	if (element.type == '1')
		element.im = mlx_xpm_file_to_image(g->mlx, g->path.mur, &w, &h);
	if (element.type == 'P')
	{
		element.im = mlx_xpm_file_to_image(g->mlx, g->path.pla, &w, &h);
		g->pl = element;
	}
	if (element.type == 'C')
		element.im = mlx_xpm_file_to_image(g->mlx, g->path.obj, &w, &h);
	if (element.type == 'E')
	{
		element.im = mlx_xpm_file_to_image(g->mlx, g->path.exit, &w, &h);
		g->eximg = element.im;
	}
	mlx_put_image_to_window(g->mlx, g->win, element.im, x, y);
}

void	map_parsing(t_mapform *mapcheck, t_bloc **mapgame, t_data *g)
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
			put_blocs(mapgame[y][x], g, cx, cy);
			x++;
		}
		cy += SIZE_BLOC;
		y++;
	}
}
