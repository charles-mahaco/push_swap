/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:54:22 by charles           #+#    #+#             */
/*   Updated: 2021/06/30 14:54:24 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shortest_path(t_stack *s_a, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (s_a->val[i] == s_a->lowest)
			s_a->low_path = i;
		else if (s_a->val[i] == s_a->highest)
			s_a->high_path = i;
	}
	if (s_a->low_path > len / 2)
		s_a->real_low_path = abs_value(s_a->low_path - len) + 1;
	else
		s_a->real_low_path = s_a->low_path;
	if (s_a->high_path > len / 2)
		s_a->real_high_path = abs_value(s_a->high_path - len) + 1;
	else
		s_a->real_high_path = s_a->high_path;
}

void	get_limits(t_stack *s_a, int len)
{
	int	i;
	int	tmp;
	int	*copy;

	copy = ft_calloc(sizeof(int), len + 1);
	i = -1;
	while (++i < len)
		copy[i] = s_a->val[i];
	i = -1;
	while (++i < len - 1)
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = -1;
		}
	}
	s_a->highest = copy[len - 1];
	s_a->lowest = copy[0];
	free(copy);
	shortest_path(s_a, len);
}

void	sort_median(t_stack *s_a, int len)
{
	int	i;
	int	tmp;
	int	*copy;

	copy = ft_calloc(sizeof(int), len + 1);
	s_a->sort_turn += s_a->sort_step;
	i = -1;
	while (++i < len)
		copy[i] = s_a->val[i];
	i = -1;
	while (++i < len - 1)
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = -1;
		}
	}
	s_a->midpoint = copy[(int)(len * s_a->sort_turn)];
	if (s_a->sort_turn >= 1)
		s_a->midpoint = copy[len - 1];
	free(copy);
}

int	is_sorted(t_stack *s_a, t_stack *s_b, int to_free)
{
	int		i;

	i = -1;
	while (++i < s_a->len - 1)
	{
		if (s_a->val[i] > s_a->val[i + 1])
			return (0);
	}
	if (to_free)
	{
		free(s_a->val);
		free(s_b->val);
	}
	return (1);
}

int	is_next_low_high(t_stack *s_b, int high)
{
	int	i;

	i = -1;
	while (++i < s_b->len)
	{
		if (high)
		{
			if (s_b->val[i] != s_b->highest && s_b->val[i] > s_b->val[0])
				return (0);
		}
		else
		{
			if (s_b->val[i] != s_b->lowest && s_b->val[i] < s_b->val[0])
				return (0);
		}
	}
	return (1);
}
