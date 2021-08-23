/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:33:43 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/22 15:33:58 by samirbouzid      ###   ########.fr       */
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

void fill_map(char *file, t_mapform *mapcheck)
{
    int i;
    int fd;
    
    i = 0;
    fd = open(file, O_RDONLY);
    while (i <= mapcheck->height - 1)
    {
        get_next_line(fd, &mapcheck->map[i]);
        i++;
    }
    mapcheck->top = mapcheck->map[0];
    mapcheck->bottom = mapcheck->map[i - 1];
    close(fd);
}

int check_characters(t_mapform *mapcheck)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    mapcheck->characters = "01CEP";
    while (i <= mapcheck->height - 1)
    {
        j = 0;
        while (mapcheck->map[i][j]!= '\0')
        {
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
    mapcheck->map = malloc(sizeof(char*) * mapcheck->height);
    fill_map(file, mapcheck);
    if (check_characters(mapcheck))
        return (1);
    if (check_square(mapcheck))
        return (1);
    if (check_wall(mapcheck))
        return (1);
    if (mapcheck->error)
        return (1);
    free_map(mapcheck);
    return (0);
}