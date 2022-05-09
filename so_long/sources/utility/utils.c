/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:01 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/09 02:19:14 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_list *list)
{
	int	i;

	i = 0;
	if (list->map.map != NULL)
	{
		free(list->map.map);
		list->map.map = NULL;
	}
	if (list->map.map_splitted != NULL)
	{
		while (list->map.map_splitted[i] != NULL)
		{
			free(list->map.map_splitted[i]);
			i++;
		}
		free(list->map.map_splitted);
	}
}

void	exit_error(char *str, t_list *list)
{
	int	len;

	if (list != NULL)
		free_list(list);
	len = ft_strlen(str);
	write(2, "Error\n", 6);
	write(2, str, len);
	exit(1);
}

void	debug(t_list *list)
{
	int	i;

	i = 0;
	while (list->map.map_splitted[i] != NULL)
	{
		write(1, list->map.map_splitted[i], \
				ft_strlen(list->map.map_splitted[i]));
		write(1, "\n", 1);
		i++;
	}
}
