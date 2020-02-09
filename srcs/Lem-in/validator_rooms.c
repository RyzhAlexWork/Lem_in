/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:17:59 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 09:58:17 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

static int		check_coordinates(t_room *temp, t_room *check)
{
	while (temp->num != check->num)
	{
		if ((temp->x == check->x) && (temp->y == check->y))
			return (-1);
		check = check->next;
	}
	return (0);
}

static int		allocate_memory_for_room(t_room **temp, t_data *data)
{
	if (*temp)
	{
		if (((*temp)->next = (t_room*)malloc(sizeof(t_room))) == NULL)
			return (-1);
		(*temp)->next->child = NULL;
		(*temp) = (*temp)->next;
	}
	else
	{
		if ((data->rooms = (t_room*)malloc(sizeof(t_room))) == NULL)
			return (-1);
		(*temp) = data->rooms;
		(*temp)->child = NULL;
	}
	return (0);
}

static t_room	*create_room(t_data *data, t_lines *lines, int i, int y)
{
	t_room		*temp;
	t_room		*check;

	temp = data->rooms;
	while (temp && temp->next != NULL)
		temp = temp->next;
	if (allocate_memory_for_room(&temp, data) == -1)
		return (NULL);
	temp->num = data->order;
	data->order++;
	data->total_rooms = data->order;
	ft_fill_room(temp);
	temp->name = ft_strsub(lines->line, y, i - y);
	if (temp->name[0] == 'L' || temp->name[0] == '#')
		return (NULL);
	check = data->rooms;
	while (check->num != temp->num)
	{
		if (ft_strcmp(check->name, temp->name) == 0)
			return (NULL);
		check = check->next;
	}
	return (temp);
}

int				get_rooms(int i, t_data *data, t_lines *lines)
{
	t_room		*temp;
	int			y;

	while (lines->line[i] != '\0' && (lines->line[i] == ' ' ||
			lines->line[i] == '\t'))
		i++;
	y = i;
	while (lines->line[i] != '\0' && lines->line[i] != ' '
			&& lines->line[i] != '\t')
		i++;
	if (lines->line[i] == '\0')
		return (-1);
	if ((temp = create_room(data, lines, i, y)) == NULL)
		return (-1);
	if (get_x(&i, temp, lines) == -1)
		return (-1);
	if (get_y(&i, temp, lines) == -1)
		return (-1);
	return (check_coordinates(temp, data->rooms) == -1 ? -1 : 0);
}

int				get_commande(t_data *data, t_lines **lines)
{
	t_room		*temp;
	int			i;

	if (ft_strcmp(&((*lines)->line[2]), "start") == 0)
		i = 1;
	else if (ft_strcmp(&((*lines)->line[2]), "end") == 0)
		i = 2;
	else
		return (0);
	if ((i == 1 && data->start != NULL) || (i == 2 && data->end != NULL))
		return (-1);
	(*lines) = (*lines)->next;
	if (ft_check_comment(&(*lines)) == -1)
		return (-1);
	if (get_rooms(0, data, *lines) == -1)
		return (-1);
	temp = data->rooms;
	while (temp->next != NULL)
		temp = temp->next;
	if (i == 1)
		data->start = temp;
	else
		data->end = temp;
	return (0);
}
