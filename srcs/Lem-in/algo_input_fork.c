/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_input_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:47:21 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/14 08:55:58 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

static int		search_no_input_forks(t_data *data, t_room **array,
										t_child *parent)
{
	if (data->start->num != array[parent->num]->num &&
			array[parent->num]->output == 1)
	{
		parent = array[parent->num]->parent;
		if (search_no_input_forks(data, array, parent) == 0)
			return (0);
		else
			return (1);
	}
	else if (data->start->num == array[parent->num]->num)
		return (1);
	return (0);
}

static void		delete_fork(t_room **array, int i, t_child *parent)
{
	t_child		*temp;
	t_child		*temp_parent;

	temp = array[i]->parent;
	while (temp)
	{
		if (temp->num == parent->num)
		{
			temp = temp->next;
			array[i]->parent = parent;
			array[i]->parent->next = NULL;
			array[i]->parent->prev = NULL;
		}
		else
		{
			temp_parent = array[temp->num]->child;
			del_child_or_parent(&temp_parent, i, array, temp->num);
			array[temp->num]->output--;
			del_child_or_parent(&temp, temp->num, array, i);
			array[i]->input--;
		}
	}
}

static void		ft_search_del_fork(t_data *data, t_room **array,
									int i, int **queue)
{
	t_child		*parent;
	int			status;
	int			y;

	status = 0;
	y = -1;
	while (queue[i][++y] != -1)
	{
		if (array[queue[i][y]]->num != data->end->num &&
				array[queue[i][y]]->input > 1)
		{
			parent = array[queue[i][y]]->parent;
			while (status == 0 && parent)
			{
				if (search_no_input_forks(data, array, parent) == 0)
					parent = parent->next;
				else
					status = 1;
			}
			(status == 1) ? delete_fork(array, queue[i][y], parent) :
			delete_fork(array, queue[i][y], array[queue[i][y]]->parent);
		}
	}
}

void			del_input_forks(t_data *data, t_room **array,
									int i, int **queue)
{
	while (queue[++i][0] != -1)
		ft_search_del_fork(data, array, i, queue);
}
