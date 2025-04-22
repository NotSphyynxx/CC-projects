/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:37:34 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:30:42 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	write(1, "pb\n", 3);
}

void	sort_exe(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(*a) == 1)
		return ;
	if (size == 2)
		sort_small(a);
	else if (size == 3)
		sort_tree(a);
	else if (size > 3)
	{
		push_b(a, b);
		sort_tree(a);
		while (*b)
		{
			ft_assign_pos(a, b);
			ft_cost(a, b);
			ft_cheapest(a, b);
		}
	}
	if (!is_sorted(*a) && *a)
		ft_stack_shift(a);
}
