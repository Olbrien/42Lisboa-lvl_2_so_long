/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:55 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 20:21:01 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_list *list)
{
	render_tiles(list);

	return (0);
}

void	hooks(t_list *list)
{
	mlx_hook(list->mlx.win_ptr, DESTROYNOTIFY, 0, &exit_no_error, list);
	mlx_hook(list->mlx.win_ptr, KEYPRESS, KEYPRESSMASK, &key_press, list);

	mlx_loop_hook(list->mlx.mlx_ptr, &loop, list);

	mlx_loop(list->mlx.mlx_ptr);
}

void	init_game(t_list *list)
{
	list->mlx.height = list->map.height * IMG_SIZE;
	list->mlx.width = list->map.width * IMG_SIZE;

	list->mlx.mlx_ptr = mlx_init();
	if (!list->mlx.mlx_ptr)
		exit_error("Could not initialize mlx\n", list);

	list->mlx.win_ptr = mlx_new_window (list->mlx.mlx_ptr, list->mlx.width,
										list->mlx.height, "so_long");
	if (!list->mlx.win_ptr)
		exit_error("Could not initialize window\n", list);
}

void	config_game(t_list *list)
{
	init_game(list);

	images_treatment(list);

	create_panel(list, &list->effects.img_white_flash_ptr, create_color(254, 254, 254, 0));
	create_panel(list, &list->effects.img_pink_flash_ptr, create_color(238, 130, 238, 0));
	create_panel(list, &list->effects.img_red_flash_ptr, create_color(197, 4, 4, 0));

	hooks(list);

}
