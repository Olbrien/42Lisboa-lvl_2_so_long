/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:18:23 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 02:46:08 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, t_list *list)
{
	if (keycode == ESC_KEY)
		exit_no_error(list);
	else if (keycode == A_KEY)
	{
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
								list->effects.img_red_flash_ptr, 0, 0);
	}
	else if (keycode == S_KEY)
	{
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
								list->effects.img_pink_flash_ptr, 0, 0);
	}
	else if (keycode == D_KEY)
	{
		mlx_put_image_to_window(list->mlx.mlx_ptr, list->mlx.win_ptr,
								list->effects.img_white_flash_ptr, 0, 0);
	}


	return (0);
}
