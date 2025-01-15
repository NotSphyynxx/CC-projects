/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:45:34 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/06 06:04:42 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str){
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int ac, char **av){
    if (ac > 1){
        int i = 0;
        while(av[1][i]){
            if (av[1][i] >= 65 && av[1][i] <= 90){
                write (1, "_", 1);
                av[1][i] += 32;
            }
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return 0;
}