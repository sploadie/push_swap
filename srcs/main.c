/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/05 14:56:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

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
	isunique(original, argc);
}

void	print_answer(int *answer, int steps)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		if (answer[i] == SA)
			ft_putstr("sa");
		else if (answer[i] == SB)
			ft_putstr("sb");
		else if (answer[i] == PA)
			ft_putstr("pa");
		else if (answer[i] == PB)
			ft_putstr("pb");
		else if (answer[i] == RA)
			ft_putstr("ra");
		else if (answer[i] == RB)
			ft_putstr("rb");
		else if (answer[i] == RR)
			ft_putstr("rr");
		else if (answer[i] == RRA)
			ft_putstr("rra");
		else if (answer[i] == RRB)
			ft_putstr("rrb");
		else if (answer[i] == RRR)
			ft_putstr("rrr");
		else
		{
			// ft_putstr("Error?!\n");//FIXME
			// exit(0);//FIXME
		}
		i++;
		if (i == steps)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
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

void	print_a(int *a, int a_size, int size)
{
	int		i;

	i = 0;
	while (i < a_size)
	{
		ft_putnbr(a[(size - a_size) + i]);
		ft_putstr(", ");
		i++;
	}
	write(1, "\n", 1);
}

int		check_a(int *a, int a_size, int size)
{
	int		i;

	// ft_putstr("check_a: ");//FIXME
	if (a_size != size)
	{
		// ft_putstr("fail\n");//FIXME
		return (0);
	}
	i = 0;
	while (i < size)
	{
		if (a[i] != i)
		{
			// ft_putstr("fail\n");//FIXME
			return (0);
		}
		i++;
	}
	// ft_putstr("success\n");//FIXME
	return (1);
}

void	duplicate_a(int *dup_a, int *a, int size)
{
	int		i;

	// ft_putstr("duplicate_a\n");//FIXME
	i = 0;
	while (i < size)
	{
		dup_a[i] = a[i];
		i++;
	}
}

void	ps_rotate(int *a, int a_size, int size)
{
	int		i;
	int		temp;

	if (a_size < 2)
		return ;
	temp = a[(size - a_size) + 0];
	i = 0;
	while (i < a_size - 1)
	{
		a[(size - a_size) + i] = a[(size - a_size) + i + 1];
		i++;
	}
	a[(size - a_size) + i] = temp;
}

void	ps_rev_rotate(int *a, int a_size, int size)
{
	int		i;
	int		temp;
	int		temp2;

	if (a_size < 2)
		return ;
	temp = a[(size - a_size) + 0];
	a[(size - a_size) + 0] = a[(size - a_size) + (a_size - 1)];
	i = 0;
	while (i < a_size - 1)
	{
		temp2 = temp;
		temp = a[(size - a_size) + i + 1];
		a[(size - a_size) + i + 1] = temp2;
		i++;
	}
	a[(size - a_size) + 0] = temp;
}

