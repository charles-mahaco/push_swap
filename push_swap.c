/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:01:53 by charles           #+#    #+#             */
/*   Updated: 2021/06/22 21:01:55 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	int j;

	j = 1;
	if (argc == 1)
		return (0);
	stack_init(&s_a, argc - 1, 'a');
	stack_init(&s_b, argc - 1, 'b');
	while (j < argc)
	{
		if (!check_argv(argv[j], &s_a, &s_b))
			return (0);
		s_a.val[j-1] = ft_atoi(argv[j]);
		j++;
	}
	s_a.val[j-1] = '\0';
	if (!check_duplicates(&s_a, &s_b) || is_sorted(&s_a, &s_b, 1))
		return (0);
	if (argc < 7)
		short_sort(&s_a, &s_b, argc - 1);
	else
		large_sort(&s_a, &s_b);
	free(s_a.val);
	free(s_b.val);
	return (0);
}
