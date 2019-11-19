/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:53:29 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 18:35:07 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, char **tmp)
{
	if (fd < 0)
		return (-1);
	if (!(*tmp))
	{
		if (!((*tmp) = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*read_line(int fd, char *tmp)
{
	char	buffer[BUFFER_SIZE + 1];
	char	len;

	while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	char			buffer[BUFFER_SIZE + 1];
	static char		*tmp;

	if (check_error(fd, &tmp) == -1)
		return (-1);
	if (*tmp)
		(*line) = ft_strdup(tmp);
	tmp = read_line(fd, tmp);
	i = 0;
	if (tmp[i])
	{
		while (tmp[i] && tmp[i] != '\n')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
				*line = ft_substr(tmp, 0, i);
				tmp = &tmp[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}

int		main(void)
{
	int fd;
	char	*line;
	int 	i = 1;

	fd = open("fichier.txt", O_RDONLY);
	line = ft_strdup("");
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		printf("%d\t%s\n", i, line);
	}
	return (0);
}
