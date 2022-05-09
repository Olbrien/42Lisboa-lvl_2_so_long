/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:03:58 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/09 02:17:56 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	int	arg_len;

	if (argc != 2)
		exit_error("Wrong number of arguments\n", NULL);
	if (*argv[1] == 0)
		exit_error("NULL map argument\n", NULL);
	arg_len = ft_strlen(argv[1]);
	if (arg_len <= 4)
		exit_error("Map argument invalid\n", NULL);
	if (argv[1][arg_len - 1] != 'r'
		|| argv[1][arg_len - 2] != 'e'
		|| argv[1][arg_len - 3] != 'b'
		|| argv[1][arg_len - 4] != '.')
	{
		exit_error("Wrong map extension\n", NULL);
	}
	if (argv[1][arg_len - 5] == '/')
	{
		exit_error("No map name\n", NULL);
	}
}

int	main(int argc, char **argv)
{
	t_list	list;

	check_args(argc, argv);
	map_treatment(&list, argv[1]);
	if (DEBUG == 1)
		debug(&list);
	free_list(&list);
}
