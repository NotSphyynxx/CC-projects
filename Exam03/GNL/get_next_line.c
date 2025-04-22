/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:49 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/04/16 18:02:02 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;

	len = 0;
	while(src[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len])
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_readed;
	static int	buffer_pos;
	char		line[70000];
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while  (1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break ;	
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
