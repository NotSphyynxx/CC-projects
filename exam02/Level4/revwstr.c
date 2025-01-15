/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revwstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:51:39 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 15:54:16 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str){
    int i = 0;
    while (*str){
        str++;
        i++;
    }
    return (i);
}

int main(int ac, char **av){
    if (ac == 2){
       int i = ft_strlen(av[1]) - 1;
       int start = 0;
       int end = 0;
       while (av[1][i]){
            while (av[1][i] <= 32)
                i--;
            end = i;
            while (av[1][i] > 32)
                i--;
            start = i + 1;
            int flag = start;
            while (start <= end){
                write (1, &av[1][start], 1);
                start++;
            }
            if (flag)
                write (1, " ", 1);
       }
    }
    write (1, "\n", 1);
    return 0;
}