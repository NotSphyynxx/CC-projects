/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:02:07 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 08:08:12 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str){
    int i = 0;
    while (str[i]){
        i++;
    }
    return (i);
}

int main(int ac, char **av){
    if (ac == 3){
        int i = 0;
        int j = 0;
        int flag = 0;
        while (av[1][i]){
            while (av[2][j]){
                if (av[1][i] == av[2][j]){
                    flag += 1;
                    break ;
                }
                j++;
            }
            i++;
        }
        if ((ft_strlen(av[1])) == flag){
            write (1, "1", 1);
        }
        else
            write (1, "0", 1);
    }
    write (1, "\n", 1);
    return 0;
}