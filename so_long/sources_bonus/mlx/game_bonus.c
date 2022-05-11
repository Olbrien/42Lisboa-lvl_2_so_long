/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:55 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 04:12:31 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	loop(t_list *list)
{
	static int		frames = 0;

	mlx_clear_window(list->mlx.mlx_ptr, list->mlx.win_ptr);
	render_step_text(list);
	render_tiles(list);
	if (list->map.collectibles == 0)
		render_exit(list);
	if (frames > FRAME_RATE)
	{
		render_animations(list);
		list->key_pressed = 0;
		frames = 0;
	}
	frames++;
	return (0);
}

void	hooks(t_list *list)
{
	mlx_loop_hook(list->mlx.mlx_ptr, &loop, list);
	mlx_hook(list->mlx.win_ptr, DESTROYNOTIFY, 0, &exit_no_error, list);
	mlx_hook(list->mlx.win_ptr, KEYPRESS, KEYPRESSMASK, &key_press, list);
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
			list->mlx.height + 25, "so_long");
	if (!list->mlx.win_ptr)
		exit_error("Could not initialize window\n", list);
}

void	config_game(t_list *list)
{
	init_game(list);
	images_treatment(list);
	fill_tilemap_with_images(list);
	hooks(list);
}
