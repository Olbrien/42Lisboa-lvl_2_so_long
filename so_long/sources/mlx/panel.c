/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 01:33:12 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 20:06:52 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_color	create_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	color_panel(t_list *list, void **img_ptr, t_color color, int x)
{
	int		y;
	int		bpp;
	int		line_size;
	int		endian;
	char	*pixels;

	pixels = mlx_get_data_addr(*img_ptr, &bpp,
			&line_size, &endian);
	if (!pixels)
		exit_error("mlx_get_data_addr error\n", list);
	y = 0;
	while (y < list->mlx.height)
	{
		x = 0;
		while (x < list->mlx.width)
		{
			pixels[(x * 4 + line_size * y) + 0] = color.b;
			pixels[(x * 4 + line_size * y) + 1] = color.g;
			pixels[(x * 4 + line_size * y) + 2] = color.r;
			pixels[(x * 4 + line_size * y) + 3] = color.a;
			x++;
		}
		y++;
	}
}

void	create_panel(t_list *list, void **img_ptr, t_color color)
{
	*img_ptr = mlx_new_image(list->mlx.mlx_ptr, list->mlx.width,
			list->mlx.height);
	if (!*img_ptr)
		exit_error("Could not initialize image\n", list);
	color_panel(list, img_ptr, color, 0);
}
