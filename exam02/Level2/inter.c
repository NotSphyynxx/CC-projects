/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:05:05 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/05 05:19:00 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int double_checker(char *str, char c, int pos){
    int i = 0;
    while (i < pos){
        if (str[i] == c){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int ac, char **av){
    if (ac == 3){
        int i;
        int j;
        i = 0;
        while (av[1][i]){
            j = 0;
            while (av[2][j]){
                if (av[1][i] == av[2][j]){
                    if (double_checker(av[1], av[1][i], i)){
                        write(1, &av[1][i], 1);
                        break ;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}