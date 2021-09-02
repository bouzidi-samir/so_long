/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:44:49 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/30 18:49:54 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    window(t_data *image)
{
   char	*relative_path = "./mur.xpm";
	void    *img;
    int		img_width;
	int		img_height;    
    int x;
    int y;
    
    x = 0;
    y = 0;
    image->mlx = mlx_init();
    image->img = mlx_new_image(image->mlx, 344, 368);
    image->win = mlx_new_window(image->mlx, 344, 368, "so_long");
    img = mlx_xpm_file_to_image(image->mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(image->mlx, image->win, image->img, 0, 0);
    mlx_put_image_to_window(image->mlx, image->win, img, 0, 0);
    mlx_put_image_to_window(image->mlx, image->win, img, 31, 0);
    mlx_put_image_to_window(image->mlx, image->win, img, 0, 31);
    printf("%p", image->img);
    mlx_loop(image->mlx);

}
