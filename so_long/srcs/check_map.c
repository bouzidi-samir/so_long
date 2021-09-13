/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:33:43 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/13 12:04:44 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_map(char *file, t_mapform *mapcheck)
{
    int i;
    int fd;
    int size;   
    
    i = 0;
    size = ft_strlen(file) - 1;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (1);
    if (file[size] != 'r' || file[size - 1] != 'e')
        return (1);
    if (file[size - 2] != 'b' || file[size - 3] != '.')
          return (1);
    while (i <= mapcheck->height - 1)
    {
        get_next_line(fd, &mapcheck->map[i]);
        i++;
    }
    mapcheck->top = mapcheck->map[0];
    mapcheck->bottom = mapcheck->map[i - 1];
    close(fd);
    return (0);
}

int check_characters(t_mapform *mapcheck)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i <= mapcheck->height - 1)
    {
        j = 0;
        while (mapcheck->map[i][j]!= '\0')
        {
            if (mapcheck->map[i][j] == 'P')
                mapcheck->player++;
            if (mapcheck->map[i][j] == 'C')
                mapcheck->colectible++;
            if (mapcheck->map[i][j] == 'E')
                mapcheck->exit++;           
            if (!ft_strchr(mapcheck->characters, (int)mapcheck->map[i][j]))    
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_square(t_mapform *mapcheck)
{
    int i;

    i = 0;
    mapcheck->width = ft_strlen(mapcheck->map[0]);
    while (i <= mapcheck->height -1)
    {
        if ((int)ft_strlen(mapcheck->map[i]) != mapcheck->width)
        {    
            ft_putstr_fd("The map must be rectangular\n", 2);
            return (1);
        }
        i++;
    }
    if (mapcheck->width == mapcheck->height)
    {
        ft_putstr_fd("The map must be rectangular\n", 2);
        return (1);
    }
    return (0);
}

int check_wall(t_mapform *mapcheck)
{
    int i;

    i = 0;
    while (mapcheck->top[i])
    {
        if (mapcheck->top[i] != '1' || mapcheck->bottom[i] != '1')
            return (1);
        i++;
    }
    i = 0;
    while (i <= mapcheck->height -1)
    {
        if (mapcheck->map[i][0] != '1')
            return (1);
        if (mapcheck->map[i][mapcheck->width -1] != '1')
            return (1);
        i++;
    }   
    return (0); 
}

int check_map(char *file, t_mapform *mapcheck)
{
    init_map(file, mapcheck);
    if (fill_map(file, mapcheck))
    {
        mapcheck->error_message = "The map description must be a file with the .ber extension\n";
        return (1);
    }
    if (check_characters(mapcheck))
    {   
        mapcheck->error_message = "The map must be composed of only 5 possible characters : 0, 1, C, E or P\n";
        return (1);
    }
    if (check_square(mapcheck))
        return (1);
    if (check_wall(mapcheck))
    {
        mapcheck->error_message = "The map must be closed/surrounded by walls\n";
        return (1);
    }
    if (mapcheck->player != 1 || !mapcheck->colectible || !mapcheck->exit)
    {
        mapcheck->error_message = "The map must have at least one exit, one collectible, and one starting position\n";
        return (1); 
    }
    return (0);
}