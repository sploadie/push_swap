/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isintstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:16:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/03 16:18:57 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isintstring(char *str)
{
	if (str[0] == '-' && str[1] != '\0')
		str++;
	while (!str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}