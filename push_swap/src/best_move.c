/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:45:50 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:33:21 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *a_cost,
		int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		rrr(stack_a, stack_b);
	}
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *a_cost,
		int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		(*a_cost)--;
		(*b_cost)--;
		rr(stack_a, stack_b);
	}
}

static void	rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a);
			(*cost)--;
		}
		else
		{
			rra(stack_a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **stack_b, int *b_cost)
{
	while (*b_cost)
	{
		if (*b_cost > 0)
		{
			rb(stack_b);
			(*b_cost)--;
		}
		else
		{
			rrb(stack_b);
			(*b_cost)++;
		}
	}
}

void	ft_best_move(t_stack **stack_a, t_stack **stack_b, int a_cost,
		int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		rev_rotate_both(stack_a, stack_b, &a_cost, &b_cost);
	else if (a_cost > 0 && b_cost > 0)
		rotate_both(stack_a, stack_b, &a_cost, &b_cost);
	rotate_a(stack_a, &a_cost);
	rotate_b(stack_b, &b_cost);
	pa(stack_a, stack_b);
}
