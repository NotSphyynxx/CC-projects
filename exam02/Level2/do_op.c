/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:01:45 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/04 15:11:45 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av){
    if (ac == 4){
        int s1 = atoi(av[1]);
        int s2 = atoi(av[3]);
        int result = 0;
        if (*av[2] == '+'){
            result = s1 + s2;
            printf("%d", result);
        }
        else if (*av[2] == '-'){
            result = s1 - s2;
            printf("%d", result);
        }
        else if (*av[2] == '*'){
            result = s1 * s2;
            printf("%d", result);
        }
        else if (*av[2] == '/'){
            result = s1 / s2;
            printf("%d", result);
        }
        else if (*av[2] == '%'){
            result = s1 % s2;
            printf("%d", result);
        }
    }
    printf("\n");
    return 0;
}