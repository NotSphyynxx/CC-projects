/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:05:04 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 19:43:30 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = ft_last(*stack);
	temp->next = NULL;
	last->next = temp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
