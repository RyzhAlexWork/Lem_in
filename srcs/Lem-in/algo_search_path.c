/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_search_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:40:32 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 07:36:54 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

static int		create_path(t_data *data, int **path,
						t_room **array, t_child *parent)
{
	int			i;
	t_room		*temp;
	int			max;

	max = array[parent->num]->level;
	if (((*path) = (int*)malloc(sizeof(int) * (max + 4))) == NULL)
		return (-1);
	(*path)[max + 3] = -1;
	(*path)[0] = max + 2;
	(*path)[1] = data->start->num;
	(*path)[max + 2] = data->end->num;
	i = max + 2;
	temp = array[parent->num];
	while (--i > 1)
	{
		(*path)[i] = temp->num;
		if (array[temp->num]->parent)
			temp = array[array[temp->num]->parent->num];
		else
			return (0);
	}
	data->total_paths++;
	return (1);
}

static int		check_forks(int **paths, int checked, int max)
{
	int		i;
	int		y;
	int		status;

	status = 1;
	y = 0;
	while (status == 1 && y < max)
	{
		i = 0;
		while (status == 1 && paths[y][i] != -1)
		{
			if (paths[y][i] == checked)
				status = -1;
			i++;
		}
		y++;
	}
	return (status);
}

static int		iteration_get_path(t_room **array,
						int **paths, t_child *parent, int i)
{
	int			status;
	t_child		*temp;

	temp = parent;
	status = 1;
	while (status == 1 && temp->num != array[paths[0][1]]->num)
	{
		if (array[temp->num]->output > 1)
			if (check_forks(paths, temp->num, i + 1) == -1)
				status = -1;
		temp = array[temp->num]->parent;
	}
	return (status);
}

int				get_path(t_data *data, t_room **array, int **paths)
{
	t_child		*parent;
	int			i;

	check_path(array, data->start->num, data->end->parent, data->end->num);
	if (!data->end->parent)
		return (print_error());
	if (data->end->parent->next)
		sort_childs(array, data->end, data->end->parent);
	i = 0;
	parent = data->end->parent;
	if ((create_path(data, &(paths[i]), array, parent)) == -1)
		return (print_error());
	parent = parent->next;
	while (parent)
	{
		if ((iteration_get_path(array, paths, parent, i)) == 1)
			if ((create_path(data, &(paths[++i]), array, parent)) == -1)
				return (print_error());
		parent = parent->next;
	}
	while (++i < data->end->input)
		paths[i] = NULL;
	return (0);
}
