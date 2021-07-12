/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 06:21:09 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 15:54:17 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		return (0);
	if (init_stack(ac, av, &st))
		return (0);
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
