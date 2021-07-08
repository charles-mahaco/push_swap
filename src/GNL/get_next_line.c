/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelpois <cbelpois@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:16:40 by cbelpois          #+#    #+#             */
/*   Updated: 2020/10/03 13:16:52 by cbelpois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line, int i)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX || !line)
		return (-1);
	*line = ft_strjoin_to_eol(NULL, buf[fd]);
	if (!*line)
		return (-1);
	ret = 1;
	while (ft_strchr_pos(buf[fd], '\n') == -1 && ret && ret != -1)
	{
		ft_bzero(buf[fd], BUFFER_SIZE + 1);
		ret = read(fd, buf[fd], BUFFER_SIZE);
		*line = ft_strjoin_to_eol(*line, buf[fd]);
		if (!*line)
			return (-1);
	}
	ret = ft_strchr_pos(buf[fd], '\n') + 1;
	if (buf[fd][0] == 0)
		return (0);
	while (buf[fd][ret] != '\0' && ret)
		buf[fd][i++] = buf[fd][ret++];
	buf[fd][i] = 0;
	return (1);
}
