/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/05 15:14:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "libft.h"

# define SA 0
# define SB 1
# define PA 2
# define PB 3
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9

void					ps_error(void);
int						isintstring(char *str);

#endif
