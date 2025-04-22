/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:06:12 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 19:43:38 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_is_full_space(char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

static char	*ft_join_args(char **v)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strdup("");
	while (v[i])
	{
		if (ft_is_full_space(v[i]))
		{
			ft_error();
			free(tmp);
			exit(1);
		}
		tmp = ft_strjoin(tmp, v[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	return (tmp);
}

char	**ft_stack(char **v)
{
	char	**str;
	char	*s;

	s = NULL;
	s = ft_join_args(v);
	str = ft_split(s, ' ');
	free(s);
	return (str);
}
