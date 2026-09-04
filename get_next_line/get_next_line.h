/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:42:32 by mkhandaq          #+#    #+#             */
/*   Updated: 2026/09/03 23:58:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr_GNL(const char *s, int c);
char	*ft_strjoin_GNL(char *s1, char *s2);
char	*ft_strdup_GNL(const char *s);
char	*ft_substr_GNL(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	*ft_memcpy_GNL(void *dest, const void *src, size_t n);
size_t	ft_strlen_GNL(const char *s);

#endif