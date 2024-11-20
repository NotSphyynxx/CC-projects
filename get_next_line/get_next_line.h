/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:31:23 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/20 16:35:59 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <libc.h>
#define BUFFER_SIZE 5
char *get_next_line(int fd);
char *read_and_fill_holder(int fd, char *lines_holder);
char *return_line_till_new_line(char *lines_holder);
char *next_line_adjuster(char *lines_holder);
size_t  ft_strlen(char *str);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);

#endif