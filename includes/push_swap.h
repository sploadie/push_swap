/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/11 14:37:28 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "libft.h"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define ALL_OPTIONS "v"

void			ps_error(void);
int				isintstring(char *str);
void			get_original(int *original, int size, char **argv);
void			print_answer(int *answer, int steps);
void			generate_a(int *original, int *a, int size);
void			print_a(int *a, int a_size, int size);
int				check_a(int *a, int a_size, int size);
void			duplicate_a(int *dup_a, int *a, int size);
void			ps_rotate(int *a, int a_size, int size);
void			ps_rev_rotate(int *a, int a_size, int size);
void			ps_swap(int size, int *one, int *two);
void			a_operations(int *a, int *b, int *sizes, int ans_val);
void			b_operations(int *a, int *b, int *sizes, int ans_val);
void			ps_dual_rotate(int *a, int *b, int *sizes);
void			ps_dual_rev_rotate(int *a, int *b, int *sizes);
int				*compute_answer(int *a, int size, int steps);
int				*verbose_compute_answer(int *a, int size, int steps);
int				deal_options(char *str, int input);

#endif
