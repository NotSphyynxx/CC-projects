/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:40:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/25 09:57:42 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_put_unsigned(unsigned int nb);
int		ft_put_hexa(unsigned int num, const char format);
void	ft_hexa_converter(unsigned int num, const char format);
int		ft_hexa_len(unsigned int num);
int		ft_put_ptr(unsigned long num);

#endif
