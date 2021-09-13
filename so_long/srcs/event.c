/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:52:24 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/13 13:38:24 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void left_right(t_data *game, int keycode, int x, int y)
{
    int direction;
    int newblock; 
    
    if (keycode == 124)
    {
        direction = x + 1;
        newblock = game->player.x + SIZE_BLOC;
    }
    if (keycode == 123)
    {
        direction = x - 1;
        newblock = game->player.x - SIZE_BLOC;
    }
    if (game->map[y][direction].type != '1')
    {
         if (game->map[y][direction].type == 'C')
            game->colectible--; 
        if (game->map[y][x].type == 'E')
            mlx_put_image_to_window(game->mlx, game->win, game->exit_img, game->player.x, game->player.y);
        else
            mlx_put_image_to_window(game->mlx, game->win, game->fond.img, game->player.x, game->player.y);
            game->player.x = newblock;
        mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y);
    }
}

void top_bottom(t_data *game, int keycode, int x, int y)
{
    int direction;
    int newblock; 
    
    if (keycode == 125)
    {
        direction = y + 1;
        newblock = game->player.y + SIZE_BLOC;
    }
    if (keycode == 126)
    {
        direction = y - 1;
        newblock = game->player.y - SIZE_BLOC;
    }
    if (game->map[direction][x].type != '1')
    {
         if (game->map[direction][x].type == 'C')
            game->colectible--; 
        if (game->map[y][x].type == 'E')
            mlx_put_image_to_window(game->mlx, game->win, game->exit_img, game->player.x, game->player.y);
        else
            mlx_put_image_to_window(game->mlx, game->win, game->fond.img, game->player.x, game->player.y);
            game->player.y = newblock;
        mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y);
    }
}

int moove_player(int keycode, t_data *game)
{
    int x;
    int y;
        
    x = (game->player.x / (SIZE_BLOC));
    y = (game->player.y / (SIZE_BLOC));
    if (keycode == 123 || keycode == 124)
        left_right(game, keycode, x, y);
    if (keycode == 125 || keycode == 126)
        top_bottom(game, keycode, x, y);
    ft_putnbr_fd(game->colectible, 1);
    return (0);
}

int end_game(t_mapform *mapcheck, t_data *game)
{
    free_tab(mapcheck, game);
    free(game);
    free_map(mapcheck);
    free(mapcheck);
    return (0);
}