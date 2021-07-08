/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:15:28 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 12:05:07 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *st, int print)
{
	if (st->b_len)
	{
		st->a_len++;
		st->a[st->a_len - 1] = st->b[0];
		rev_rotate_a(st, 0);
		rotate_b(st, 0);
		st->b_len--;
	}
	if (print)
		ft_putendl_fd("pa", 1);
}

void	push_b(t_stacks *st, int print)
{
	if (st->a_len)
	{
		st->b_len++;
		st->b[st->b_len - 1] = st->a[0];
		rev_rotate_b(st, 0);
		rotate_a(st, 0);
		st->a_len--;
	}
	if (print)
		ft_putendl_fd("pb", 1);
}
