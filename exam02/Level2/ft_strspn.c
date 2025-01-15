/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 04:55:15 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/05 05:04:32 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strspn(const char *s, const char *accept){
    int c = 0;
    int i = 0;
    while (*s){
        i = 0;
        while (accept[i]){
            if (*s == accept[i]){
                c++;
                break ;
            }
            i++;
        }
        if (accept[i] == '\0')
            break ;
        s++;
    }
    return c ;
}