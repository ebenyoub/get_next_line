/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:53:29 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 20:12:03 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int		len;
	static int		stop;
	char			buffer[BUFFER_SIZE + 1];
	static char		*tmp;

	if (fd < 0)
		return (-1);
	while ((len = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		stop = 0;
		buffer[len] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buffer);
		else
			if (!(tmp = ft_strjoin(tmp, buffer)))
				return (-1);
		if (ft_strchr(tmp, '\n') > 0)
			stop = ft_strchr(tmp, '\n');
		if (ft_strchr(tmp, '\n') == 0 && len == 0)
			stop = ft_strlen(tmp);
		if (stop > 0)
		{
			if (!(*line = ft_substr(tmp, 0, stop)))
			{
				free(tmp);
				return (-1);
			}
			tmp = &tmp[stop + 1];
			return (1);
		}
		if (ft_strchr(tmp, '\n') == 0 && len == 0)
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	free(buffer);
	return (-1);
}

int		main(void)
{
	int fd;
	char	*line;
	int 	i = 9;

	fd = open("fichier.txt", O_RDONLY);
	while (i-- >= 0)
		printf("%d\t%s\n", get_next_line(fd, &line), line);
	return (0);
}
