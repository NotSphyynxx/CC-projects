/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 06:44:45 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/08 10:43:15 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet){
    int i = 8;
    while (i--){
        unsigned char bit = (octet >> i & 1) + '0';
        write (1, &bit, 1); 
    }
}