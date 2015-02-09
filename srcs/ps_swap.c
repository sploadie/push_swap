/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:42:39 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 14:46:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(int size, int *one, int *two)
{
	int	temp;

	if (size < 2)
		return ;
	temp = *one;
	*one = *two;
	*two = temp;
}
