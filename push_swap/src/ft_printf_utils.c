/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:16:02 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:43 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i += ft_putstr("(null)"));
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(2, "-2147483648", 11));
	else if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_put_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_put_unsigned(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_put_ptr(unsigned long num)
{
	char	*hexa;
	char	holder[16];
	int		count;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(2, "0x0", 3));
	count += write(2, "0x", 2);
	while (num)
	{
		holder[i++] = hexa[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(2, &holder[i], 1);
	return (count);
}
