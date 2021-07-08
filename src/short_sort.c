/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:28:39 by charles           #+#    #+#             */
/*   Updated: 2021/06/30 14:28:41 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *s_a, t_stack *s_b, int len)
{
	if (len == 2 && (s_a->val[0] > s_a->val[1]))
		sab(s_a);
	if (len == 3)
		sort_three(s_a);
	if (len == 4)
		sort_four(s_a, s_b);
	if (len == 5)
		sort_five(s_a, s_b);
}

void	sort_five(t_stack *s_a, t_stack *s_b)
{
	s_a->sort_step = 0.5;
	sort_median(s_a, s_a->len);
	while (s_a->len > 3)
	{
		if (s_a->val[0] < s_a->midpoint)
			pab(s_b, s_a);
		else
			rab(s_a);
	}
	sort_three(s_a);
	if (s_b->val[0] < s_b->val[1])
		sab(s_b);
	pab(s_a, s_b);
	pab(s_a, s_b);
}

void	sort_four(t_stack *s_a, t_stack *s_b)
{
	get_limits(s_a, s_a->len);
	while (s_a->val[0] != s_a->lowest)
		rab(s_a);
	if (!is_sorted(s_a, s_b, 0))
	{
		pab(s_b, s_a);
		sort_three(s_a);
		pab(s_a, s_b);
	}
}

void	sort_three(t_stack *s_a)
{
	if (s_a->val[0] > s_a->val[1] && s_a->val[1] < s_a->val[2]
		&& s_a->val[0] < s_a->val[2])
		sab(s_a);
	if (s_a->val[0] > s_a->val[1] && s_a->val[1] > s_a->val[2]
		&& s_a->val[0] > s_a->val[2])
	{
		sab(s_a);
		rrab(s_a);
	}
	if (s_a->val[0] > s_a->val[1] && s_a->val[1] < s_a->val[2]
		&& s_a->val[0] > s_a->val[2])
		rab(s_a);
	if (s_a->val[0] < s_a->val[1] && s_a->val[1] > s_a->val[2]
		&& s_a->val[0] < s_a->val[2])
	{
		sab(s_a);
		rrab(s_a);
	}
	if (s_a->val[0] < s_a->val[1] && s_a->val[1] > s_a->val[2]
		&& s_a->val[0] > s_a->val[2])
		rrab(s_a);
}

void	large_sort(t_stack *s_a, t_stack *s_b)
{
	sort_median(s_a, s_a->len_max);
	while (s_b->len != (int)(s_a->len_max * s_a->sort_turn))
	{
		if (s_a->val[0] < s_a->midpoint)
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
	large_sort_b(s_a, s_b);
}
