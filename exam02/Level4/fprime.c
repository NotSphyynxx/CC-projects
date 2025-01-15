/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:41:18 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 13:46:45 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int main(int ac, char **av){
    if (ac == 2){
        int i = 1;
        int num = atoi(av[1]);
        if (num == 1)
            printf("1");
        while (num >= ++i){
            if (num % i == 0){
                printf("%d", i);
                if (num == i)
                    break ;
                printf("*");
                num /= i;
                i = 1;
            }
        }
    }
    write (1, "\n", 1);
    return 0;
}