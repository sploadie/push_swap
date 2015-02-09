/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_original.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:41:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:44:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_original(int *original, int size, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		if (!isintstring(argv[i]))
			ps_error();
		original[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (original[i] == original[j])
				ps_error();
			j++;
		}
		i++;
	}
}
