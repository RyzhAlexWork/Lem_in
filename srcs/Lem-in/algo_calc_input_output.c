/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_calc_input_output.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:15:48 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/14 08:20:00 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

void		calculate_input_and_output(t_room **array, int **queue)
{
	int			i;
	int			y;
	t_child		*child;

	i = -1;
	while (queue[++i][0] != -1)
	{
		y = -1;
		while (queue[i][++y] != -1)
		{
			child = array[queue[i][y]]->child;
			while (child)
			{
				array[queue[i][y]]->output++;
				array[child->num]->input++;
				child = child->next;
			}
		}
	}
}
