/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_array_of_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:21:20 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/14 08:32:29 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

int			create_array_rooms(t_data *data, t_room ***array)
{
	t_room		*temp;

	temp = data->rooms;
	if (((*array) = (t_room **)malloc(sizeof(t_room*) *
			(data->total_rooms + 1))) == NULL)
		return (print_error());
	(*array)[data->total_rooms] = NULL;
	while (temp)
	{
		(*array)[temp->num] = temp;
		temp = temp->next;
	}
	return (0);
}

static int	add_child(int parent, t_room **array, int children)
{
	t_child		*child;

	if (array[parent]->child == NULL)
	{
		if ((array[parent]->child = (t_child*)malloc(sizeof(t_child))) == NULL)
			return (-1);
		child = array[parent]->child;
		child->prev = NULL;
		child->next = NULL;
	}
	else
	{
		child = array[parent]->child;
		while (child->next != NULL)
			child = child->next;
		if ((child->next = (t_child*)malloc(sizeof(t_child))) == NULL)
			return (-1);
		child->next->prev = child;
		child = child->next;
		child->next = NULL;
	}
	child->num = children;
	return (0);
}

int			fill_array_rooms(t_data *data, t_room **array)
{
	t_link	*temp;

	temp = data->links;
	while (temp != NULL)
	{
		if ((add_child(temp->a, array, temp->b)) == -1)
			return (print_error());
		if ((add_child(temp->b, array, temp->a)) == -1)
			return (print_error());
		temp = temp->next;
	}
	return (0);
}
