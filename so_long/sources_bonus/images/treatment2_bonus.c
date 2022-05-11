/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:13:21 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 03:27:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_player_images(t_list *list)
{
	int	width;
	int	height;

	list->images.player_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLAYER_01,
			&width, &height);
	if (list->images.player_01 == NULL)
		exit_error("Could not load image player_01\n", list);
	list->images.player_02 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLAYER_02,
			&width, &height);
	if (list->images.player_02 == NULL)
		exit_error("Could not load image player_02\n", list);
}

void	open_wall_images(t_list *list)
{
	int	width;
	int	height;

	list->images.wall_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_01,
			&width, &height);
	if (list->images.wall_01 == NULL)
		exit_error("Could not load image wall_01\n", list);
}

void	fill_tilemap_with_images(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].type == WALL)
				list->tilemap[y][x].image = list->images.wall_01;
			else if (list->tilemap[y][x].type == MAP_EXIT)
				list->tilemap[y][x].image = list->images.door_01;
			else if (list->tilemap[y][x].type == COLLECTIBLE)
				list->tilemap[y][x].image = list->images.plant_01;
			else if (list->tilemap[y][x].type == PLAYER_POSITION)
				list->tilemap[y][x].image = list->images.player_01;
			else if (list->tilemap[y][x].type == ENEMY)
				list->tilemap[y][x].image = list->images.enemy_01;
			else
				list->tilemap[y][x].image = NULL;
			list->tilemap[y][x].image_number = 0;
			x++;
		}
		y++;
	}
}
