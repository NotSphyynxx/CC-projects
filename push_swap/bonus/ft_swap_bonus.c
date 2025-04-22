/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:06:34 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 19:43:40 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
}
