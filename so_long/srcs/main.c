/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:02:22 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/24 14:43:50 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    window(void *mlx)
{
    t_data  d_img;
    void    *img;
    //void    *mlx_win;

    mlx = mlx_init();
    d_img.img = mlx_new_image(mlx, 1920, 1080);
    //mlx_win = mlx_new_window(mlx, 500, 508, "so_long");
    d_img.addr = mlx_get_data_addr(d_img.img, &d_img.bits_per_pixel, &d_img.line_length,
								&d_img.endian);
    mlx_loop(mlx);

}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    void    *mlx;
    t_mapform   *mapcheck;
    
    mapcheck = malloc(sizeof(*mapcheck));
    if (mapcheck == NULL)
        return (-1);
    if (check_map(argv[1], mapcheck))
    {  
        ft_putstr_fd("error\n", 1);
        free(mapcheck);
        return (1);
    }
    window(mlx);
    free(mapcheck);
    return (0);
}