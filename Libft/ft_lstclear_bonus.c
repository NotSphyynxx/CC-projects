/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:06 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/10 17:35:32 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*c;
	t_list	*n;

	if (!lst || !del)
		return ;
	c = *lst;
	while (c)
	{
		n = c->next;
		ft_lstdelone(c, del);
		c = n;
	}
	*lst = NULL;
}
