/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 05:20:27 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/04 06:09:32 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *tab, int first, int last)
{
	int		i;
	int		j;

	if (first < last)
	{
		i = first;
		j = last;
		while (i < j)
		{
			while (tab[i] <= tab[first] && i < last)
				i++;
			while (tab[j] > tab[first])
				j--;
			if (i < j)
				swap_int(&tab[i], &tab[j]);
		}
		swap_int(&tab[first], &tab[j]);
		quick_sort(tab, first, j - 1);
		quick_sort(tab, j + 1, last);
	}
}
