/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:58:42 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 07:33:37 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

void	free_temp_link(t_link **temp_link, t_data *data)
{
	if ((*temp_link)->prev)
	{
		(*temp_link) = (*temp_link)->prev;
		free((*temp_link)->next);
		(*temp_link)->next = NULL;
	}
	else
	{
		free(*temp_link);
		(*temp_link) = NULL;
		data->links = NULL;
	}
}

int		ft_free_queue(int ***queue)
{
	int		i;

	i = 0;
	if (*queue)
	{
		while ((*queue)[i])
		{
			free((*queue)[i]);
			(*queue)[i] = NULL;
			i++;
		}
		free(*queue);
		(*queue) = NULL;
	}
	return (0);
}

int		rev(void)
{
	ft_printf("Too many ants!");
	return (-1);
}
