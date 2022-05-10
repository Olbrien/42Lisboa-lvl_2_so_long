/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:51 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 20:50:16 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tiles_type(t_list *list, int x, int y)
{
	if (list->tilemap[y][x].type == WALL)
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
							list->images.wall_01, x * IMG_SIZE , y * IMG_SIZE );

	if (list->tilemap[y][x].type == MAP_EXIT)
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
			list->images.door_01, x * IMG_SIZE, y * IMG_SIZE);

	if (list->tilemap[y][x].type == COLLECTIBLE)
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
			list->images.plant_01, x * IMG_SIZE, y * IMG_SIZE);

	if (list->tilemap[y][x].type == PLAYER_POSITION)
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
			list->images.player_01, x * IMG_SIZE, y * IMG_SIZE);

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
			render_tiles_type(list, x, y);
			x++;
		}
		y++;
	}
}
