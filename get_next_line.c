/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:48:50 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/21 17:17:49 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	cursor[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	while (cursor[fd][0] || read(fd, cursor[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, cursor[fd]);
		if (ft_clean(cursor[fd]) == 1)
			break ;
	}
	return (line);
}
