/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:19:25 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 04:40:28 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move_left(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].left
			&& list->tilemap[y][x].left->type == EMPTY_SPACE))
	{
		list->tilemap[y][x].left->type = ENEMY;
		list->tilemap[y][x].left->image = list->tilemap[y][x].image;
		list->tilemap[y][x].left->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	else if ((list->tilemap[y][x].left
			&& list->tilemap[y][x].left->type == PLAYER_POSITION))
	{
		exit_no_error(list);
	}
}

void	enemy_move_down(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].down
			&& list->tilemap[y][x].down->type == EMPTY_SPACE))
	{
		list->tilemap[y][x].down->type = ENEMY;
		list->tilemap[y][x].down->image = list->tilemap[y][x].image;
		list->tilemap[y][x].down->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	else if ((list->tilemap[y][x].down
			&& list->tilemap[y][x].down->type == PLAYER_POSITION))
	{
		exit_no_error(list);
	}
}

void	enemy_move_right(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].right
			&& list->tilemap[y][x].right->type == EMPTY_SPACE))
	{
		list->tilemap[y][x].right->type = ENEMY;
		list->tilemap[y][x].right->image = list->tilemap[y][x].image;
		list->tilemap[y][x].right->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	else if ((list->tilemap[y][x].right
			&& list->tilemap[y][x].right->type == PLAYER_POSITION))
	{
		exit_no_error(list);
	}
}

void	enemy_move_up(t_list *list, int x, int y)
{
	if ((list->tilemap[y][x].up
			&& list->tilemap[y][x].up->type == EMPTY_SPACE))
	{
		list->tilemap[y][x].up->type = ENEMY;
		list->tilemap[y][x].up->image = list->tilemap[y][x].image;
		list->tilemap[y][x].up->image_number
			= list->tilemap[y][x].image_number;
		list->tilemap[y][x].type = EMPTY_SPACE;
		list->tilemap[y][x].image = NULL;
	}
	else if ((list->tilemap[y][x].up
			&& list->tilemap[y][x].up->type == PLAYER_POSITION))
	{
		exit_no_error(list);
	}
}

void	render_enemy_patrol(t_list *list, int random_number)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].type == 'X')
			{
				random_number = rand() % ((3 + 1) - 0) + 0;
				if (random_number == 0)
					enemy_move_left(list, x, y);
				else if (random_number == 1)
					enemy_move_down(list, x, y);
				else if (random_number == 2)
					enemy_move_right(list, x, y);
				else if (random_number == 3)
					enemy_move_up(list, x, y);
			}
			x++;
		}
		y++;
	}
}
