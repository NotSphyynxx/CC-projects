/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:46:25 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/06 05:53:03 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str){
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int main(int ac, char **av){
    if (ac == 3){
        int i = 0;
        int j = 0;
        char str[100];
        while (av[1][i]){
            while (av[2][j]){
                if (av[1][i] == av[2][j]){
                    str[i] = av[1][i];
                    break ;
                }
                j++;
            }
            i++;
        }
        str[i] = '\0';
        i = 0;
        if (ft_strlen(str) == ft_strlen(av[1])){
            while (av[1][i]){
                write(1, &av[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}