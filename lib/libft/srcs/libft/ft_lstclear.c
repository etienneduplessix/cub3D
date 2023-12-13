/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:53:00 by edupless          #+#    #+#             */
/*   Updated: 2023/08/08 17:49:45 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*h;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		h = *lst;
		*lst = h->next;
		free(h);
	}
	*lst = NULL;
}
