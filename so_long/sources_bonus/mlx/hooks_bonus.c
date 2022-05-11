/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:14:10 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 01:41:29 by tisantos         ###   ########.fr       */
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

int	key_press(int keycode, t_list *list)
{
	if (list->key_pressed == 1)
		return (0);
	if (keycode == ESC_KEY)
		exit_no_error(list);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		move_player(list, 'A', list->current_player_x, list->current_player_y);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(list, 'S', list->current_player_x, list->current_player_y);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_player(list, 'D', list->current_player_x, list->current_player_y);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_player(list, 'W', list->current_player_x, list->current_player_y);
	list->key_pressed = 1;
	return (0);
}
