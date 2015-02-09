/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:42:23 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:45:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(int *a, int a_size, int size)
{
	int		i;
	int		temp;

	if (a_size < 2)
		return ;
	temp = a[(size - a_size) + 0];
	i = 0;
	while (i < a_size - 1)
	{
		a[(size - a_size) + i] = a[(size - a_size) + i + 1];
		i++;
	}
	a[(size - a_size) + i] = temp;
}

void	ps_rev_rotate(int *a, int a_size, int size)
{
	int		i;
	int		temp;
	int		temp2;

	if (a_size < 2)
		return ;
	temp = a[(size - a_size) + 0];
	a[(size - a_size) + 0] = a[(size - a_size) + (a_size - 1)];
	i = 0;
	while (i < a_size - 1)
	{
		temp2 = temp;
		temp = a[(size - a_size) + i + 1];
		a[(size - a_size) + i + 1] = temp2;
		i++;
	}
	a[(size - a_size) + 0] = temp;
}

void	ps_dual_rotate(int *a, int *b, int *sizes)
{
	ps_rotate(a, sizes[1], sizes[0]);
	ps_rotate(b, sizes[2], sizes[0]);
}

void	ps_dual_rev_rotate(int *a, int *b, int *sizes)
{
	ps_rev_rotate(a, sizes[1], sizes[0]);
	ps_rev_rotate(b, sizes[2], sizes[0]);
}
