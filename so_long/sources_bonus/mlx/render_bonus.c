/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:51 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 01:37:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_exit(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].type == MAP_EXIT)
			{
				list->tilemap[y][x].image = list->images.door_02;
			}
			x++;
		}
		y++;
	}
	list->map.collectibles = -1;
}

void	render_animations_plant(t_list *list, int x, int y)
{
	if (list->tilemap[y][x].image_number == 0)
	{
		list->tilemap[y][x].image_number = 1;
		list->tilemap[y][x].image = list->images.plant_02;
	}
	else
	{
		list->tilemap[y][x].image_number = 0;
		list->tilemap[y][x].image = list->images.plant_01;
	}
}

void	render_animations_player(t_list *list, int x, int y)
{
	if (list->tilemap[y][x].image_number == 0)
	{
		list->tilemap[y][x].image_number = 1;
		list->tilemap[y][x].image = list->images.player_02;
	}
	else
	{
		list->tilemap[y][x].image_number = 0;
		list->tilemap[y][x].image = list->images.player_01;
	}
}

void	render_animations(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].type == COLLECTIBLE)
				render_animations_plant(list, x, y);
			if (list->tilemap[y][x].type == PLAYER_POSITION)
				render_animations_player(list, x, y);
			x++;
		}
		y++;
	}
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
			if (list->tilemap[y][x].type == PLAYER_POSITION)
			{
				list->current_player_x = x;
				list->current_player_y = y;
			}
			x++;
		}
		y++;
	}
}
