/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:52:24 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/20 09:11:50 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_right(t_data *g, int keycode, int x, int y)
{
	int	newblock;

	if (keycode == DROITE)
		g->direction = x + 1;
	else
		g->direction = x - 1;
	if (keycode == DROITE)
		newblock = g->pl.x + SIZE_BLOC;
	else
		newblock = g->pl.x - SIZE_BLOC;
	if (g->map[y][g->direction].type != '1')
	{
		g->score++;
		if (g->map[y][g->direction].type == 'C')
		{
			g->map[y][g->direction].type = '0';
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
	int	newblock;

	if (keycode == BAS)
		g->direction = y + 1;
	else
		g->direction = y - 1;
	if (keycode == BAS)
		newblock = g->pl.y + SIZE_BLOC;
	else
		newblock = g->pl.y - SIZE_BLOC;
	if (g->map[g->direction][x].type != '1')
	{
		g->score++;
		if (g->map[g->direction][x].type == 'C')
		{
			g->colectible--;
			g->map[g->direction][x].type = '0';
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
	g->elementx = (g->pl.x / (SIZE_BLOC));
	g->elementy = (g->pl.y / (SIZE_BLOC));
	get_image_direction(keycode, g);
	if (keycode == GAUCHE || keycode == DROITE)
	{
		left_right(g, keycode, g->elementx, g->elementy);
		if (g->map[g->elementy][g->direction].type != '1')
		{
			ft_putnbr_fd(g->score, 1);
			ft_putstr_fd("\n", 1);
		}
	}
	if (keycode == BAS || keycode == HAUT)
	{
		top_bottom(g, keycode, g->elementx, g->elementy);
		if (g->map[g->direction][g->elementx].type != '1')
		{
			ft_putnbr_fd(g->score, 1);
			ft_putstr_fd("\n", 1);
		}
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
