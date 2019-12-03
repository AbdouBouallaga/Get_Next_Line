/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:57:39 by babdelka          #+#    #+#             */
/*   Updated: 2019/06/15 13:48:50 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_newline(char *str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	if (str[i] == '\n')
		tmp = ft_strdup(&str[i] + 1);
	if (str[i] == '\0')
		tmp = ft_strnew(0);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[FD_MAX];
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > FD_MAX)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && !ft_strlen(str[fd]))
		return (0);
	tmp = ft_newline(str[fd], line);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}
