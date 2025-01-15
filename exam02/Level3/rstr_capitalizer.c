/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:39:42 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 09:58:34 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av){
    if (ac > 0){
        int i = 0;
        int a = 1;
        while (av[a]){
            i = 0;
            while (av[a][i]){
                if (av[a][i] >= 'A' && av[a][i] <= 'Z')
                    av[a][i] += 32;
                i++;
            }
            i = 0;
            while (av[a][i]){
                if ((av[a][i + 1] == ' ' || av[a][i + 1] == '\0') && (av[a][i] >= 'a' && av[a][i] <= 'z')){
                    av[a][i] -= 32;
                }   
            i++;
            }
            i = 0;
            while (av[a][i]){
                write (1, &av[a][i], 1);
                i++;
            }
        a++;
        }
    }
    write (1, "\n", 1);
    return 0;
}