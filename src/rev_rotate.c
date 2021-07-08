/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:31:40 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 12:02:28 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_tab(int *tab, int len)
{
	int		i;
	int		last;

	i = len - 1;
	last = tab[len - 1];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[i] = last;
}

void	rev_rotate_a(t_stacks *st, int print)
{
	rev_rotate_tab(st->a, st->a_len);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_stacks *st, int print)
{
	rev_rotate_tab(st->b, st->b_len);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rev_rotate_ab(t_stacks *st, int print)
{
	rev_rotate_a(st, 0);
	rev_rotate_b(st, 0);
	if (print)
		ft_putendl_fd("rrr", 1);
}
