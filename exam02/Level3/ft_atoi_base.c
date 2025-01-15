/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:20:21 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/10 12:02:28 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base){
    int i = 0;
    int res = 0;
    int s = 1;
    int k = 0;

    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            s *= -1;
        else
            i++;
    }
    while (str[i]){
        if (str[i] >= '0' && str[i] <= '9')
            k = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            k = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            k = str[i] - 'A' + 10;
        else
            break ;
        res = res * str_base + k;
    i++;
    }
    return (res * s);
}
