/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:03:58 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 19:43:25 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}
