/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:04:07 by balvyn-s          #+#    #+#             */
/*   Updated: 2018/12/15 19:24:35 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *data, size_t size)
{
	size_t i;

	i = size;
	free(data);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	begin = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
		if (!new)
		{
			ft_lstdel(&begin, &del);
			return (NULL);
		}
	}
	return (begin);
}
