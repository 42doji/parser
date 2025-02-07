/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:05:55 by doji              #+#    #+#             */
/*   Updated: 2025/01/29 19:06:01 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef MAX_FD
# define MAX_FD 4096
#endif

static char	*left_str[MAX_FD];

static char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*read_to_left_str(int fd, char *left_str)
{
	char	*buf;
	int		read_bytes;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(left_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		temp = ft_strjoin(left_str, buf);
		free(left_str);
		left_str = temp;
	}
	free(buf);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!left_str[fd])
		left_str[fd] = ft_strdup("");
	if (!left_str[fd])
		return (NULL);
	left_str[fd] = read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
	{
		left_str[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(left_str[fd]);
	if (!line)
	{
		free(left_str[fd]);
		left_str[fd] = NULL;
		return (NULL);
	}
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

void	get_next_line_cleanup(int fd)
{
	int	i;

	if (fd == -1)
	{
		i = 0;
		while (i < MAX_FD)
		{
			if (left_str[i])
			{
				free(left_str[i]);
				left_str[i] = NULL;
			}
			i++;
		}
	}
	else if (fd >= 0 && fd < MAX_FD && left_str[fd])
	{
		free(left_str[fd]);
		left_str[fd] = NULL;
	}
}