int		check_answer(int *a, int size, int steps, int *answer)
{
	int		b[size];
	int		a_size;
	int		b_size;
	int		i;
	int		temp;

	// ft_putstr("check_answer\n");//FIXME
	a_size = size;
	b_size = 0;
	i = 0;
	while (i < steps)
	{
		if (answer[i] == SA)
		{
			if (a_size >= 2)
			{
				temp = a[(size - a_size) + 0];
				a[(size - a_size) + 0] = a[(size - a_size) + 1];
				a[(size - a_size) + 1] = temp;
			}
		}
		else if (answer[i] == SB)
		{
			if (b_size >= 2)
			{
				temp = b[(size - b_size) + 0];
				b[(size - b_size) + 0] = b[(size - b_size) + 1];
				b[(size - b_size) + 1] = temp;
			}
		}
		else if (answer[i] == PA)
		{
			if (a_size >= 1)
			{
				b_size++;
				b[(size - b_size) + 0] = a[(size - a_size) + 0];
				a_size--;
			}
		}
		else if (answer[i] == PB)
		{
			if (b_size >= 1)
			{
				a_size++;
				a[(size - a_size) + 0] = b[(size - b_size) + 0];
				b_size--;
			}
		}
		else if (answer[i] == RA)
		{
			ps_rotate(a, a_size, size);
		}
		else if (answer[i] == RB)
		{
			ps_rotate(b, b_size, size);
		}
		else if (answer[i] == RR)
		{
			ps_rotate(a, a_size, size);
			ps_rotate(b, b_size, size);
		}
		else if (answer[i] == RRA)
		{
			ps_rev_rotate(a, a_size, size);
		}
		else if (answer[i] == RRB)
		{
			ps_rev_rotate(b, b_size, size);
		}
		else if (answer[i] == RRR)
		{
			ps_rev_rotate(a, a_size, size);
			ps_rev_rotate(b, b_size, size);
		}
		else
		{
			// ft_putstr("Error?!\n");//FIXME
			// exit(0);//FIXME
		}
		i++;
	}
	// ft_putstr("?: ");//FIXME
	// print_answer(answer, steps);//FIXME
	// ft_putstr("a: ");//FIXME
	// print_a(a, a_size, size);//FIXME
	// ft_putstr("b: ");//FIXME
	// print_a(b, b_size, size);//FIXME
	// sleep(1);//FIXME
	return (check_a(a, a_size, size));
}

int		*compute_answer(int *a, int size, int steps)
{
	int			i;
	int			answer[steps];
	int			dup_a[size];
	int			answer_count;//FIXME

	answer_count = 0;//FIXME
	// ft_putstr("compute_answer\n");//FIXME
	ft_bzero(answer, steps * sizeof(int));
	answer[steps - 1] = -1; //SETUP
	while (answer[0] < RRR)
	{
		//DATA MINING FIXME
		// write(1, "\33[2K\r", 5);//FIXME
		// write(1, "\r", 1);//FIXME
		// ft_putnbr(++answer_count);//FIXME
		printf("\r%d", ++answer_count);
		//DATA MINING FIXME
		i = steps - 1;
		answer[steps - 1] += 1;
		while (i != 0 && answer[i] > RRR)
		{
			answer[i] = SA;
			answer[i - 1] += 1;
			i--;
		}
		//SHORTCUTS
		i = 0;
		while (i < steps - 1)
		{
			if ((answer[i] == SA || answer[i] == SB) && (answer[i] == answer[i + 1]))
			{
				answer[i + 1] += 1;
			}
			if ((answer[i] >= RA && answer[i] <= RR) && answer[i + 1] >= RRA)
			{
				answer[i] += 1;
				answer[i + 1] = SA;
			}
			if (answer[i] >= RRA && (answer[i + 1] >= RA && answer[i + 1] <= RR))
			{
				answer[i + 1] = RRA;
			}
			i++;
		}
		//SHORTCUTS END
		duplicate_a(dup_a, a, size);
		if (check_answer(dup_a, size, steps, answer))
		{
			return (ft_memdup(answer, steps * sizeof(int)));
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
		// ft_putstr("Done.\n");//FIXME
		return (0);
	}
	argc--;
	argv++;
	// ft_putstr("get_original\n");//FIXME
	get_original(original, argc, argv);
	// ft_putstr("generate_a\n");//FIXME
	generate_a(original, a, argc);
	// print_a(a, argc, argc);//FIXME
	if (check_a(a, argc, argc))
	{
		// ft_putstr("Done.\n");//FIXME
		return (0);
	}
	// ft_putstr("Loop Start:\n");//FIXME
	ft_putstr("Operations: 1\n");//FIXME
	i = 1;
	while (!(answer = compute_answer(a, argc, i)))
	{
		i++;
		write(1, "\n", 1);//FIXME
		ft_putstr("Operations: ");//FIXME
		ft_putnbr(i);//FIXME
		write(1, "\n", 1);//FIXME
	}
	// ft_putstr("Loop End\n");//FIXME
	write(1, "\n", 1);//FIXME
	print_answer(answer, i);
	return (0);
}
