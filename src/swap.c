/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:07:11 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 12:05:37 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *st, int print)
{
	int		tmp;

	if (st->a_len > 1)
	{
		tmp = st->a[0];
		st->a[0] = st->a[1];
		st->a[1] = tmp;
	}
	if (print)
		ft_putendl_fd("sa", 1);
}

void	swap_b(t_stacks *st, int print)
{
	int		tmp;

	if (st->b_len > 1)
	{
		tmp = st->b[0];
		st->b[0] = st->b[1];
		st->b[1] = tmp;
	}
	if (print)
		ft_putendl_fd("sb", 1);
}

void	swap_ab(t_stacks *st, int print)
{
	swap_a(st, 0);
	swap_b(st, 0);
	if (print)
		ft_putendl_fd("ss", 1);
}
