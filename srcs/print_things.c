/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:41:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:45:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_answer(int *answer, int steps)
{
	while (steps--)
	{
		if (*answer == SA)
			ft_putstr("sa");
		else if (*answer == SB)
			ft_putstr("sb");
		else if (*answer == PA)
			ft_putstr("pa");
		else if (*answer == PB)
			ft_putstr("pb");
		else if (*answer == RA)
			ft_putstr("ra");
		else if (*answer == RB)
			ft_putstr("rb");
		else if (*answer == RR)
			ft_putstr("rr");
		else if (*answer == RRA)
			ft_putstr("rra");
		else if (*answer == RRB)
			ft_putstr("rrb");
		else if (*answer == RRR)
			ft_putstr("rrr");
		answer++;
		!steps ? write(1, "\n", 1) : write(1, " ", 1);
	}
}

void	print_a(int *a, int a_size, int size)
{
	int		i;

	write(1, "[", 1);
	i = 0;
	while (i < a_size)
	{
		ft_putnbr(a[(size - a_size) + i]);
		i++;
		i == a_size ? write(1, "]\n", 2) : write(1, ", ", 2);
	}
}
