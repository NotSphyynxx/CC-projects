/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:16:07 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 00:57:02 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int double_checker(char *str, char c, int pos){
    int i = 0;
    while (i < pos){
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int not_there(char *str, char c, int pos){
    int i = 0;
    while (str[i]){
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av){
    if (ac == 3){
        int i = 0;
        while (av[1][i]){
            int j = 0;
            while (av[2][j]){
                if (double_checker(av[1], av[1][i], i)){
                    write(1, &av[1][i], 1);
                    break ;
                }
                j++;
            }
            i++;
        }
        i = 0;
        while (av[2][i]){
            int k = 0;
            while (av[1][k]){
                if (not_there(av[1], av[2][i], i)){  
                    if (double_checker(av[2], av[2][i], i)){
                        write(1, &av[2][i], 1);
                        break ;
                    }
                }
                k++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}