/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:57:56 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 15:54:08 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(ft_isdigit(*str) || *str == ' ' || *str == '+' || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

int	nbword(char *s)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && (i == 0 || s[i - 1] == ' '))
			nb++;
		i++;
	}
	return (nb);
}

int	size_stack(int ac, char **av)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (i < ac)
	{
		if (check_str(av[i]) == 0)
			return (-1);
		size += nbword(av[i]);
		i++;
	}
	return (size);
}

int	init_stack(int ac, char **av, t_stacks *st)
{
	int	size;

	size = size_stack(ac, av);
	if (size == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	st->a_len = 0;
	st->b_len = 0;
	st->a = malloc(sizeof(int) * (size));
	if (!st->a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	st->b = malloc(sizeof(int) * (size));
	if (!st->b)
	{
		free(st->a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
