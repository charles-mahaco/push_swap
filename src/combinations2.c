/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:00:08 by charles           #+#    #+#             */
/*   Updated: 2021/06/30 17:00:09 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *s_a, t_stack *s_b)
{
	int	tmp;

	if (s_a->len > 1)
	{
		tmp = s_a->val[0];
		s_a->val[0] = s_a->val[1];
		s_a->val[1] = tmp;
	}
	if (s_b->len > 1)
	{
		tmp = s_b->val[0];
		s_b->val[0] = s_b->val[1];
		s_b->val[1] = tmp;
	}
	if (s_a->stack_id)
		write(1, "ss\n", 3);
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	int	len;
	int	tmp;

	if (s_a->len > 1)
	{
		len = -1;
		tmp = s_a->val[0];
		while (++len < s_a->len)
			s_a->val[len] = s_a->val[len + 1];
		s_a->val[len - 1] = tmp;
	}
	if (s_b->len > 1)
	{
		len = -1;
		tmp = s_b->val[0];
		while (++len < s_b->len)
			s_b->val[len] = s_b->val[len + 1];
		s_b->val[len - 1] = tmp;
	}
	if (s_a->stack_id)
		write(1, "rr\n", 3);
	if (s_a->possible_rr)
		s_a->possible_rr--;
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	int	len;
	int	tmp;

	if (s_a->len > 1)
	{
		len = s_a->len;
		tmp = s_a->val[len - 1];
		while (--len > 0)
			s_a->val[len] = s_a->val[len - 1];
		s_a->val[0] = tmp;
	}
	if (s_b->len > 1)
	{
		len = s_b->len;
		tmp = s_b->val[len - 1];
		while (--len > 0)
			s_b->val[len] = s_b->val[len - 1];
		s_b->val[0] = tmp;
	}
	if (s_a->stack_id)
		write(1, "rrr\n", 4);
}
