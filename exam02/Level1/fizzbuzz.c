/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:04:33 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 16:46:42 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_printnum(int i){
    char str[10] = "0123456789";
    if (i > 9)
        ft_printnum(i / 10);
    write(1, &str[i % 10], 1);
}

int main(int ac , char **av){
    if (ac <= 1){
        int i;
        i = 1;
        while(i < 100){
            if (i % 5 == 0 && i % 3 == 0)
                write(1, "fizzbuzz\n", 9);
            else if (i % 3 == 0)
                write(1, "fizz\n", 5);
            else if (i % 5 == 0)
                write(1, "buzz\n", 5);
            else{
                ft_printnum(i);
                write (1, "\n", 1);
            }
            i++;
        }
    }
    return 0;
}