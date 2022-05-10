/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 01:33:12 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 02:02:06 by tisantos         ###   ########.fr       */
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

void	color_panel(t_list *list, void **img_ptr, t_panel panel, t_color color)
{
	int	x;
	int	y;

	panel.pixels = mlx_get_data_addr(*img_ptr, &panel.bpp,
					&panel.line_size, &panel.endian);
	if (!panel.pixels)
		exit_error("mlx_get_data_addr error\n", list);
	y = 0;
	while (y < panel.y)
	{
		x = 0;
		while (x < panel.x)
		{
			panel.pixels[(x * 4 + panel.line_size * y) + 0] = color.b;
			panel.pixels[(x * 4 + panel.line_size * y) + 1] = color.g;
			panel.pixels[(x * 4 + panel.line_size * y) + 2] = color.r;
			panel.pixels[(x * 4 + panel.line_size * y) + 3] = color.a;
			x++;
		}
		y++;
	}
}

void	create_panel(t_list *list, void **img_ptr, t_color color)
{
	t_panel panel;

	*img_ptr = mlx_new_image(list->mlx.mlx_ptr, list->mlx.width, list->mlx.height);
	if (!*img_ptr)
		exit_error("Could not initialize image\n", list);

	panel.x = list->mlx.width;
	panel.y = list->mlx.height;

	color_panel(list, img_ptr, panel, color);
}
