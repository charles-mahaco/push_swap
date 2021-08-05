/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:45:00 by charles           #+#    #+#             */
/*   Updated: 2021/06/30 16:45:03 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}

void	wrong_instruction(t_stack *s_a, t_stack *s_b, char *line)
{
	free(line);
	free(s_a->val);
	free(s_b->val);
	write(1, "Error\n", 6);
	exit(1);
}

void	do_instruction(t_stack *s_a, t_stack *s_b, char *line)
{
	if (!ft_strcmp(line, "pb"))
		pab(s_b, s_a);
	else if (!ft_strcmp(line, "pa"))
		pab(s_a, s_b);
	else if (!ft_strcmp(line, "ra"))
		rab(s_a);
	else if (!ft_strcmp(line, "rb"))
		rab(s_b);
	else if (!ft_strcmp(line, "rra"))
		rrab(s_a);
	else if (!ft_strcmp(line, "rrb"))
		rrab(s_b);
	else if (!ft_strcmp(line, "rr"))
		rr(s_a, s_b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(s_a, s_b);
	else if (!ft_strcmp(line, "sa"))
		sab(s_a);
	else if (!ft_strcmp(line, "sb"))
		sab(s_b);
	else if (!ft_strcmp(line, "ss"))
		ss(s_a, s_b);
	else
		wrong_instruction(s_a, s_b, line);
}

void	get_instruction(t_stack *s_a, t_stack *s_b)
{
	char	*line;

	while (get_next_line(0, &line, 0))
	{
		do_instruction(s_a, s_b, line);
		free(line);
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	int		j;

	j = 0;
	if (argc == 1)
		return (0);
	stack_init(&s_a, argc - 1, 'c');
	stack_init(&s_b, argc - 1, '\0');
	while (++j < argc)
	{
		if (!check_argv(argv[j], &s_a, &s_b))
			return (0);
		s_a.val[j - 1] = ft_atoi(argv[j]);
	}
	if (!check_duplicates(&s_a, &s_b))
		return (0);
	get_instruction(&s_a, &s_b);
	if (s_b.len == 0 && is_sorted(&s_a, &s_b, 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(s_a.val);
	free(s_b.val);
	return (0);
}
