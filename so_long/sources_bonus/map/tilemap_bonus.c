/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 04:06:18 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 03:16:43 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_tilemap_2(t_list *list, int y, int x)
{
	list->tilemap[y][x].type = list->map.map_splitted[y][x];
	list->tilemap[y][x].width = x;
	list->tilemap[y][x].height = y;
	if (y - 1 >= 0)
		list->tilemap[y][x].up = &list->tilemap[y - 1][x];
	else
		list->tilemap[y][x].up = NULL;
	if (y + 1 < list->map.height)
		list->tilemap[y][x].down = &list->tilemap[y + 1][x];
	else
		list->tilemap[y][x].down = NULL;
	if (x - 1 >= 0)
		list->tilemap[y][x].left = &list->tilemap[y][x - 1];
	else
		list->tilemap[y][x].left = NULL;
	if (x + 1 < list->map.width)
		list->tilemap[y][x].right = &list->tilemap[y][x + 1];
	else
		list->tilemap[y][x].right = NULL;
}

void	fill_tilemap(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			fill_tilemap_2(list, y, x);
			x++;
		}
		y++;
	}
}

void	allocate_memory(t_list *list)
{
	int	i;

	list->tilemap = malloc(sizeof(t_tilemap *) * list->map.height + 1);
	if (!list->tilemap)
		exit_error("Failed to allocate memory on the tilemap\n", list);
	i = 0;
	while (i < list->map.height)
	{
		list->tilemap[i] = malloc(sizeof(t_tilemap) * list->map.width + 1);
		if (!list->tilemap[i])
			exit_error("Failed to allocate memory on the tilemap\n", list);
		i++;
	}
}

void	tilemap_treatment(t_list *list)
{
	allocate_memory(list);
	fill_tilemap(list);
}
