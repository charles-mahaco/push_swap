/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:58:40 by charles           #+#    #+#             */
/*   Updated: 2021/07/01 14:58:41 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_duplicates(t_stack *s_a, t_stack *s_b)
{
	int i;
	int j;

	i = -1;
	while (++i < s_a->len)
	{
		j = -1;
		while (++j < s_a->len)
		{
			if (s_a->val[i] == s_a->val[j] && i != j)
			{
				write(1, "Error\n", 6);
				free(s_a->val);
				free(s_b->val);
				return(0);
			}
		}
	}
	return(1);
}

int		check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int check_argv(char *str, t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(&str[i]);
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	while (str[i])
	{
		if (str[i] < 47 || str[i] > 58)
		{
			write(1, "Error\n", 6);
			free(s_a->val);
			free(s_b->val);
			return(0);
		}
		i++;
	}
	if (len > 10 || (len == 10 && check_int_overflow(str)))
	{
		write(1, "Error\n", 6);
		free(s_a->val);
		free(s_b->val);
		return (0);
	}
	return(1);
}

void	stack_init(t_stack *s, int len, char id)
{
	if (!(s->val = ft_calloc(sizeof(*s->val) + 1, len)))
		malloc_error();
	s->stack_id = id;
	if (s->stack_id == 'a')
		s->len = len;
	else
		s->len = 0;
	s->len_max = len;
	s->lowest = 0;
	s->highest = 0;
	s->midpoint = 0;
	s->sort_turn = 0;
	s->sort_step = 0.25;
	s->sorted_ahead = 0;
	s->high_sorted_ahead = 0;
	s->previous_midpoint = 0;
	s->possible_rr = 0;
}
