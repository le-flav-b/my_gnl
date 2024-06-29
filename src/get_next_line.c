/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <flboulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:43:41 by flboulea          #+#    #+#             */
/*   Updated: 2024/06/29 02:29:06 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ex :

**save = [
	1
	1
	0x57e2ac570a		"bonjour\n"
	1
	0x57e2b180d4		"\0"
	0
]
*/

int	create_save_tab(char ***save)
{
	*save = malloc(sizeof(char *));
	if (!*save)
		return (0);
	(*save)[0] = 0;
	return (1);
}

int	check_for_new_fd(char ***save, int fd)
{
	char	**new_save;
	int		i;

	if (!*save && !(create_save_tab(save)))
		return (0);
	i = -1;
	while ((*save)[++i])
	{
		if (i == fd && (unsigned long long)((*save)[i]) > 1)
			return (1);
		else if (i == fd && (unsigned long long)((*save)[i]) == 1)
			return (create_save(*save + i));
	}
	new_save = malloc(sizeof(char *) * (fd + 2));
	if (!new_save)
		return (0);
	i = -1;
	while ((*save)[++i])
		new_save[i] = (*save)[i];
	while (i < fd)
		new_save[i++] = (void *)1;
	if (!create_save(new_save + i))
		return (free(new_save), 0);
	new_save[++i] = 0;
	return (free(*save), *save = new_save, 1);
}

char	*cls_save(char ***save, char *ret)
{
	int	i;

	i = -1;
	while ((*save)[++i])
		if ((unsigned long long)((*save)[i]) > 1)
			return (ret);
	free(*save);
	*save = 0;
	return (ret);
}

/*
Read from fd until '\n' or EOF and put it in *line.

Return :
	0	: success
	1	: EOF
	-1	: invalid fd
	-2	: malloc/read failed

On success, *line is null-terminated and ends with '\n' if it's not EOF,
			the caller is responsible for freeing *line.
On EOF,		*line is set to NULL.
On failure,	*line is set to NULL.

This function has no leak, no need to call it until EOF.
*/
int	get_next_line(int fd, char **line)
{
	static char	buf[FD_MAX][BUFFER_SIZE + 1];
	int			i;

	*line = NULL;
	if (fd < 0 || fd >= FD_MAX)
		return (-2);
	(void)buf;
	(void)i;
	// TODO
	return (0);
}




/*
char	*get_next_line(int fd)
{
	static char	**save = 0;
	char		*buf;
	int			i;

	if (fd == -100)
		return ((char *)save);
	if (fd < 0 || BUFFER_SIZE <= 0 || !check_for_new_fd(&save, fd))
		return ((char *)-1);
	i = -1;
	int (nb_read) = 1;
	while (save[fd][++i] != '\n' && nb_read)
	{
		if (save[fd][i])
			continue ;
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ((char *)-1);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read <= 0)
			return (free(buf), cls_save(&save, extract_until(save + fd, i)));
		buf[nb_read] = ('\0' * i--);
		if (!concate_and_free(save + fd, buf, nb_read))
			return ((char *)-1);
	}
	return (extract_until(save + fd, ++i));
}
*/
