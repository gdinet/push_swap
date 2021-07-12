/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 06:21:09 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 12:12:01 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		return (0);
	st.a = malloc(sizeof(int) * (ac - 1));
	st.a_len = 0;
	st.b = malloc(sizeof(int) * (ac - 1));
	st.b_len = 0;
	if (parse(ac, av, &st))
		return (0);
	if (check_sorted(&st))
		return (0);
	if (st.a_len <= 10)
		insert_sort(&st);
	else if (st.a_len <= 200)
		chunk_sort(&st, 6);
	else
		chunk_sort(&st, 12);
	clear_stacks(&st);
	return (0);
}
