/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:33:25 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/08 14:33:52 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>
void	print_game(t_stacks *st)
{
	int i = 0;
	printf("Pile a :\n");
	while (i < st->a_len)
	{
		printf("%d ", st->a[i]);
		i++;
	}
	i = 0;
	printf("\nPile b :\n");
	while (i < st->b_len)
	{
		printf("%d ", st->b[i]);
		i++;
	}
	printf("\n");
}
