/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:38:23 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 23:35:26 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_tmp;
	int		a_size;
	int		b_size;

	a_size = ft_lstsize(*stack_a);
	b_size = ft_lstsize(*stack_b);
	b_tmp = *stack_b;
	while (b_tmp)
	{
		b_tmp->cost_b = b_tmp->pos;
		if (b_tmp->pos > b_size / 2)
			b_tmp->cost_b = (b_size - b_tmp->pos) * -1;
		b_tmp->cost_a = b_tmp->target_pos;
		if (b_tmp->target_pos > a_size / 2)
			b_tmp->cost_a = (a_size - b_tmp->target_pos) * -1;
		b_tmp = b_tmp->next;
	}
}

void	ft_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		a_cost;
	int		b_cost;

	a_cost = 0;
	b_cost = 0;
	if (!*stack_b)
		return ;
	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < cheapest)
		{
			cheapest = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			a_cost = tmp->cost_a;
			b_cost = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (cheapest != INT_MAX)
		ft_best_move(stack_a, stack_b, a_cost, b_cost);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	ft_is_signed(char c)
{
	return (c == '-' || c == '+');
}
