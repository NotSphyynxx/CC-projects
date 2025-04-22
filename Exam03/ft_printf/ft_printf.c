/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:54 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/04/17 16:39:07 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int num, int base, int *len)
{
	if (num < 0)
	{
		num *= -1;
		*len += write(1, "-", 1);
	}
	if (num >= base)
		put_digit((num / base), base, len);
	*len += write(1, &("0123456789abcdef"[num % base]), 1);
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if((*format == '%') && ((*format + 1) == 's') || ((*format + 1) == 'd') || ((*format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit(va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digit(va_arg(ptr, long), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}