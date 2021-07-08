/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 03:12:04 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 13:48:48 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		strisnum(char *str)
{
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

int		check_dupplicate(int *tab, int len, int n)
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

int		check_sorted(t_stacks *st)
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

int		parse(int ac, char **av, t_stacks *st)
{
	int		i;
	int		nb;

	i = 0;
	while (i < ac- 1)
	{
		if (!strisnum(av[i + 1]))
			return (error_exit(st));
		if (ft_atoi_ovf(av[i + 1], &nb) == -1)
			return (error_exit(st));
		if (check_dupplicate(st->a, st->a_len, nb))
			return (error_exit(st));
		st->a[i] = nb;
		st->a_len++;
		i++;
	}
	return (0);
}
