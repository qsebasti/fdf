/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:15:58 by qsebasti          #+#    #+#             */
/*   Updated: 2019/03/03 18:03:43 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	addend(char **line, char **dest, char *tmp)
{
	if (ft_strchr(*dest, '\n'))
	{
		*line = ft_strsub(*dest, 0, ft_strchr(*dest, '\n') - *dest);
		tmp = *dest;
		*dest = ft_strdup(ft_strchr(*dest, '\n') + 1);
		free(tmp);
		return (1);
	}
	if (*dest[0] == '\0' || !*dest)
		return (0);
	else
	{
		*line = ft_strdup(*dest);
		ft_bzero(*dest, ft_strlen(*dest));
		return (1);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*dest = NULL;
	char		*tmp;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	tmp = NULL;
	if (fd < 0 || !line || (!dest &&
				!(dest = ft_strdup(""))))
		return (-1);
	if (ft_strchr(dest, '\n'))
		return (addend(line, &dest, tmp));
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		dest = ft_new_alloc(dest, buf);
	}
	return (addend(line, &dest, tmp));
}
