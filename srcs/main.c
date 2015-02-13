/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 17:34:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	score_a(int *a, int size)
{
	int total;
	int	i;

	//Avoid errors
	if (size < 2)
		return ;
	total = 0;
	//Points at 0
	//Is 0?
	if (a[0] == 0)
		total++;
	//Is less than next?
	if (a[0] < a[1])
		total++;
	//Is before next?
	if (a[0] + 1 == a[1])
		total++;
	i = 0;
	while (++i < size - 1)
	{
		//Points at i
		//Is i?
		if (a[i] == i)
			total++;
		//Is less than next?
		if (a[i] < a[i + 1])
			total++;
		//Is before next?
		if (a[i] + 1 == a[i + 1])
			total++;
	}
	//Points at last
	//Is last?
	if (a[size - 1] == size - 1)
		total++;
	//Is less than next?
	if (a[size - 1] < a[0])
		total++;
	//Is before next?
	if (a[size - 1] + 1 == a[0])
		total++;
	ft_putstr("Score=");
	ft_putnbr(total);
	write(1, " ", 1);
}

int		main(int argc, char **argv)
{
	int			original[argc - 1];
	int			a[argc - 1];
	int			i;
	int			*answer;

	while (argc - 1 > 0 && deal_options(*(++argv), 1))
		argc--;
	if (argc - 1 < 1)
		ps_error();
	if (argc - 1 == 1)
		return (0);
	get_original(original, --argc, argv);
	generate_a(original, a, argc);
	if (check_a(a, argc, argc))
		return (0);
	score_a(a, argc);
	i = 1;
	if (deal_options("v", 0))
	{
		while (!(answer = verbose_compute_answer(a, argc, i++)))
			write(1, "\n", 1);
		i--;
		write(1, "\n", 1);
	}
	else
	{
		while (!(answer = compute_answer(a, argc, i)))
			i++;
	}
	print_answer(answer, i);
	return (0);
}
