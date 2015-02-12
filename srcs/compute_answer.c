/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:43:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 15:21:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	skip_reset(int *answer)
{
	answer[0]++;
	answer[1] = SA;
}

static void	leanificate_beginning(int *ans, int i)
{
	(ans[i] == SS && ans[i + 1] <= SS) ? ans[i + 1] = SS + 1 : (void)ans;
	if ((ans[i] == SA || ans[i] == SB) && (ans[i] == ans[i + 1]))
		ans[i + 1] += 1;
	(ans[i] == PA && ans[i + 1] == PB) ? ans[i + 1] += 1 : (void)ans;
	(ans[i] == PB && ans[i + 1] == PA) ? ans[i + 1] += 1 : (void)ans;
	if ((ans[i] >= RA && ans[i] <= RR) && ans[i + 1] >= RRA)
		skip_reset(ans + i);
	if (ans[i] >= RRA && (ans[i + 1] >= RA && ans[i + 1] <= RR))
		ans[i + 1] = RRA;
}

static int	leanificate_answer(int *ans, int steps, int a_size)
{
	int		i;
	int		b_size;

	i = 0;
	b_size = 0;
	while (i < steps - 1)
	{
		leanificate_beginning(ans, i);
		if ((ans[i] == PA && a_size < 1) || (ans[i] == PB && b_size < 1))
		{
			skip_reset(ans + i);
			continue ;
		}
		(ans[i] == PA) ? vamp_count(&a_size, &b_size) : (void)ans;
		(ans[i] == PB) ? vamp_count(&b_size, &a_size) : (void)ans;
		i++;
	}
	if ((ans[i] == PA && a_size < 1) || (ans[i] == PB && b_size < 1))
		ans[i]++;
	(ans[i] == PA) ? vamp_count(&a_size, &b_size) : (void)ans;
	(ans[i] == PB) ? vamp_count(&b_size, &a_size) : (void)ans;
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
