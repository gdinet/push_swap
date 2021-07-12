/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 03:12:04 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 15:38:37 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	check_dupplicate(int *tab, int len, int n)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	check_sorted(t_stacks *st)
{
	int		i;

	i = 0;
	if (st->b_len != 0)
		return (0);
	while (i < st->a_len - 1)
	{
		if (st->a[i] > st->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	split_arg(char *arg, t_stacks *st)
{
	char	**tab;
	int		i;
	int		nb;

	tab = ft_split(arg, ' ');
	i = 0;
	while (tab[i])
	{
		if (ft_atoi_ovf(tab[i], &nb) == -1)
		{
			ft_free_split(tab);
			return (error_exit(st));
		}
		if (check_dupplicate(st->a, st->a_len, nb))
		{
			ft_free_split(tab);
			return (error_exit(st));
		}
		st->a[st->a_len] = nb;
		st->a_len++;
		i++;
	}
	return (0);
}

int	parse(int ac, char **av, t_stacks *st)
{
	int		i;

	i = 0;
	while (i < ac - 1)
	{
		if (split_arg(av[i + 1], st))
			return (1);
		i++;
	}
	return (0);
}
