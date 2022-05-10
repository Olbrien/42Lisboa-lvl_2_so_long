/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:14:10 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 00:35:35 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_list *list)
{
	if (list->key_pressed == 1)
		return (0);
	if (keycode == ESC_KEY)
		exit_no_error(list);
	else if (keycode == A_KEY)
		move_player(list, 'A', list->current_player_x, list->current_player_y);
	else if (keycode == S_KEY)
		move_player(list, 'S', list->current_player_x, list->current_player_y);
	else if (keycode == D_KEY)
		move_player(list, 'D', list->current_player_x, list->current_player_y);
	else if (keycode == W_KEY)
		move_player(list, 'W', list->current_player_x, list->current_player_y);

	list->key_pressed = 1;
	return (0);
}

int		key_release(int keycode, t_list *list)
{
	(void)keycode;
	if (list->key_pressed == 1)
		list->key_pressed = 0;
	return (0);
}
