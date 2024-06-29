/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <flboulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:45:28 by flboulea          #+#    #+#             */
/*   Updated: 2024/06/07 02:08:13 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_strcpy_at_from(char *dest, int dest_start, char *src, int src_start)
{
	int	i;

	i = -1;
	while (src[src_start + ++i])
		dest[dest_start + i] = src[src_start + i];
	dest[dest_start + i] = '\0';
}

int	create_save(char **save)
{
	*save = malloc(1);
	if (!*save)
		return (0);
	(*save)[0] = '\0';
	return (1);
}

int	concate_and_free(char **base, char *to_add, int to_add_len)
{
	char	*tmp;
	int		base_len;

	base_len = ft_strlen(*base);
	tmp = malloc(base_len + to_add_len + 1);
	if (!tmp)
		return (free(to_add), 0);
	ft_strcpy_at_from(tmp, 0, *base, 0);
	ft_strcpy_at_from(tmp, base_len, to_add, 0);
	free(*base);
	free(to_add);
	*base = tmp;
	return (1);
}

char	*extract_until(char **save, int cut)
{
	char	*res;
	char	*tmp_cpy;
	int		len_remaining;
	int		i;

	if (!cut)
		return (free(*save), *save = (void *)1, (char *)0);
	res = malloc(cut + 1);
	if (!res)
		return ((char *)-1);
	i = -1;
	while (++i < cut)
		res[i] = (*save)[i];
	res[i] = '\0';
	len_remaining = 0;
	while ((*save)[cut + len_remaining])
		len_remaining++;
	tmp_cpy = malloc(len_remaining + 1);
	if (!tmp_cpy)
		return (free(res), (char *)-1);
	ft_strcpy_at_from(tmp_cpy, 0, *save, cut);
	free(*save);
	*save = tmp_cpy;
	return (res);
}
