/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:40:36 by gdinet            #+#    #+#             */
/*   Updated: 2021/07/12 14:36:58 by gdinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_op(t_stacks *st, char *line)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		swap_a(st, 0);
	else if (ft_strncmp(line, "sb", 3) == 0)
		swap_b(st, 0);
	else if (ft_strncmp(line, "ss", 3) == 0)
		swap_ab(st, 0);
	else if (ft_strncmp(line, "pa", 3) == 0)
		push_a(st, 0);
	else if (ft_strncmp(line, "pb", 3) == 0)
		push_b(st, 0);
	else if (ft_strncmp(line, "ra", 3) == 0)
		rotate_a(st, 0);
	else if (ft_strncmp(line, "rb", 3) == 0)
		rotate_b(st, 0);
	else if (ft_strncmp(line, "rr", 3) == 0)
		rotate_ab(st, 0);
	else if (ft_strncmp(line, "rra", 4) == 0)
		rev_rotate_a(st, 0);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rev_rotate_b(st, 0);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		rev_rotate_ab(st, 0);
	else
		return (error_exit(st));
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	st;
	char		*line;

	if (ac == 1)
		return (0);
	st.a = malloc(sizeof(int) * (ac - 1));
	st.a_len = 0;
	st.b = malloc(sizeof(int) * (ac - 1));
	st.b_len = 0;
	if (parse(ac, av, &st))
		return (0);
	while (get_next_line(0, &line))
	{
		if (exec_op(&st, line))
			return (0);
		free(line);
	}
	if (check_sorted(&st))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	clear_stacks(&st);
	return (0);
}
