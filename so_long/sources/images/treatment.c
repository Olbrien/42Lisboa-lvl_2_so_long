/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:36:33 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 22:10:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_plant_images(t_list *list)
{
	int	width;
	int	height;

	list->images.plant_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLANT_01,
			&width, &height);
	if (list->images.plant_01 == NULL)
		exit_error("Could not load image plant_01\n", list);
	list->images.plant_02 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLANT_02,
			&width, &height);
	if (list->images.plant_02 == NULL)
		exit_error("Could not load image plant_02\n", list);
	list->images.plant_03 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLANT_03,
			&width, &height);
	if (list->images.plant_03 == NULL)
		exit_error("Could not load image plant_03\n", list);
	list->images.plant_04 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, PLANT_04,
			&width, &height);
	if (list->images.plant_04 == NULL)
		exit_error("Could not load image plant_04\n", list);
}

void	open_enemy_images(t_list *list)
{
	int	width;
	int	height;

	list->images.enemy_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, ENEMY_01,
			&width, &height);
	if (list->images.enemy_01 == NULL)
		exit_error("Could not load image enemy_01\n", list);
	list->images.enemy_02 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, ENEMY_02,
			&width, &height);
	if (list->images.enemy_02 == NULL)
		exit_error("Could not load image enemy_02\n", list);
	list->images.enemy_03 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, ENEMY_03,
			&width, &height);
	if (list->images.enemy_03 == NULL)
		exit_error("Could not load image enemy_03\n", list);
	list->images.enemy_04 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, ENEMY_04,
			&width, &height);
	if (list->images.enemy_04 == NULL)
		exit_error("Could not load image enemy_04\n", list);
}

void	open_effect_images(t_list *list)
{
	int	width;
	int	height;

	list->images.effect_w = mlx_xpm_file_to_image(list->mlx.mlx_ptr, EFFECT_W,
			&width, &height);
	if (list->images.effect_w == NULL)
		exit_error("Could not load image effect_w\n", list);
}

void	open_door_images(t_list *list)
{
	int	width;
	int	height;

	list->images.door_01 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, DOOR_01,
			&width, &height);
	if (list->images.door_01 == NULL)
		exit_error("Could not load image door_01\n", list);
	list->images.door_02 = mlx_xpm_file_to_image(list->mlx.mlx_ptr, DOOR_02,
			&width, &height);
	if (list->images.door_02 == NULL)
		exit_error("Could not load image door_02\n", list);
}

void	images_treatment(t_list *list)
{
	open_door_images(list);
	open_effect_images(list);
	open_enemy_images(list);
	open_plant_images(list);
	open_player_images(list);
	open_wall_images(list);
	open_wall2_images(list);
}
