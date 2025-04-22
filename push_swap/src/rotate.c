/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:15:40 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:26:15 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ra(t_stack **a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
}
