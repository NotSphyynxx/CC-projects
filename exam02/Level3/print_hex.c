/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:18:14 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 08:36:58 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str){
    int result = 0;
    while (*str && (*str >= '0' && *str <= '9')){
        result = (result * 10) + (*str - '0');
        str++;
    }
    return (result);
}

int main(int ac, char **av){
    if (ac == 2){
        char *str = "0123456789abcdef";
        char holder[16];
        int nb = ft_atoi(av[1]);
        int i = 0;
        if (nb == 0)
            write (1, "0", 1);
        else{
            while (nb){
                holder[i] = str[nb % 16];
                i++;
                nb /= 16;
            }
            while (i--)
                write (1, &holder[i], 1);
        }
    }
    write (1, "\n", 1);
    return 0;
}