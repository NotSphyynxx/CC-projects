/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:36:50 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:24:34 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_range(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
	{
		close_error();
	}
}

t_stack	*ft_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_lst_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_last(*stack);
	last->next = new;
}

t_stack	*ft_lst_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*save_node;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		save_node = current->next;
		free(current);
		current = save_node;
	}
	*lst = NULL;
}
