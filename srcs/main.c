/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/05 16:51:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_original(int *original, int size, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		if (!isintstring(argv[i]))
			ps_error();
		original[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (original[i] == original[j])
				ps_error();
			j++;
		}
		i++;
	}
}

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

	write(1, "[", 1);
	i = 0;
	while (i < a_size)
	{
		ft_putnbr(a[(size - a_size) + i]);
		i++;
		i == a_size ? write(1, "\n", 1) : write(1, ", ", 2);
	}
	write(1, "]\n", 2);
}

int		check_a(int *a, int a_size, int size)
{
	int		i;

	if (a_size != size)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		if (a[i] != i)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	duplicate_a(int *dup_a, int *a, int size)
{
	int		i;

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

void	ps_swap(int size, int *one, int *two)
{
	int	temp;

	if (size < 2)
		return ;
	temp = *one;
	*one = *two;
	*two = temp;
}

int		a_operations(int *a, int a_size, int size, int ans_val)
{
	if (ans_val == SA)
		ps_swap(a_size, a + (size - a_size), a + (size - a_size) + 1);
	else if (ans_val == RA)
		ps_rotate(a, a_size, size);
	else if (ans_val == RRA)
		ps_rev_rotate(a, a_size, size);
	else if (ans_val == PA)
		return (1);
	return (0);
}

int		b_operations(int *b, int b_size, int size, int ans_val)
{
	if (ans_val == SB)
		ps_swap(b_size, b + (size - b_size), b + (size - b_size) + 1);
	else if (ans_val == RB)
		ps_rotate(b, b_size, size);
	else if (ans_val == RRB)
		ps_rev_rotate(b, b_size, size);
	else if (ans_val == PB)
		return (1);
	return (0);
}

int		check_answer(int *a, int size, int steps, int *answer)
{
	int		b[size];
	int		a_size;
	int		b_size;
	int		i;

	a_size = size;
	b_size = 0;
	i = -1;
	while (++i < steps)
	{
		if (a_size > 0 && a_operations(a, a_size, size, answer[i]))
		{
			b_size++;
			b[(size - b_size) + 0] = a[(size - a_size) + 0];
			a_size--;
		}
		if (b_size > 0 && b_operations(b, b_size, size, answer[i]))
		{
			a_size++;
			a[(size - a_size) + 0] = b[(size - b_size) + 0];
			b_size--;
		}
		if (answer[i] == RR)
		{
			ps_rotate(a, a_size, size);
			ps_rotate(b, b_size, size);
		}
		else if (answer[i] == RRR)
		{
			ps_rev_rotate(a, a_size, size);
			ps_rev_rotate(b, b_size, size);
		}
	}
	return (check_a(a, a_size, size));
}

void	leanificate_answer(int *ans, int steps)
{
	int		i;

	i = 0;
	while (i < steps - 1)
	{
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

int		*compute_answer(int *a, int size, int steps)
{
	int			i;
	int			ans[steps];
	int			dup_a[size];
	int			ans_count;

	ans_count = 0;
	ft_bzero(ans, steps * sizeof(int));
	ans[steps - 1] = -1;
	while (ans[0] < RRR)
	{
		write(1, "\r", 1);
		ft_putnbr(++ans_count);
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

int		main(int argc, char **argv)
{
	int			original[argc - 1];
	int			a[argc - 1];
	int			i;
	int			*answer;

	if (argc - 1 < 1)
		ps_error();
	if (argc - 1 == 1)
		return (0);
	get_original(original, --argc, ++argv);
	generate_a(original, a, argc);
	if (check_a(a, argc, argc))
		return (0);
	i = 0;
	while (!(answer = compute_answer(a, argc, ++i)))
		write(1, "\n", 1);
	write(1, "\n", 1);
	print_answer(answer, i);
	return (0);
}
