/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:02:22 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/02 11:26:24 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_blocs(t_bloc element, t_data  *game, int x, int y)
{
    int		img_width;
	int		img_height;
    
    if (element.type == '0')
        element.img = mlx_xpm_file_to_image(game->mlx, "./mur.xpm", &img_width, &img_height);
    if (element.type == '1')
        element.img = mlx_xpm_file_to_image(game->mlx, "./mur.xpm", &img_width, &img_height);
    if (element.type == 'P')
        element.img = mlx_xpm_file_to_image(game->mlx, "./mur.xpm", &img_width, &img_height);
    if (element.type == 'C')
        element.img = mlx_xpm_file_to_image(game->mlx, "./objectif.xpm", &img_width, &img_height);
    if (element.type == 'E')
        element.img = mlx_xpm_file_to_image(game->mlx, "./mur.xpm", &img_width, &img_height);
    mlx_put_image_to_window(game->mlx, game->win, element.img, x, y);
}

void map_parsing(t_mapform *mapcheck, t_bloc **mapgame, t_data  *game)
{
    int x;
    int y;
    int cx;
    int cy;

    y = 0;
    cy = 0;
    while (y < mapcheck->height)
    {
        cx = - SIZE_BLOC;
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

int init_game(t_mapform *mapcheck)
{
    t_data  *game;
    
    game = malloc(sizeof(*game));
    if (game == NULL)
        return (-1);
    game->mlx = mlx_init();
    game->width = mapcheck->width * SIZE_BLOC;
    game->height = mapcheck->height * SIZE_BLOC;
    game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
    game->img = mlx_new_image(game->mlx, game->width, game->height);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    if (get_tab(game, mapcheck))
        return (-1);
    map_parsing(mapcheck, game->map, game);
    mlx_loop(game->mlx);
    free(game);
    return (0);
}


int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    t_mapform   *mapcheck;
    
    mapcheck = malloc(sizeof(*mapcheck));
    if (mapcheck == NULL)
        return (-1);
    if (check_map(argv[1], mapcheck))
    {  
        ft_putstr_fd("error\n", 1);
        free_map(mapcheck);
        free(mapcheck);
        return (1);
    }
    if (mapcheck == NULL)
        return (-1);
    init_game(mapcheck);
    free_map(mapcheck);
    free(mapcheck);
    return (0);
}