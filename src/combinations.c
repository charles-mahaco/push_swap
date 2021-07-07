/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:02:08 by charles           #+#    #+#             */
/*   Updated: 2021/06/22 21:02:10 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *s)
{
	int	tmp;

	if (s->len > 1)
	{
		tmp = s->val[0];
		s->val[0] = s->val[1];
		s->val[1] = tmp;
	}
	if (s->stack_id == 'a')
		write(1, "sa\n", 3);
	else if (s->stack_id == 'b')
		write(1, "sb\n", 3);
}

void	pab(t_stack *s_a, t_stack *s_b)
{
	int	len;

	if (s_b->len > 0)
	{
		len = s_a->len + 1;
		s_a->val[len] = '\0';
		while (--len > 0)
			s_a->val[len] = s_a->val[len - 1];
		s_a->val[0] = s_b->val[0];
		len = -1;
		while (++len < s_b->len)
			s_b->val[len] = s_b->val[len + 1];
		s_a->len++;
		s_b->len--;
	}
	if (s_a->stack_id == 'a')
		write(1, "pa\n", 3);
	else if (s_a->stack_id == 'b')
		write(1, "pb\n", 3);
}

void	rab(t_stack *s_a)
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
		if (s_a->possible_rr)
			s_a->possible_rr--;
	}
	if (s_a->stack_id == 'a')
		write(1, "ra\n", 3);
	else if (s_a->stack_id == 'b')
		write(1, "rb\n", 3);
}

void	rrab(t_stack *s_a)
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
	if (s_a->stack_id == 'a')
		write(1, "rra\n", 4);
	else if (s_a->stack_id == 'b')
		write(1, "rrb\n", 4);
}
