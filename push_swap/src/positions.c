/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:52:57 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 23:33:09 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_positon(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	ft_target(t_stack **stack_a, int b_index, int target_index,
				int target_pos)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	ft_assign_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target;

	tmp = *stack_b;
	target = 0;
	ft_positon(stack_a);
	ft_positon(stack_b);
	while (tmp)
	{
		target = ft_target(stack_a, tmp->index, INT_MAX, target);
		tmp->target_pos = target;
		tmp = tmp->next;
	}
}

t_stack	*ft_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	check_what_to_sort(t_stack **first, t_stack **second,
		t_stack **third, t_stack **a)
{
	if ((*first)->index > (*second)->index
		&& (*first)->index > (*third)->index)
	{
		ra(a);
		if ((*second)->index > (*third)->index)
			sa(a);
	}
	else if ((*second)->index > (*first)->index
		&& (*second)->index > (*third)->index)
	{
		rra(a);
		if ((*first)->index > (*third)->index)
			sa(a);
	}
	else if ((*third)->index > (*first)->index
		&& (*third)->index > (*second)->index)
	{
		if ((*first)->index > (*second)->index)
			sa(a);
	}
}
