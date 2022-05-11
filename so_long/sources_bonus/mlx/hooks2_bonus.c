/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:18:23 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 01:46:01 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_key_w(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].up && list->tilemap[y][x].up->type == COLLECTIBLE)
		|| (list->tilemap[y][x].up
			&& list->tilemap[y][x].up->type == EMPTY_SPACE))
	{
		if (list->tilemap[y][x].up->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].up->type = PLAYER_POSITION;
		list->tilemap[y][x].up->image = list->tilemap[y][x].image;
		list->tilemap[y][x].up->image_number = list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		player_moved(list);
	}
	if ((list->tilemap[y][x].up
			&& list->tilemap[y][x].up->image == list->images.door_02))
	{
		player_moved(list);
		exit_no_error(list);
	}
}

void	move_player_key_d(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].right
			&& list->tilemap[y][x].right->type == COLLECTIBLE)
		|| (list->tilemap[y][x].right
			&& list->tilemap[y][x].right->type == EMPTY_SPACE))
	{
		if (list->tilemap[y][x].right->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].right->type = PLAYER_POSITION;
		list->tilemap[y][x].right->image = list->tilemap[y][x].image;
		list->tilemap[y][x].right->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		player_moved(list);
	}
	if ((list->tilemap[y][x].right
			&& list->tilemap[y][x].right->image == list->images.door_02))
	{
		player_moved(list);
		exit_no_error(list);
	}
}

void	move_player_key_s(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].down
			&& list->tilemap[y][x].down->type == COLLECTIBLE)
		|| (list->tilemap[y][x].down
			&& list->tilemap[y][x].down->type == EMPTY_SPACE))
	{
		if (list->tilemap[y][x].down->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].down->type = PLAYER_POSITION;
		list->tilemap[y][x].down->image = list->tilemap[y][x].image;
		list->tilemap[y][x].down->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		player_moved(list);
	}
	if ((list->tilemap[y][x].down
			&& list->tilemap[y][x].down->image == list->images.door_02))
	{
		player_moved(list);
		exit_no_error(list);
	}
}

void	move_player_key_a(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].left
			&& list->tilemap[y][x].left->type == COLLECTIBLE)
		|| (list->tilemap[y][x].left
			&& list->tilemap[y][x].left->type == EMPTY_SPACE))
	{
		if (list->tilemap[y][x].left->type == COLLECTIBLE)
			list->map.collectibles--;
		list->tilemap[y][x].left->type = PLAYER_POSITION;
		list->tilemap[y][x].left->image = list->tilemap[y][x].image;
		list->tilemap[y][x].left->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
		player_moved(list);
	}
	if ((list->tilemap[y][x].left
			&& list->tilemap[y][x].left->image == list->images.door_02))
	{
		player_moved(list);
		exit_no_error(list);
	}
}

void	move_player(t_list *list, char key_pressed, int x, int y)
{
	if (key_pressed == 'A')
		move_player_key_a(list, x, y);
	if (key_pressed == 'S')
		move_player_key_s(list, x, y);
	if (key_pressed == 'D')
		move_player_key_d(list, x, y);
	if (key_pressed == 'W')
		move_player_key_w(list, x, y);
}
