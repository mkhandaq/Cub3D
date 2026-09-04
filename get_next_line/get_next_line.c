/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:42:22 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/09/03 23:57:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dest;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

static char	*readline(int fd, char *book, char *buffer)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0 && (!book || !ft_strchr(book, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(book);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(book, buffer);
		free(book);
		book = temp;
	}
	return (book);
}

static char	*bline(char **book)
{
	char	*pos;
	char	*temp;
	char	*line;
	size_t	linelen;

	if (ft_strchr(*book, '\n'))
	{
		pos = ft_strchr(*book, '\n');
		linelen = (pos - *book + 1);
		line = ft_substr(*book, 0, linelen - 1);
		temp = ft_strdup(pos + 1);
		free(*book);
		*book = temp;
	}
	else
	{
		line = ft_strdup(*book);
		free(*book);
		*book = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*book;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	book = readline(fd, book, buffer);
	free(buffer);
	if (book == NULL || book[0] == '\0')
	{
		free(book);
		book = NULL;
		return (NULL);
	}
	line = bline(&book);
	return (line);
}