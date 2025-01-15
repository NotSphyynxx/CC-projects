/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:57:02 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 16:24:01 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void    bard_lktaf(char *str, int s, int e){
    while (s <= e){
        write (1, &str[s], 1);
        s++;
    }
}

void    skhon_lktaf(char *str){
    int i = 0;
    int start = 0;
    int end = 0;
    while (str[i] <= 32)
        i++;
    start = i;
    while (str[i] > 32)
        i++;
    end = i - 1;
    while (str[i]){
        while (str[i] && str[i] <= 32)
            i++;
        while (str[i] && str[i] > 32){
            write (1, &str[i], 1);
            i++;
        }
        write (1, " ", 1);
    }
    bard_lktaf(str, start, end);
}

int main(int ac, char **av){
    if (ac > 1){
        skhon_lktaf(av[1]);
    }
    write (1, "\n", 1);
    return 0;
}