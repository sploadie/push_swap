/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:43:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 17:01:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putcounter(unsigned long n)
{
	char	txtspc[22];
	int		ntxt;

	if (!(n % 5 == 0))
		return ;
	ntxt = 21;
	txtspc[ntxt] = '\0';
	while (n > 0)
	{
		txtspc[--ntxt] = '0' + (n % 10);
		n = n / 10;
	}
	txtspc[--ntxt] = '\r';
	write(1, txtspc + ntxt, 21 - ntxt);
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

static int	skip_rrr(int *ans, int i, int steps)
{
	ans[i]++;
	while (++i < steps)
		ans[i] = RRR + 1;
	return (0);
}

static int	leanificate_answer(int *ans, int steps, int a_size)
{
	int		i;
	int		b_size;

	i = 0;
	b_size = 0;
	while (i < steps - 1)
	{
		if (a_size < 2)
		{
			if (ans[i] == RRR)
				return (skip_rrr(ans, i, steps));
			if (   ans[i] == SA
				|| ans[i] == SS
				|| ans[i] == RA
				|| ans[i] == RR
				|| ans[i] == RRA)
			{
				ans[i]++;
				continue ;
			}
		}
		if (b_size < 2)
		{
			if (ans[i] == RRR)
				return (skip_rrr(ans, i, steps));
			if (   ans[i] == SA
				|| ans[i] == SS
				|| ans[i] == RB
				|| ans[i] == RR
				|| ans[i] == RRA)
			{
				ans[i]++;
				continue ;
			}
		}
		if (   (a_size < 1 && ans[i] == PA)
			|| (b_size < 1 && ans[i] == PB))
		{
			ans[i]++;
			continue ;
		}
		if (ans[i] == SS && ans[i + 1] <= SS)
			ans[i + 1] = SS + 1;
		if (   ((ans[i] == SA || ans[i] == SB) && (ans[i] == ans[i + 1]))
			|| (ans[i] == PA && ans[i + 1] == PB)
			|| (ans[i] == PB && ans[i + 1] == PA))
			ans[i + 1] += 1;
		if ((ans[i] >= RA && ans[i] <= RR) && ans[i + 1] >= RRA)
		{
			ans[i] += 1;
			ans[i + 1] = SA;
		}
		if (ans[i] >= RRA && (ans[i + 1] >= RA && ans[i + 1] <= RR))
			ans[i + 1] = RRA;
		if (ans[i] == PA)
		{
			a_size--;
			b_size++;
		}
		else if (ans[i] == PB)
		{
			b_size--;
			a_size++;
		}
		i++;
	}
	if (   (a_size < 1 && ans[i] == PA)
		|| (b_size < 1 && ans[i] == PB))
		ans[i]++;
	if (ans[i] == PA)
	{
		a_size--;
		b_size++;
	}
	else if (ans[i] == PB)
	{
		b_size--;
		a_size++;
	}
	if (b_size > 0)
		return (0);
	return (1);
}

int			*compute_answer(int *a, int size, int steps)
{
	int				i;
	int				ans[steps];
	int				dup_a[size];

	ft_bzero(ans, steps * sizeof(int));
	ans[steps - 1] = -1;
	while (ans[0] < RRR)
	{
		ans[steps - 1] += 1;
		i = steps;
		while (--i, i != 0 && ans[i] > RRR)
		{
			ans[i] = SA;
			ans[i - 1] += 1;
		}
		if (!leanificate_answer(ans, steps, size))
			continue ;
		if (duplicate_a(dup_a, a, size), check_answer(dup_a, size, steps, ans))
			return (ft_memdup(ans, steps * sizeof(int)));
	}
	return (NULL);
}

int			*verbose_compute_answer(int *a, int size, int steps)
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
		ans[steps - 1] += 1;
		i = steps;
		while (--i, i != 0 && ans[i] > RRR)
		{
			ans[i] = SA;
			ans[i - 1] += 1;
		}
		if (!leanificate_answer(ans, steps, size))
			continue ;
		putcounter(++ans_count);
		if (duplicate_a(dup_a, a, size), check_answer(dup_a, size, steps, ans))
			return (ft_memdup(ans, steps * sizeof(int)));
	}
	return (NULL);
}
