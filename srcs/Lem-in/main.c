/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:32:00 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 05:56:06 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
changed by ivan
int		main(void)
{
	t_data	data;
	t_room	**array;
	int		**paths;
	int		**queue;

	array = NULL;
	queue = NULL;
	fill_data(&data);
	if ((validator(&data, 0)) == -1)
		return (ft_free(&data, &array, &queue));
	if (create_array_rooms(&data, &array) == -1)
		return (ft_free(&data, &array, &queue));
	fill_array_rooms(&data, array);
	if (ft_create_queue(&data, &queue) == -1)
		return (ft_free(&data, &array, &queue));
	bfs(&data, array, queue);
	if (algo_prepare_graph(&data, array, &queue) == -1)
		return (ft_free(&data, &array, &queue));
	if (create_paths(&data, &paths) == -1 ||
		get_path(&data, array, paths) == -1)
		return (ft_free(&data, &array, &paths));
	print_ants_rooms_links(&data);
	move_ant(&data, array, paths);
	return (ft_free(&data, &array, &paths));
}
