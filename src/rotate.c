/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:26:21 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 12:03:08 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_tab(int *tab, int len)
{
	int 	i;
	int		first;

	i = 0;
	first = tab[0];
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = first;
}

void	rotate_a(t_stacks *st, int print)
{
	rotate_tab(st->a, st->a_len);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stacks *st, int print)
{
	rotate_tab(st->b, st->b_len);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rotate_ab(t_stacks *st, int print)
{
	rotate_a(st, 0);
	rotate_b(st, 0);
	if (print)
		ft_putendl_fd("rr", 1);
}
