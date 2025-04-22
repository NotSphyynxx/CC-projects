/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:35:53 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/08 21:41:58 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	s_a = NULL;
	s_b = NULL;
	input_check(ac, av);
	push_a(&s_a, ac, av);
	assign_index(&s_a);
	sort_exe(&s_a, &s_b);
	while (s_a)
	{
		printf("%d ", s_a->nb);
		s_a = s_a->next;
	}
	ft_lstclear(&s_a);
}

void	input_check(int ac, char **av)
{
	char	**numbers;
	int		i;
	int		j;

	i = 1;
	numbers = NULL;
	while (i < ac)
	{
		if (!av[i] || ft_strlen(av[i]) == 0)
			close_error();
		numbers = ft_split(av[i], ' ');
		handle_failure(numbers);
		j = 0;
		while (numbers[j])
		{
			digit_check(numbers[j]);
			check_range(numbers[j]);
			j++;
		}
		dup_check(numbers);
		ft_free(numbers);
		free(numbers);
		i++;
	}
}

void	push_a(t_stack **s_a, int ac, char **av)
{
	char	**numbers;
	t_stack	*new_node;
	int		i;
	int		j;

	new_node = NULL;
	i = 1;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		handle_failure(numbers);
		j = 0;
		while (numbers[j])
		{
			new_node = ft_lst_new(ft_atoi(numbers[j]));
			handle_node(new_node);
			ft_lst_add_back(s_a, new_node);
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
	dup_arg_check(s_a);
}

static int	ft_lowest_idx_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		low_idx;
	int		low_pos;

	tmp = *stack;
	low_idx = INT_MAX;
	ft_positon(stack);
	low_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < low_idx)
		{
			low_idx = tmp->index;
			low_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}

void	ft_stack_shift(t_stack **stack_a)
{
	int	size;
	int	lowest;

	size = ft_lstsize(*stack_a);
	lowest = ft_lowest_idx_pos(stack_a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			rra(stack_a);
			lowest++;
		}
	}
	else
	{
		while (lowest)
		{
			ra(stack_a);
			lowest--;
		}
	}
}
