/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 15:21:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	low_main(int *a, int argc, int *answer)
{
	int			i;

	i = 1;
	if (deal_options("v", 0))
	{
		while (!(answer = verbose_compute_answer(a, argc, i++)))
			write(1, "\n", 1);
		i--;
		write(1, "\n", 1);
	}
	else
		while (!(answer = compute_answer(a, argc, i)))
			i++;
	print_answer(answer, i);
	return (0);
}

int			main(int argc, char **argv)
{
	int			original[argc - 1];
	int			a[argc - 1];
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
	answer = NULL;
	return (low_main(a, argc, answer));
}
