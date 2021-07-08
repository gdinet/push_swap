/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:37:02 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/05 13:54:45 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_cpy(int *src, int *dst, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int		find_value(int *tab, int value, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int		value_to_pos(int *tab, int len)
{
	int		*sort;
	int		i;

	if (!(sort = malloc(sizeof(int) * len)))
		return (-1);
	tab_cpy(tab, sort, len);
	quick_sort(sort, 0, len - 1);
	i = 0;
	while (i < len)
	{
		tab[i] = find_value(sort, tab[i], len);
		if (tab[i] == -1)
		{
			free(sort);
			return (-1);
		}
		i++;
	}
	free(sort);
	return (0);
}
