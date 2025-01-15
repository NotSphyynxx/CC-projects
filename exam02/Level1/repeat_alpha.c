/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 01:05:00 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/04 01:20:27 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av){
    if (ac > 1){
        int i = 0;
        int count = 0;
        while (av[1][i]){
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                count = av[1][i] - 'a' + 1;
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                count = av[1][i] - 'A' + 1;
            else
                count = 1;
            while (count--)
                write(1, &av[1][i], 1);
            i++;
    }
    write(1, "\n", 1);
    return 0;
}
}