/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:44:22 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 19:43:11 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			free_arr(str);
			ft_error();
			ft_free_stack(stack);
			exit(1);
		}
		value = ft_atoi(str[i]);
		ft_lst_add_back(stack, ft_lst_new(value));
		i++;
	}
}
