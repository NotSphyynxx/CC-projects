/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:09:57 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/20 16:44:19 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd){

   static char *lines_holder;
   char *line_to_be_returned;

   if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL ;
	lines_holder = read_and_fill_holder(fd, lines_holder);
	if (lines_holder == NULL)
		return NULL ;
	line_to_be_returned = return_line_till_new_line(lines_holder);
	if(line_to_be_returned == NULL)
		return NULL ;
	lines_holder = next_line_adjuster(lines_holder);
	return (line_to_be_returned);
}

char *read_and_fill_holder(int fd, char *lines_holder){

	char *buffer;
	ssize_t scanned_bytes;
	
	scanned_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return NULL ;
	while (!ft_strchr(lines_holder , '\n') && scanned_bytes > 0){

		scanned_bytes = read(fd, buffer, BUFFER_SIZE);
		if (scanned_bytes == -1){
			
			free(buffer);
			return NULL ;
		}
		buffer[scanned_bytes] = '\0';
		lines_holder = ft_strjoin(lines_holder, buffer);
	}
	free(buffer);
	return (lines_holder);
}

char *return_line_till_new_line(char *lines_holder){
	
	char	*str;
	int i;

	if (!lines_holder)
		return (NULL) ;
	while (lines_holder[i] && lines_holder[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return NULL ;
	i = 0;
	while(lines_holder[i] && lines_holder[i] != '\n'){
		str[i] = lines_holder[i];
		i++;
	}
	if (lines_holder[i] == '\n'){
		str[i] = lines_holder[i];
		i++;
	}
	str[i] = '\0';
	return (str) ;
}

char *next_line_adjuster(char *lines_holder){

	char *str;
	int i;
	int j;

	i = 0;
	while (lines_holder[i] && lines_holder[i] != '\n')
		i++;
	if (!lines_holder[i]){
		free(lines_holder);
		return NULL ;
	}
	str = malloc(sizeof(char) * (ft_strlen(lines_holder) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while(lines_holder[i])
		str[j++] = lines_holder[i++];
	str[j] = '\0';
	free(lines_holder);
	return (str);
}