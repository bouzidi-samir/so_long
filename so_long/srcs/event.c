/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:52:24 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/19 14:01:34 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_right(t_data *g, int keycode, int x, int y)
{
	int	direction;
	int	newblock;

	if (keycode == DROITE)
		direction = x + 1;
	else
		direction = x - 1;
	if (keycode == DROITE)
		newblock = g->pl.x + SIZE_BLOC;
	else
		newblock = g->pl.x - SIZE_BLOC;
	if (g->map[y][direction].type != '1')
	{
		if (g->map[y][direction].type == 'C')
		{
			g->map[y][direction].type = '0';
			g->colectible--;
		}
		if (g->map[y][x].type == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->eximg, g->pl.x, g->pl.y);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->fo.im, g->pl.x, g->pl.y);
		g->pl.x = newblock;
		mlx_put_image_to_window(g->mlx, g->win, g->pl.im, g->pl.x, g->pl.y);
	}
}

void	top_bottom(t_data *g, int keycode, int x, int y)
{
	int	direction;
	int	newblock;

	if (keycode == BAS)
		direction = y + 1;
	else
		direction = y - 1;
	if (keycode == BAS)
		newblock = g->pl.y + SIZE_BLOC;
	else
		newblock = g->pl.y - SIZE_BLOC;
	if (g->map[direction][x].type != '1')
	{
		if (g->map[direction][x].type == 'C')
		{
			g->colectible--;
			g->map[direction][x].type = '0';
		}
		if (g->map[y][x].type == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->eximg, g->pl.x, g->pl.y);
		else
			mlx_put_image_to_window(g->mlx, g->win, g->fo.im, g->pl.x, g->pl.y);
		g->pl.y = newblock;
		mlx_put_image_to_window(g->mlx, g->win, g->pl.im, g->pl.x, g->pl.y);
	}
}

int	moove_player(int keycode, t_data *g)
{
	int	x;
	int	y;

	x = (g->pl.x / (SIZE_BLOC));
	y = (g->pl.y / (SIZE_BLOC));
	get_image_direction(keycode, g);
	if (keycode == GAUCHE || keycode == DROITE)
	{
		g->score++;
		ft_putnbr_fd(g->score, 1);
		ft_putstr_fd("\n", 1);
		left_right(g, keycode, x, y);
	}
	if (keycode == BAS || keycode == HAUT)
	{
		g->score++;
		ft_putnbr_fd(g->score, 1);
		ft_putstr_fd("\n", 1);
		top_bottom(g, keycode, x, y);
	}
	if (keycode == 53)
		end_game(g);
	return (0);
}

int	key_release(int keycode, t_data *g)
{
	int	x;
	int	y;
	int	k;

	k = keycode;
	x = (g->pl.x / (SIZE_BLOC));
	y = (g->pl.y / (SIZE_BLOC));
	if (g->map[y][x].type == 'E' && g->colectible == 0)
		end_game(g);
	return (0);
}

int	destroy_window(t_data *g)
{
	end_game(g);
	return (0);
}
