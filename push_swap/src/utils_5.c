/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:20:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:28:53 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dup_arg_check(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*st_a;

	tmp = *stack_a;
	while (tmp)
	{
		st_a = tmp->next;
		while (st_a)
		{
			if (tmp->nb == st_a->nb)
				close_error();
			st_a = st_a->next;
		}
		tmp = tmp->next;
	}
}

void	assign_index(t_stack **s_a)
{
	t_stack	*ptr;
	t_stack	*scan;
	int		i;

	ptr = (*s_a);
	while (ptr)
	{
		scan = (*s_a);
		i = 1;
		while (scan)
		{
			if (ptr->nb > scan->nb)
				i++;
			scan = scan->next;
		}
		ptr->index = i;
		ptr = ptr->next;
	}
}

int	is_sorted(t_stack *s_a)
{
	while (s_a && s_a->next)
	{
		if (s_a->nb > s_a->next->nb)
			return (0);
		s_a = s_a->next;
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
