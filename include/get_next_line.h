/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flboulea <flboulea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:42:41 by flboulea          #+#    #+#             */
/*   Updated: 2024/06/29 02:04:06 by flboulea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

int		get_next_line(int fd, char **line);

void	ft_strcpy_at_from(char *dest, int dest_start, char *src, int src_start);
int		create_save(char **save);
int		concate_and_free(char **base, char *to_add, int to_add_len);
char	*extract_until(char **save, int cut);

#endif
