/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 14:07:00 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 14:09:21 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		end_line(char **tmp, int len, char **line)
{
	if (len < 0)
		return (-1);
	if (len == 0)
	{
		if (!(*line = ft_strdup(*tmp)))
			return (-1);
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
		return (0);
	}
	return (-1);
}

int		new_line(char **tmp, int len, char **line)
{
	int				i;
	char			*clean;

	i = 0;
	if (*tmp == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	while ((*tmp)[i] != '\n' && (*tmp)[i] != '\0')
		i++;
	if ((*tmp)[i] == '\n')
	{
		if (!((*line) = ft_substr((*tmp), 0, i)))
			return (-1);
		if (!(clean = ft_strdup(&(*tmp)[i + 1])))
			return (-1);
		free(*tmp);
		(*tmp) = clean;
	}
	else if (len < 1)
		return (end_line(tmp, len, line));
	return (1);
}

int		fill_buffer(int len, char *buffer, char **tmp)
{
	char			*clean;

	buffer[len] = '\0';
	if (*tmp == NULL)
	{
		if (!(*tmp = ft_strdup(buffer)))
			return (-1);
	}
	else
	{
		if (!(clean = ft_strjoin(*tmp, buffer)))
			return (-1);
		free(*tmp);
		*tmp = clean;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				len;
	char			buffer[BUFFER_SIZE + 1];
	static char		*tmp[FD_SETSIZE];

	if (!(line) || fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
		return (-1);
	while (ft_strchr(tmp[fd]) == 0)
	{
		if ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			if ((fill_buffer(len, buffer, &tmp[fd])) == -1)
				return (-1);
		}
		else
			break ;
	}
	return (new_line(&tmp[fd], len, line));
}
