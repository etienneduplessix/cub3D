/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edupless <edupless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:35:07 by edupless          #+#    #+#             */
/*   Updated: 2023/01/24 11:33:16 by edupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;
	void	*temp;

	if (lst == NULL)
		return (0);
	result = 0;
	while (lst != NULL)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (new == NULL)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	new = 0;
	return (result);
}
