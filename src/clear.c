/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 05:57:45 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 12:03:05 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stacks(t_stacks *st)
{
	free(st->a);
	free(st->b);
}

int	error_exit(t_stacks *st)
{
	clear_stacks(st);
	ft_putstr_fd("Error\n", 2);
	return (1);
}
