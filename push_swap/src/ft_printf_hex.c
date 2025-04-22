/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:52:22 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:26 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_hexa_converter(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_hexa_converter((num / 16), format);
		ft_hexa_converter((num % 16), format);
	}
	else if (num <= 9)
		ft_putchar(num + 48);
	else
	{
		if (format == 'x')
			ft_putchar((num - 10) + 'a');
		else if (format == 'X')
			ft_putchar((num - 10) + 'A');
	}
}

int	ft_put_hexa(unsigned int num, const char format)
{
	if (num == 0)
		return (write(2, "0", 1));
	else
		ft_hexa_converter(num, format);
	return (ft_hexa_len(num));
}
