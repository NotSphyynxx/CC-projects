/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:56:05 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/06 05:04:30 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet){
    int i = 8;
    unsigned char res = 0;
    while(i--){
        res = res * 2 + (octet % 2);
        octet /= 2;
    }
    return (res);
}
