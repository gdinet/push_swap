/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 06:22:57 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 12:03:37 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *st)
{
	if (st->a[1] < st->a[0])
		swap_a(st, 1);
}

void	sort_three(t_stacks *st)
{
	if (st->a[0] < st->a[2] && st->a[2] < st->a[1])
	{
		swap_a(st, 1);
		rotate_a(st, 1);
	}
	if (st->a[1] < st->a[0] && st->a[0] < st->a[2])
		swap_a(st, 1);
	if (st->a[2] < st->a[0] && st->a[0] < st->a[1])
		rev_rotate_a(st, 1);
	if (st->a[1] < st->a[2] && st->a[2] < st->a[0])
		rotate_a(st, 1);
	if (st->a[2] < st->a[1] && st->a[1] < st->a[0])
	{
		swap_a(st, 1);
		rev_rotate_a(st, 1);
	}
}

void	move_min(t_stacks *st)
{
	int		min;
	int		pos;
	int		i;

	min = st->a[0];
	pos = 0;
	i = 0;
	while (i < st->a_len)
	{
		if (st->a[i] < min)
		{
			min = st->a[i];
			pos = i;
		}
		i++;
	}
	while (st->a[0] != min)
	{
		if (pos < (st->a_len / 2 + 1))
			rotate_a(st, 1);
		else
			rev_rotate_a(st, 1);
	}
	push_b(st, 1);
}

void	insert_sort(t_stacks *st)
{
	if (st->a_len == 2)
		sort_two(st);
	else if (st->a_len == 3)
		sort_three(st);
	else if (st->a_len > 3)
	{
		move_min(st);
		insert_sort(st);
	}
	while (st->b_len > 0)
		push_a(st, 1);
}
