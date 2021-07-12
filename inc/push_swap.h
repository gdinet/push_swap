/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:57:03 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 15:54:53 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

struct	s_stacks
{
	int		*a;
	int		a_len;
	int		*b;
	int		b_len;
};

typedef struct s_stacks	t_stacks;

void	swap_a(t_stacks *st, int print);
void	swap_b(t_stacks *st, int print);
void	swap_ab(t_stacks *st, int print);
void	push_a(t_stacks *st, int print);
void	push_b(t_stacks *st, int print);
void	rotate_a(t_stacks *st, int print);
void	rotate_b(t_stacks *st, int print);
void	rotate_ab(t_stacks *st, int print);
void	rev_rotate_a(t_stacks *st, int print);
void	rev_rotate_b(t_stacks *st, int print);
void	rev_rotate_ab(t_stacks *st, int print);

int		init_stack(int ac, char **av, t_stacks *st);
int		parse(int ac, char **av, t_stacks *st);
int		check_sorted(t_stacks *st);
void	clear_stacks(t_stacks *st);
int		error_exit(t_stacks *st);

void	insert_sort(t_stacks *st);
void	quick_sort(int *tab, int first, int last);
int		value_to_pos(int *tab, int len);
void	chunk_sort(t_stacks *st, int chunk);

void	print_game(t_stacks *st);

#endif
