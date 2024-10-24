/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:59:26 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/10/24 12:30:02 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
        {
            return ((char*)&s[i]);
        }
        i++;
    }
    if (c == '\0')
    {
        return ((char*)&s[i]);
    }
    return NULL;
}