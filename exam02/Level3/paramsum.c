/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:12:00 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 08:16:28 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int nb){
    if (nb >= 10)
        ft_putnbr(nb/10);
    nb = nb % 10 + '0';
    write (1, &nb, 1);
}

int main(int ac, char **av){
    int i = -1;
    while (*av){
        i++;
        av++;
    }
    ft_putnbr(i);
    write (1, "\n", 1);
    return 0;
}