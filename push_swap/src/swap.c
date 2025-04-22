/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:00:25 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:25:17 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack **a)
{
	ft_swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	ft_swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(*a);
	ft_swap(*b);
	ft_putstr_fd("ss\n", 1);
}

void	sort_small(t_stack **a)
{
	if (is_sorted(*a) == 0)
		sa(a);
}
