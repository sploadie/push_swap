/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:19:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 15:20:11 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_answer(int *a, int size, int steps, int *answer)
{
	int		b[size];
	int		sizes[3];
	int		i;

	sizes[0] = size;
	sizes[1] = size;
	sizes[2] = 0;
	i = -1;
	while (++i < steps)
	{
		if (sizes[1] > 0)
			a_operations(a, b, sizes, answer[i]);
		if (sizes[2] > 0)
			b_operations(a, b, sizes, answer[i]);
		if (answer[i] == RR)
			ps_dual_rotate(a, b, sizes);
		else if (answer[i] == RRR)
			ps_dual_rev_rotate(a, b, sizes);
	}
	return (check_a(a, sizes[1], size));
}
