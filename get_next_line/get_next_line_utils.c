/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:15:12 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/20 16:35:39 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str){

    int i;

    if (!str)
        return (0);
    i = 0;
    while(str[i]){
        i++;
    }
    return (i);
}

char *ft_strchr(const char *s, int c){

    char ch;
    size_t i;

    if (!s)
        return (NULL);
    i = 0;
    ch = (char)c;
    while(s[i]){

        if (s[i] == ch)
            return ((char *)&s[i]);
        i++;
    }
    if (ch == '\0')
        return ((char*)&s[i]);
    return (NULL);
}

char *ft_strjoin(char *s1, char *s2){

    size_t i;
    size_t j;
    char *s3;

    if (!s1){
        s1 = malloc(1);
        if (!s1)
            return NULL ;
        s1[0] = '\0';
    }
    if (!s2)
        return NULL;
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (s3 == NULL)
        return NULL ;
    i = 0;
    j = 0;
    while(s1[j])
        s3[i++] = s1[j++];
    j = 0;
    while(s2[j])
        s3[i++] = s2[j++];
    s3[i] = '\0';
    free(s1);
    return (s3);
}