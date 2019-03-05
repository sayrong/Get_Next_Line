/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:36:42 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/01/09 20:25:39 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list, int fd)
{
	t_list	*prev;
	t_list	*temp;
	size_t	t_fd;

	t_fd = (size_t)fd;
	temp = *list;
	if (temp != NULL && temp->content_size == t_fd)
	{
		*list = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && temp->content_size != t_fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
	return ;
}

t_list	*find_list(int fd, t_list **list)
{
	t_list	*temp;
	char	*a;

	a = "";
	temp = *list;
	if (*list == NULL)
	{
		*list = ft_lstnew(a, 1);
		(*list)->content_size = (size_t)fd;
		return (*list);
	}
	while (temp != NULL)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		temp = temp->next;
	}
	ft_lstadd(list, ft_lstnew(a, 1));
	(*list)->content_size = (size_t)fd;
	return (*list);
}

char	*check_iteration(int fd, char **buf, char **output_line, int *fin)
{
	char	*temp;
	ssize_t	read_result;

	while (!(temp = ft_strchr(*output_line, '\n')))
	{
		read_result = read(fd, *buf, BUFF_SIZE);
		if (read_result < BUFF_SIZE)
		{
			if (read_result == -1)
				return (NULL);
			(*buf)[read_result] = 0;
		}
		if (!(temp = ft_strjoin(*output_line, *buf)))
			return (NULL);
		free(*output_line);
		*output_line = temp;
		if (read_result == 0)
		{
			if (**output_line == '\0')
				*fin = 0;
			return (temp + ft_strlen(temp));
		}
	}
	return (temp);
}

char	*get_line(int fd, char **buf, t_list **list, int *fin)
{
	char	*output_line;
	char	*temp;
	char	*new_line;

	if (*list == NULL)
		return (NULL);
	output_line = (*list)->content;
	if (!(temp = check_iteration(fd, buf, &output_line, fin)))
		return (NULL);
	if (!(new_line = ft_strnew(temp - output_line)))
		return (NULL);
	ft_memcpy(new_line, output_line, temp - output_line);
	if (*temp != '\0')
		temp++;
	if (!(temp = ft_strdup(temp)))
		return (NULL);
	if (!*fin)
		free(temp);
	else
	{
		(*list)->content = temp;
	}
	free(output_line);
	return (new_line);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*working;
	char			*buf;
	int				fin;

	fin = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	working = find_list(fd, &list);
	if (!(buf = (char *)malloc(BUFF_SIZE + 1)))
	{
		clear_list(&list, fd);
		return (-1);
	}
	buf[BUFF_SIZE] = 0;
	*line = get_line(fd, &buf, &working, &fin);
	if (*line == NULL)
	{
		clear_list(&list, fd);
		return (-1);
	}
	if (fin == 0)
		clear_list(&list, fd);
	free(buf);
	return (fin);
}
