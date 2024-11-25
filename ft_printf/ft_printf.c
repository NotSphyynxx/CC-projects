/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:20 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/24 16:12:51 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_checker(va_list al, const char format)
{
	int	bytes_written;

	bytes_written = 0;
	if (format == 'c')
		bytes_written += ft_putchar(va_arg(al, int));
	else if (format == 's')
		bytes_written += ft_putstr(va_arg(al, char *));
	else if (format == 'd' || format == 'i')
		bytes_written += ft_putnbr(va_arg(al, int));
	else if (format == 'u')
		bytes_written += ft_put_unsigned(va_arg(al, unsigned int));
	else if (format == '%')
		bytes_written += ft_putchar(format);
	else if (format == 'X' || format == 'x')
		bytes_written += ft_put_hexa(va_arg(al, unsigned int), format);
	else if (format == 'p')
		bytes_written += ft_put_ptr((unsigned long)va_arg(al, void *));
	return (bytes_written);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	al;

	va_start(al, format);
	i = 0;
	printed = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				printed += format_checker(al, format[i + 1]);
				i++;
			}
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(al);
	return (printed);
}
