/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:41:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/11 11:48:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_answer(int *answer, int steps)
{
	while (steps--)
	{
		(*answer == SA) ? ft_putstr("sa") : (void)SA;
		(*answer == SB) ? ft_putstr("sb") : (void)SB;
		(*answer == SS) ? ft_putstr("ss") : (void)SS;
		(*answer == PA) ? ft_putstr("pa") : (void)PA;
		(*answer == PB) ? ft_putstr("pb") : (void)PB;
		(*answer == RA) ? ft_putstr("ra") : (void)RA;
		(*answer == RB) ? ft_putstr("rb") : (void)RB;
		(*answer == RR) ? ft_putstr("rr") : (void)RR;
		(*answer == RRA) ? ft_putstr("rra") : (void)RRA;
		(*answer == RRB) ? ft_putstr("rrb") : (void)RRB;
		(*answer == RRR) ? ft_putstr("rrr") : (void)RRR;
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
