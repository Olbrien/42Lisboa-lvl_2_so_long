/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:13:21 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 19:22:39 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_wall2_images(t_list *list)
{
	int width;
	int height;

	list->images.wall_l = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_L, &width, &height);
	if (list->images.wall_l == NULL)
		exit_error("Could not load image player_l\n", list);
	list->images.wall_r = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_R, &width, &height);
	if (list->images.wall_r == NULL)
		exit_error("Could not load image player_r\n", list);
	list->images.wall_u = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_U, &width, &height);
	if (list->images.wall_u == NULL)
		exit_error("Could not load image player_u\n", list);
	list->images.wall_ul = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_UL, &width, &height);
	if (list->images.wall_ul == NULL)
		exit_error("Could not load image player_ul\n", list);
	list->images.wall_ur = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_UR, &width, &height);
	if (list->images.wall_ur == NULL)
		exit_error("Could not load image player_ur\n", list);
}

void	open_wall_images(t_list *list)
{
	int width;
	int height;

	list->images.wall_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_01, &width, &height);
	if (list->images.wall_01 == NULL)
		exit_error("Could not load image wall_01\n", list);
	list->images.wall_02 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_02, &width, &height);
	if (list->images.wall_02 == NULL)
		exit_error("Could not load image player_02\n", list);
	list->images.wall_d = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_D, &width, &height);
	if (list->images.wall_d == NULL)
		exit_error("Could not load image player_d\n", list);
	list->images.wall_dl = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_DL, &width, &height);
	if (list->images.wall_dl == NULL)
		exit_error("Could not load image player_dl\n", list);
	list->images.wall_dr = mlx_xpm_file_to_image(list->mlx.mlx_ptr, WALL_DR, &width, &height);
	if (list->images.wall_dr == NULL)
		exit_error("Could not load image player_dr\n", list);
}
