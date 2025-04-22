/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:52:47 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:34:36 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	is_pushed;

	size = ft_lstsize(*stack_a);
	is_pushed = 0;
	i = 0;
	while (size > 6 && i < size && is_pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			is_pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - is_pushed > 3)
	{
		pb(stack_a, stack_b);
		is_pushed++;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
