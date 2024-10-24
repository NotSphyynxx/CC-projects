/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:33:51 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/24 15:31:35 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isalnum(int ch);
int ft_isascii(int ch);
int ft_isprint(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
void    ft_bzero(void *ptr, size_t numberOfBytes);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_memcpy(void *d, const void *s, size_t numberOfBytes);
void    *ft_memmove(void *dest, const void *src, size_t numberOfBytes);

#endif