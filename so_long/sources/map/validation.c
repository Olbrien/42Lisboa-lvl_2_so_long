/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 02:28:33 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/09 03:21:34 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_map_is_closed(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->map.width)
	{
		if (list->map.map_splitted[0][i] != '1'
			|| list->map.map_splitted[list->map.height - 1][i] != '1')
			exit_error("Map is not closed\n", list);
		i++;
	}
	i = 1;
	if (list->map.height > 2)
	{
		while (i < list->map.height - 1)
		{
			if (list->map.map_splitted[i][0] != '1'
				|| list->map.map_splitted[i][list->map.width - 1] != '1')
				exit_error("Map is not closed\n", list);
			i++;
		}
	}
}

void	check_if_map_is_rectangular(t_list *list)
{
	int	width;
	int	i;
	int	j;

	width = 0;
	i = 0;
	while (list->map.map_splitted[i] != NULL)
	{
		j = 0;
		while (list->map.map_splitted[i][j] != '\0')
			j++;
		if (width == 0)
			width = j;
		if (width != j)
			exit_error("Map is not rectangular\n", list);
		i++;
	}
	if (i <= 1)
		exit_error("Map is not rectangular\n", list);
	list->map.height = i;
	list->map.width = j;
}
