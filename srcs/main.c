/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/03 19:02:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_original(int *original, int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!isintstring(argv[i]))
			ps_error();
		original[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	isunique(int *array, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				ps_error();
			j++;
		}
		i++;
	}
	temp = array[0];
}

void	generate_a(int *original, int *a, int size)
{
	int		i;
	int		j;
	int		value;
	int		count;

	i = 0;
	while (i < size)
	{
		value = original[i];
		count = 0;
		j = 0;
		while (j < size)
		{
			if (original[j] < value)
				count++;
			j++;
		}
		a[i] = count;
		i++;
	}
}

int		check_answer(int *a, int size, int steps, int *answer)
{
	int		b[steps];
	int		a_size;
	int		b_size;
	int		i;
	int		temp;

	a_size = size;
	b_size = 0;
	i = 0;
	while (i < steps)
	{
		if (steps[i] == SA)
		{
			if (a_size >= 2)
			{
				temp = a[0];
				a[0] = a[1];
				a[1] = temp;
			}
		}
		else if (steps[i] == SB)
		{
			if (b_size >= 2)
			{
				temp = b[0];
				b[0] = b[1];
				b[1] = temp;
			}
		}
		else if (steps[i] == PA)
		{
			;
		}
		else if (steps[i] == PB)
		{
			;
		}
		else if (steps[i] == RA)
		{
			;
		}
		else if (steps[i] == RB)
		{
			;
		}
		else if (steps[i] == RR)
		{
			;
		}
		else if (steps[i] == RRA)
		{
			;
		}
		else if (steps[i] == RRB)
		{
			;
		}
		else if (steps[i] == RRR)
		{
			;
		}
		i++;
	}
	i = 0;
	if (a_size != size)
		return (0);
	while (i < size)
	{
		if (a[(top + i) % size] != i)
			return (0);
	}
	return (1);
}

int		*compute_answer(int *a, int size, int steps)
{
	int			i;
	int			answer[steps];

	ft_bzero(answer, steps * sizeof(t_operation));
	answer[steps - 1] = -1;
	while (answer[0] != RRR)
	{
		i = steps - 1;
		answer[i] += 1;
		while (i != 0 && answer[i] > RRR)
		{
			answer[i] = SA;
			answer[i - 1] += 1;
			i--;
		}

	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	int			original[argc - 1];
	int			a[argc - 1];
	int			i;
	int			*answer;

	if (argc - 1 < 1)
		ps_error();
	if (argc - 1 == 1)
	{
		ft_putstr("Done.\n");
		return (0);
	}
	argc--;
	argv++;
	get_original(original, argc, argv);
	isunique(original, argc);
	generate_a(original, a, argc);
	i = 1;
	while (!(answer = compute_answer(a, argc, i)))
		i++;
	print_answer(answer, i);
	return (0);
}
