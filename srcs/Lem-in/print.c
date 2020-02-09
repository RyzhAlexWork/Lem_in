/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:33:08 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 07:16:00 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

int		print_error(void)
{
	ft_printf("ERROR\n");
	return (-1);
}

void	print_ants_rooms_links(t_data *data)
{
	t_lines		*temp;

	temp = data->first_line_print;
	while (temp)
	{
		ft_printf("%s\n", temp->line);
		temp = temp->next;
	}
	ft_printf("\n");
}
