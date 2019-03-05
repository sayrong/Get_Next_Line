/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:41:56 by balvyn-s          #+#    #+#             */
/*   Updated: 2018/12/15 19:30:18 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*t_s;
	char		*r;

	t_s = s;
	r = NULL;
	while (*t_s != '\0')
	{
		if (*t_s == (char)c)
			r = (char *)t_s;
		t_s++;
	}
	if (c == 0)
		return ((char *)t_s);
	return (r);
}
