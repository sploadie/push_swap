/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:41:26 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:47:45 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_a(int *original, int *a, int size)
{
	int		i;
	int		j;
	int		value;
	int		count;

	i = 0;
	while (i < size)
	{
		value = original[i];
		count = 0;
		j = 0;
		while (j < size)
		{
			if (original[j] < value)
				count++;
			j++;
		}
		a[i] = count;
		i++;
	}
}

int		check_a(int *a, int a_size, int size)
{
	int		i;

	if (a_size != size)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		if (a[i] != i)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	duplicate_a(int *dup_a, int *a, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		dup_a[i] = a[i];
		i++;
	}
}
