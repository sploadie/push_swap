/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:43:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/11 14:20:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putcounter(unsigned long n)
{
	char	txtspc[20];
	char	*ntxt;

	ntxt = &txtspc[10];
	*ntxt = '\0';
	while (n > 0)
	{
		*(--ntxt) = 48 + (n % 10);
		n = n / 10;
	}
	ft_putstr(ntxt);
}

static int	check_answer(int *a, int size, int steps, int *answer)
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

static void	leanificate_answer(int *ans, int steps)
{
	int		i;

	i = 0;
	while (i < steps - 1)
	{
		if (ans[i] == SS && ans[i + 1] <= SS)
			ans[i + 1] = SS + 1;
		if ((ans[i] == SA || ans[i] == SB) && (ans[i] == ans[i + 1]))
			ans[i + 1] += 1;
		if ((ans[i] >= RA && ans[i] <= RR) && ans[i + 1] >= RRA)
		{
			ans[i] += 1;
			ans[i + 1] = SA;
		}
		if (ans[i] >= RRA && (ans[i + 1] >= RA && ans[i + 1] <= RR))
			ans[i + 1] = RRA;
		i++;
	}
}

int			*compute_answer(int *a, int size, int steps)
{
	int				i;
	int				ans[steps];
	int				dup_a[size];
	unsigned long	ans_count;

	ans_count = 0;
	ft_bzero(ans, steps * sizeof(int));
	ans[steps - 1] = -1;
	while (ans[0] < RRR)
	{
		if (deal_options("v", 0))
		{
			write(1, "\r", 1);
			putcounter(++ans_count);
		}
		ans[steps - 1] += 1;
		i = steps;
		while (--i, i != 0 && ans[i] > RRR)
		{
			ans[i] = SA;
			ans[i - 1] += 1;
		}
		leanificate_answer(ans, steps);
		if (duplicate_a(dup_a, a, size), check_answer(dup_a, size, steps, ans))
			return (ft_memdup(ans, steps * sizeof(int)));
	}
	return (NULL);
}
