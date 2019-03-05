/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:42:22 by balvyn-s          #+#    #+#             */
/*   Updated: 2018/12/15 18:36:04 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char const *s, char c)
{
	const char	*tmp;
	int			tik;
	int			count;

	tik = 1;
	tmp = s;
	count = 0;
	while (*tmp != '\0')
	{
		if (tik == 1 && *tmp != c)
		{
			tik = 0;
			count++;
		}
		else if (*tmp == c)
		{
			tik = 1;
		}
		tmp++;
	}
	return (count);
}

static int		lets_check_and_free(char **ar, int i)
{
	int j;

	if (ar[i - 1] == NULL)
	{
		j = 0;
		while (j < i)
		{
			free(ar[j]);
			j++;
		}
		free(ar);
		return (1);
	}
	return (0);
}

static	char	*get_string(char const *s, char c, int *index)
{
	int		wc;
	int		t_index;
	char	*tmp;
	int		i;

	wc = 0;
	i = 0;
	t_index = *index;
	while (s[*index] != c && s[*index] != '\0')
	{
		wc++;
		(*index)++;
	}
	tmp = (char*)malloc(sizeof(char) * (wc + 1));
	if (tmp == NULL)
		return (NULL);
	while (wc--)
	{
		tmp[i] = s[t_index];
		i++;
		t_index++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ar;
	int		str_count;
	int		index;
	int		i;

	i = 0;
	index = 0;
	if (s == NULL)
		return (NULL);
	str_count = count_words(s, c);
	if (!(ar = (char **)malloc(sizeof(char *) * str_count + 1)))
		return (NULL);
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			ar[i++] = get_string(s, c, &index);
			if (lets_check_and_free(ar, i))
				return (NULL);
		}
		else
			index++;
	}
	ar[i] = NULL;
	return (ar);
}
