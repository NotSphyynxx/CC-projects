/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:43:37 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/15 13:38:53 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_count_word(char *str){
    int i = 0;
    int wc = 0;
    int wz = 1;
    while (str[i]){
        if (wz == 1 && str[i] > 32){
            wc++;
            wz = 0;
        }
        if (str[i] <= 32){
            wz = 1;
        }
        i++;
    }
    return (wc);
}

char *ft_strncpy(char *s1, char *s2, int n){
    int i = 0;
    while (i < n && s2[i]){
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

char    **ft_split(char *str){
    int wc = ft_count_word(str);
    char **mother = malloc((wc + 1) * sizeof(char *));
    if (mother == NULL)
        return NULL;
    int j = 0;
    int i = 0;
    int mi = 0;
    while (str[i]){
        while (str[i] && str[i] <= 32)
            i++;
        j = i;
        while (str[i] && str[i] > 32)
            i++;
        if (i > j){
            mother[mi] = malloc(sizeof(char) * (i - j) + 1);
            if (mother[mi] == NULL)
                return NULL;
            ft_strncpy(mother[mi], &str[j], i - j);
            mi++;
        }
    }
    mother[mi] = NULL;
    return (mother);
}


#include <libc.h>
int main(){
    char str[] = "  ismail m9wd badr zaml";
    char **sp = ft_split(str);
    int i = 0;
    while (sp[i]){
        printf("%s\n", sp[i]);
    i++;
   }
}