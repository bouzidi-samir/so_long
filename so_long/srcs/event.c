/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:52:24 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/16 22:00:36 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_right(t_data *game, int keycode, int x, int y)
{
	int	direction;
	int	newblock;
	
	if (keycode == DROITE)
		direction = x + 1;
	else
		direction = x - 1;
	if (keycode == DROITE)	
		newblock = game->player.x + SIZE_BLOC;
	else
		newblock = game->player.x - SIZE_BLOC;
	if (game->map[y][direction].type != '1')
	{
		if (game->map[y][direction].type == 'C')
		{
			game->map[y][direction].type = '0';
			game->colectible--;
		}
		if (game->map[y][x].type == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit_img, game->player.x, game->player.y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->fond.img, game->player.x, game->player.y);
		game->player.x = newblock;
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y);
	}
}

void	top_bottom(t_data *game, int keycode, int x, int y)
{
	int	direction;
	int	newblock;
	
	if (keycode == BAS)
		direction = y + 1;
	else 
		direction = y - 1;
	if (keycode == BAS)
		newblock = game->player.y + SIZE_BLOC;
	else
		newblock = game->player.y - SIZE_BLOC;
	if (game->map[direction][x].type != '1')
	{
		if (game->map[direction][x].type == 'C')
		{
			game->colectible--;
			game->map[direction][x].type = '0';
		}
		if (game->map[y][x].type == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit_img, game->player.x, game->player.y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->fond.img, game->player.x, game->player.y);
		game->player.y = newblock;
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y);
	}
}

int	moove_player(int keycode, t_data *game)
{
	int	x;
	int	y;
	
	x = (game->player.x / (SIZE_BLOC));
	y = (game->player.y / (SIZE_BLOC));
	get_image_direction(keycode, game);
	if (keycode == GAUCHE || keycode == DROITE)
		left_right(game, keycode, x, y);
	if (keycode == BAS || keycode == HAUT)
		top_bottom(game, keycode, x, y);
	if (keycode == 53)
		end_game(game);
	return (0);
}

int	key_release(int keycode, t_data *game)
{
	int	x;
	int	y;
	int	k;
	
	k = keycode;
	x = (game->player.x / (SIZE_BLOC));
	y = (game->player.y / (SIZE_BLOC));
	if (game->map[y][x].type == 'E' && game->colectible == 0)
		end_game(game);
	return (0);
}