/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcounter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:17:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/12 15:19:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putcounter(unsigned long n)
{
	char	txtspc[22];
	int		ntxt;

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
