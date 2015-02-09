/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:00:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/09 15:42:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_strjoinfree(char **line, char *add)
{
	char	*to_free;

	to_free = *line;
	*line = ft_strjoin(*line, add);
	free(to_free);
}

static int	is_options(char *str)
{
	while (*str != '\0' && ft_strchr(ALL_OPTIONS, *str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int			deal_options(char *str, int input)
{
	static char		*options = NULL;

	if (!input)
		return (ft_strchr(options, *str) ? 1 : 0);
	if (!options)
		options = ft_strnew(0);
	if (*str == '-' && is_options(str + 1))
	{
		ft_strjoinfree(&options, str + 1);
		return (1);
	}
	return (0);
}
