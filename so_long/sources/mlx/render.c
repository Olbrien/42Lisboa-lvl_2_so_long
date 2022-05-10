/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:51 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 21:42:15 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_animations(t_list *list, int frames)
{
	(void)list;
	(void)frames;
}

void	render_tiles(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].image != NULL)
				mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
						list->tilemap[y][x].image, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
}
