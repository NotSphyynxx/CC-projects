/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:10:04 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 10:23:07 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int num){
    if (num >= 10)
        ft_putnbr(num / 10);
    num = (num % 10) + '0';
    write (1, &num, 1);
}

int ft_atoi(char *str){
    int res = 0;
    while (*str){
        res = res * 10 + (*str - '0');
        str++;
    }
    return res;
}

int main(int ac, char **av){
    if (ac == 2){
        int i = 1;
        int res = 0;
        int num = ft_atoi(av[1]);
        while (i < 10){
            res = i * num;
            ft_putnbr(i);
            write (1, " x ", 3);
            ft_putnbr(num);
            write (1, " = ", 3);
            ft_putnbr(res);
            write (1, "\n", 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return 0;
}