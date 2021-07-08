/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:02:01 by charles           #+#    #+#             */
/*   Updated: 2021/06/22 21:02:03 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_to_be_sorted(t_stack *s_b)
{
	int	to_be_sorted;

	s_b->bottom = 0;
	get_limits(s_b, s_b->len);
	if (s_b->real_low_path < s_b->real_high_path)
	{
		to_be_sorted = s_b->lowest;
		if (s_b->low_path > s_b->len / 2)
			s_b->bottom = 1;
	}
	else
	{
		to_be_sorted = s_b->highest;
		if (s_b->high_path > s_b->len / 2)
			s_b->bottom = 1;
	}
	return (to_be_sorted);
}

void	do_shortest_path(t_stack *s_a, t_stack *s_b, int to_be_sorted)
{
	while (s_b->val[0] != to_be_sorted)
	{
		if (s_b->len > 25 && s_b->sorted_ahead < 2
			&& ((to_be_sorted == s_b->lowest && is_next_low_high(s_b, 0))
				|| (to_be_sorted == s_b->highest && is_next_low_high(s_b, 1))))
		{
			while (s_a->possible_rr)
				rab(s_a);
			pab(s_a, s_b);
			s_b->sorted_ahead++;
		}
		if (s_b->bottom)
			rrab(s_b);
		else
		{
			if (s_a->possible_rr)
				while (s_a->possible_rr)
					rr(s_a, s_b);
			else
				rab(s_b);
		}
	}
	while (s_a->possible_rr)
		rab(s_a);
}

void	do_sorted_ahead(t_stack *s_a, t_stack *s_b, int to_be_sorted)
{
	if (s_b->sorted_ahead == 2 && to_be_sorted == s_b->highest)
	{
		rab(s_a);
		pab(s_a, s_b);
		sab(s_a);
		rrab(s_a);
	}
	else if (s_b->sorted_ahead == 2 && to_be_sorted == s_b->lowest)
	{
		sab(s_a);
		pab(s_a, s_b);
		rab(s_a);
		rab(s_a);
	}
	else
		pab(s_a, s_b);
	if (to_be_sorted == s_b->lowest)
		s_a->possible_rr++;
	if (s_b->sorted_ahead == 1 && to_be_sorted == s_b->lowest)
		s_a->possible_rr++;
	else if (s_b->sorted_ahead == 1 && to_be_sorted == s_b->highest)
		sab(s_a);
	s_b->sorted_ahead = 0;
}

void	fill_b(t_stack *s_a, t_stack *s_b)
{
	while (s_a->val[0] < s_a->previous_midpoint)
		rab(s_a);
	while (s_a->val[0] >= s_a->previous_midpoint)
	{
		if (s_a->val[0] < s_a->midpoint && s_a->sort_turn <= 1)
			pab(s_b, s_a);
		else
		{
			get_limits(s_b, s_b->len);
			if (s_b->val[0] != s_b->lowest && s_b->val[0] != s_b->highest)
				rr(s_a, s_b);
			else
				rab(s_a);
		}
	}
	if (s_a->sort_turn < 1)
	{
		while (s_a->val[0] < s_a->previous_midpoint)
			rab(s_a);
		else
			if (s_a->sort_turn >= 1)
				rrab(s_a);
	}
}

void	large_sort_b(t_stack *s_a, t_stack *s_b)
{
	int	to_be_sorted;

	while (s_b->len > 0)
	{
		to_be_sorted = get_to_be_sorted(s_b);
		do_shortest_path(s_a, s_b, to_be_sorted);
		do_sorted_ahead(s_a, s_b, to_be_sorted);
	}
	s_a->previous_midpoint = s_a->midpoint;
	sort_median(s_a, s_a->len_max);
	fill_b(s_a, s_b);
	if (s_a->sort_turn <= 1)
		large_sort_b(s_a, s_b);
	else if (s_a->sort_turn > 1)
		rab(s_a);
}
