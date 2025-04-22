/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:52:07 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:27:01 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_last(*stack);
	before_last = ft_before_last(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	rra(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
