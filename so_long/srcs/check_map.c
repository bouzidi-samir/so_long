/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:33:43 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/31 15:17:00 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  count_lines(char *file) 
{
    int fd;
    int count;
    int rcount;
    char    c;

    fd = open(file, O_RDONLY);
    if (!fd)
        return (-1);
    count = 1;
    while (1)
    {
        rcount = read(fd, &c, 1);
        if (rcount == 0)
            break ;
        if (rcount < 0)
            return (-1);
        if (c == '\n')
            count++;
    }
    close(fd);
    return (count);
}

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
   if (!mapcheck->player || !mapcheck->colectible || !mapcheck->exit)
        return (1);   
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
            return (1);
        i++;
    }
    if (mapcheck->width == mapcheck->height)
        return (1);
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
    mapcheck->error = 0;
    mapcheck->height = 0;
    mapcheck->height = count_lines(file); 
    mapcheck->characters = "01CEP";
    mapcheck->player = 0;
    mapcheck->colectible = 0;
    mapcheck->exit = 0;    
    mapcheck->map = malloc(sizeof(char*) * mapcheck->height);
    if (fill_map(file, mapcheck))
        return (1);
    if (check_characters(mapcheck))
        return (1);
    if (check_square(mapcheck))
        return (1);
    if (check_wall(mapcheck))
        return (1);
    if (mapcheck->error)
        return (1);
 //   free_map(mapcheck);
    return (0);
}