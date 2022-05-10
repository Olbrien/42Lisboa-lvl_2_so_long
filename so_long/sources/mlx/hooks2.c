/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:18:23 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 00:35:22 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_moved(t_list *list)
{
	list->steps++;
	write (1, "steps: ", 8);
	ft_putnbr_fd(list->steps, 1);
	write (1, "\n", 1);
}

void	move_player_conf2(t_list *list, char key_pressed, int x, int y)
{
	if (key_pressed == 'D')
	{
		if (list->tilemap[y][x].right->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].right->type = PLAYER_POSITION;
		list->tilemap[y][x].right->image = list->tilemap[y][x].image;
		list->tilemap[y][x].right->image_number = list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	if (key_pressed == 'W')
	{
		if (list->tilemap[y][x].up->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].up->type = PLAYER_POSITION;
		list->tilemap[y][x].up->image = list->tilemap[y][x].image;
		list->tilemap[y][x].up->image_number = list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	list->tilemap[y][x].type = EMPTY_SPACE;
	list->tilemap[y][x].image = NULL;
}

void	move_player_conf(t_list *list, char key_pressed, int x, int y)
{
	if (key_pressed == 'A')
	{
		if (list->tilemap[y][x].left->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].left->type = PLAYER_POSITION;
		list->tilemap[y][x].left->image = list->tilemap[y][x].image;
		list->tilemap[y][x].left->image_number = list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	if (key_pressed == 'S')
	{
		if (list->tilemap[y][x].down->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].down->type = PLAYER_POSITION;
		list->tilemap[y][x].down->image = list->tilemap[y][x].image;
		list->tilemap[y][x].down->image_number = list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}

	move_player_conf2(list, key_pressed, x, y);
}

void	move_player2(t_list *list, char key_pressed, int x, int y)
{
	if (key_pressed == 'D')
	{
		if ((list->tilemap[y][x].right && list->tilemap[y][x].right->type == COLLECTIBLE)
			|| (list->tilemap[y][x].right && list->tilemap[y][x].right->type == EMPTY_SPACE))
		{
			if (list->tilemap[y][x].right->type == COLLECTIBLE)
				list->map.collectibles--;
			move_player_conf(list, key_pressed, x, y);
			player_moved(list);
		}
	}
	if (key_pressed == 'W')
	{
		if ((list->tilemap[y][x].up && list->tilemap[y][x].up->type == COLLECTIBLE)
			|| (list->tilemap[y][x].up && list->tilemap[y][x].up->type == EMPTY_SPACE))
		{
			if (list->tilemap[y][x].up->type == COLLECTIBLE)
				list->map.collectibles--;
			move_player_conf(list, key_pressed, x, y);
			player_moved(list);
		}
	}
}

void	move_player(t_list *list, char key_pressed, int x, int y)
{
	if (key_pressed == 'A')
	{
		if ((list->tilemap[y][x].left && list->tilemap[y][x].left->type == COLLECTIBLE)
			|| (list->tilemap[y][x].left && list->tilemap[y][x].left->type == EMPTY_SPACE))
		{
			if (list->tilemap[y][x].left->type == COLLECTIBLE)
				list->map.collectibles--;
			move_player_conf(list, key_pressed, x, y);
			player_moved(list);
		}
	}
	if (key_pressed == 'S')
	{
		if ((list->tilemap[y][x].down && list->tilemap[y][x].down->type == COLLECTIBLE)
			|| (list->tilemap[y][x].down && list->tilemap[y][x].down->type == EMPTY_SPACE))
		{
			if (list->tilemap[y][x].down->type == COLLECTIBLE)
				list->map.collectibles--;
			move_player_conf(list, key_pressed, x, y);
			player_moved(list);
		}
	}
	move_player2(list, key_pressed, x, y);
}
