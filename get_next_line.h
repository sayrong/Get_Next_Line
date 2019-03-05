/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:37:08 by balvyn-s          #+#    #+#             */
/*   Updated: 2018/12/23 15:22:30 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
