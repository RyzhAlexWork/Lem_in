/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_del_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:39:06 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/14 08:46:18 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

static t_child	*del_first_child(int y, t_room **array, int i, t_child *temp)
{
	if (array[i]->child && array[i]->child->num == y)
	{
		array[i]->child = temp->next;
		if (array[i]->child)
			array[i]->child->prev = NULL;
		temp = array[i]->child;
	}
	else
	{
		array[i]->parent = temp->next;
		if (array[i]->parent)
			array[i]->parent->prev = NULL;
		temp = array[i]->parent;
	}
	return (temp);
}

void			del_child_or_parent(t_child **child, int y,
								t_room **array, int i)
{
	t_child		*temp;
	t_child		*del;

	temp = (*child);
	while (temp->num != y)
		temp = temp->next;
	del = temp;
	if (temp->prev)
	{
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		temp = temp->next;
	}
	else
		temp = del_first_child(y, array, i, temp);
	free(del);
	(*child) = temp;
}

void			delete_no_one_link_a(t_data *data, t_room **array,
					int **queue, int i)
{
	while (queue[++i][0] != -1)
		delete_no_one_link(data, array, queue, i);
}
