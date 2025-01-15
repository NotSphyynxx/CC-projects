/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:03:52 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 02:35:47 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_prime(int num){
    if (num <= 1)
        return (0);
    int i = 2;
    while (i * i <= num){
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi(char *str){
    int res = 0;
    if (str == NULL)
        return 0;
    while (*str){
        res = (res * 10) + (*str - '0');
        str++;
    }
    return (res);
}

void    ft_putnbr(int nb){
    if (nb >= 10)
        ft_putnbr(nb / 10);
        nb = nb % 10 + '0';
        write (1, &nb, 1);
}

void    program_exe(char *str){
    int num = ft_atoi(str);
    int i = 0;
    int sum = 0;
    while (i <= num){
        if (is_prime(i)){
            sum += i;
        }
        i++;
    }
    ft_putnbr(sum);
}

int main(int ac, char **av){
    if (ac == 2){
        program_exe(av[1]);
    }
    write (1, "\n", 1);
    return (0);
}