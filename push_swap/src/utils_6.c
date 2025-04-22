/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:14:59 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/08 21:04:03 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tree(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (is_sorted(*a))
		return ;
	check_what_to_sort(&first, &second, &third, a);
	if (!is_sorted(*a))
		sa(a);
}

void	push_b(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	int	is_pushed;

	size = ft_lstsize(*a);
	is_pushed = 0;
	i = 0;
	while (size > 6 && i < size && is_pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			is_pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - is_pushed > 3)
	{
		pb(a, b);
		is_pushed++;
	}
}

static int	validnum(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] && ft_is_digit(str[i]))
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (1);
	}
	return (0);
}

void	ft_fill_stack(char **str, t_stack **stack)
{
	long int	value;
	int			i;

	*stack = NULL;
	i = 0;
	while (str[i])
	{
		if (validnum(str[i]) == 1)
		{
			ft_free_stack(stack);
			exit(1);
		}
		value = ft_atoi(str[i]);
		ft_lst_add_back(stack, ft_lst_new(value));
		i++;
	}
}

void	ft_index_stack(t_stack *stack_a, int size)
{
	t_stack	*temp;
	t_stack	*high;
	int		value;

	while (size-- > 0)
	{
		temp = stack_a;
		value = INT_MIN;
		high = NULL;
		while (temp)
		{
			if (temp->nb == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->nb > value && temp->index == 0)
			{
				value = temp->nb;
				high = temp;
			}
			else
				temp = temp->next;
		}
		if (high)
			high->index = size;
	}
}
