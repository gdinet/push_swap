/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:11:11 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 15:30:57 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int		move_top(t_stacks *st, int max)
{
	int		i;
	int		first;
	int		last;

	if (st->a_len == 0)
		return (0);
	if (st->a[0] <= max)
		return (1);
	i = 1;
	first = -1;
	last = -1;
	while (i < st->a_len && first == -1 && last == -1)
	{
		if (st->a[i] <= max)
			first = st->a[i];
		if (st->a[st->a_len - i] <= max)
			last = st->a[st->a_len - i];
		i++;
	}
	while (first != -1 && st->a[0] != first)
		rotate_a(st, 1);
	while (first == -1 && last != -1 && st->a[0] != last)
		rev_rotate_a(st, 1);
	return (first != -1 || last != -1);
}

int		pos_smaller(t_stacks *st, int to_push)
{
	int		max;
	int		smaller;
	int		pos;
	int		i;

	max = st->b[0];
	smaller = -1;
	pos = 0;
	i = 0;
	while (i < st->b_len)
	{
		if (st->b[i] > max && smaller == -1)
		{
			max = st->b[i];
			pos = i;
		}
		if (st->b[i] < to_push && st->b[i] > smaller)
		{
			smaller = st->b[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	set_b(t_stacks *st, int to_push)
{
	int		pos;
	int		top;

	if (st->b_len)
	{
		pos = pos_smaller(st, to_push);
		top = st->b[pos];
		while (st->b[0] != top)
		{
			if (pos < (st->b_len / 2 + 1))
				rotate_b(st, 1);
			else
				rev_rotate_b(st, 1);
		}
	}
}

void	chunk_sort(t_stacks *st, int chunk)
{
	int		max_chunk;

	value_to_pos(st->a, st->a_len);
	max_chunk = (st->a_len + st->b_len) / chunk;
	while (st->a_len)
	{
		while (move_top(st, max_chunk))
		{
			set_b(st, st->a[0]);
			push_b(st, 1);
		}
		max_chunk += (st->a_len + st->b_len) / chunk;
	}
	set_b(st, st->a_len + st->b_len);
	while (st->b_len)
		push_a(st, 1);
}
