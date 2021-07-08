/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:11:11 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 16:30:48 by gdinet           ###   ########.fr       */
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
		return (-1);
	if (st->a[0] <= max)
		return (0);
	i = 1;
	first = -1;
	last = -1;
	while (i < st->a_len && first == -1 && last == -1)
	{
		if (st->a[i] <= max)
			first = i;
		if (st->a[st->a_len - i] <= max)
			last = st->a_len - i;
		i++;
	}
	if (first != -1)
		return (first);
	if (last != -1)
		return (last);
	return (-1);
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

void	rotate_stacks(t_stacks *st, int pos_a, int pos_b)
{
	if (pos_a >= (st->a_len / 2 + 1))
		pos_a = pos_a - st->a_len;
	if (pos_b >= (st->b_len / 2 + 1))
		pos_b = pos_b - st->b_len;
	while (pos_a != 0 || pos_b != 0)
	{
		if (pos_a > 0 && pos_b > 0)
			rotate_ab(st, pos_a-- && pos_b--);
		else if (pos_a < 0 && pos_b < 0)
			rev_rotate_ab(st, pos_a++ && pos_b++);
		else if (pos_a > 0)
			rotate_a(st, pos_a--);
		else if (pos_a < 0)
			rev_rotate_a(st, pos_a++);
		else if (pos_b > 0)
			rotate_b(st, pos_b--);
		else if (pos_b < 0)
			rev_rotate_b(st, pos_b++);
	}
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
	int		pos_a;

	value_to_pos(st->a, st->a_len);
	max_chunk = (st->a_len + st->b_len) / chunk;
	while (st->a_len)
	{
		while ((pos_a = move_top(st, max_chunk)) != -1)
		{
			rotate_stacks(st, pos_a, pos_smaller(st, st->a[pos_a]));
			push_b(st, 1);
		}
		max_chunk += (st->a_len + st->b_len) / chunk;
	}
	set_b(st, st->a_len + st->b_len);
	while (st->b_len)
		push_a(st, 1);
}
