/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:29:49 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/12 11:30:08 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap_stacks(t_stack *a, t_stack *b)
{
	if (a->list[0] > a->list[1] && b->list[0] < b->list[1]
			&& a->size > 1 && b->size > 1)
		ss(a, b);
	else if (a->list[0] > a->list[1] && a->size > 1)
		sa(a);
	else if (b->list[0] < b->list[1] && b->size > 1)
		sb(b);
}

static void		rotate_stacks(t_stack *a, t_stack *b)
{
	if (a->list[a->size - 1] < a->list[0] && a->list[a->size - 1] < a->list[1]
			&& b->size > 1 && b->list[b->size - 1] > b->list[0]
			&& b->list[b->size - 1] > b->list[1])
		rrr(a, b);
	else if (a->list[a->size - 1] < a->list[0]
			&& a->list[a->size - 1] < a->list[1])
		rra(a);
	else if (b->size > 1 && b->list[b->size - 1] > b->list[0]
			&& b->list[b->size - 1] > b->list[1])
		rrb(b);
	else if (a->size > 2 && a->list[0] > a->list[1]
			&& a->list[0] > a->list[a->size - 1] && a->list[0] > a->list[2]
			&& b->size > 2 && b->list[0] < b->list[1]
			&& b->list[0] < b->list[b->size - 1] && b->list[0] < b->list[2])
		rr(a, b);
	else if (a->size > 2 && a->list[0] > a->list[1]
			&& a->list[0] > a->list[a->size - 1] && a->list[0] > a->list[2])
		ra(a);
	else if (b->size > 2 && b->list[0] < b->list[1]
			&& b->list[0] < b->list[b->size - 1] && b->list[0] < b->list[2])
		rb(b);
}

static void		reverse_rotate_stacks(t_stack *a, t_stack *b)
{
	if (a->size > 1 && a->list[a->size - 1] > a->list[0]
			&& a->list[a->size - 1] < a->list[a->size - 2] && b->size > 1
			&& b->list[b->size - 1] < b->list[0]
			&& b->list[b->size - 1] > b->list[b->size - 2])
		rrr(a, b);
	else if (a->size > 1 && a->list[a->size - 1] > a->list[0] &&
			a->list[a->size - 1] < a->list[a->size - 2])
		rra(a);
	else if (b->size > 1 && b->list[b->size - 1] < b->list[0] &&
			b->list[b->size - 1] > b->list[b->size - 2])
		rrb(b);
}

void			main_sort(t_stack *a, t_stack *b)
{
	while (1)
	{
		swap_stacks(a, b);
		reverse_rotate_stacks(a, b);
		rotate_stacks(a, b);
		swap_stacks(a, b);
		if (ft_issorted(a->list, a->size) && b->size > 0)
		{
			pa(a, b);
			if (a->list[0] > a->list[a->size - 1]
					&& a->list[0] > a->list[a->size - 2] && a->size > 2)
				ra(a);
		}
		else if (ft_issorted(a->list, a->size))
			break ;
		else
			pb(a, b);
	}
}
