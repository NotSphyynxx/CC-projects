/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:38:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/12 11:06:46 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_countbytes(int nbr){
    int len = 0;
    if (nbr < 0){
        len++;
        nbr *= -1;
    }
    if (nbr == 0)
        return (1);
    while (nbr > 0){
        len++;
        nbr /= 10;  
    }
    return (len);
}

char	*ft_itoa(int nbr){
    int i = 0;
    int len = ft_countbytes(nbr);
    char *str = malloc((len * sizeof(char)) + 1);
    if (str == NULL)
        return NULL;
    str[len] = '\0';
    len--;
    while (len >= 0){
        str[len] = (nbr % 10) + '0';
        nbr = nbr / 10;
        len--;
    }
    return (str);
}
#include <libc.h>
int main(){
    printf("%s\n", ft_itoa(0));
}