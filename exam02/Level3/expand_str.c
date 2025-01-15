/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:54:00 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/07 03:18:11 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    program_exe(char *str){
    int i = 0;
    while (str[i] == ' ')
        i++;
    while (str[i]){
        if (str[i] == ' '){
            while (str[i] == ' '){
                i++;
            }
            if (str[i] == '\0')
                break ;
            write (1, "   ", 3);
        }
        write (1, &str[i], 1);
        i++;
    }
}
int main(int ac, char **av){
    if (ac == 2){
        program_exe(av[1]);
    }
    write (1, "\n", 1);
    return 0;
}