/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:15:20 by mlamarre          #+#    #+#             */
/*   Updated: 2017/01/12 18:47:33 by mlamarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

static int		read_line(const int fd, char **line)
{
	int			size;
	char		*buffer;
	char		*str;

	buffer = ft_strnew(sizeof(*buffer) * (BUFF_SIZE + 1));
	if (!buffer)
		return (-1);
	size = read(fd, buffer, BUFF_SIZE);
	if (size > 0)
	{
		buffer[size] = '\0';
		str = ft_strjoin(*line, buffer);
		if (!(str))
			return (-1);
		free(*line);
		*line = str;
	}
	if (buffer)
		free(buffer);
	return (size);
}

int				get_next_line(const int fd, char **line)
{
	int			line_read;
	char		*new_line;
	static char	*str = NULL;

	if (!line || (!str && (str = ft_strnew(sizeof(*str))) == NULL))
		return (-1);
	new_line = ft_strchr(str, '\n');
	while (new_line == NULL)
	{
		if ((line_read = read_line(fd, &str)) == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (line_read < 0)
			return (-1);
		else
			new_line = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(new_line));
	new_line = ft_strdup(new_line + 1);
	free(str);
	str = new_line;
	return (1);
}
