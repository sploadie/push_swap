/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:42:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:46:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_operations(int *a, int *b, int *sizes, int ans_val)
{
	if (ans_val == SA)
		ps_swap(sizes[1]
			, a + (sizes[0] - sizes[1]), a + (sizes[0] - sizes[1]) + 1);
	else if (ans_val == RA)
		ps_rotate(a, sizes[1], sizes[0]);
	else if (ans_val == RRA)
		ps_rev_rotate(a, sizes[1], sizes[0]);
	else if (ans_val == PA)
	{
		sizes[2]++;
		b[(sizes[0] - sizes[2]) + 0] = a[(sizes[0] - sizes[1]) + 0];
		sizes[1]--;
	}
}

void	b_operations(int *a, int *b, int *sizes, int ans_val)
{
	if (ans_val == SB)
		ps_swap(sizes[2]
			, b + (sizes[0] - sizes[2]), b + (sizes[0] - sizes[2]) + 1);
	else if (ans_val == RB)
		ps_rotate(b, sizes[2], sizes[0]);
	else if (ans_val == RRB)
		ps_rev_rotate(b, sizes[2], sizes[0]);
	else if (ans_val == PB)
	{
		sizes[1]++;
		a[(sizes[0] - sizes[1]) + 0] = b[(sizes[0] - sizes[2]) + 0];
		sizes[2]--;
	}
}
