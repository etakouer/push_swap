/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:47:56 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 12:48:35 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_add(char **line, int size, char c)
{
	char	*tmp;

	tmp = *line;
	*line = malloc(sizeof(char) * (size + 2));
	if (*line == NULL)
	{
		*line = tmp;
		return (-1);
	}
	(*line)[size + 1] = 0;
	(*line)[size] = c;
	while (--size > -1)
		(*line)[size] = tmp[size];
	ft_free_ptr((void **)&tmp);
	return (1);
}

int	ft_get_line(int fd, char **line)
{
	char	c;
	int		r;
	int		size;
	char	cc;

	size = 0;
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	**line = 0;
	c = 0;
	r = 1;
	while (1)
	{
		cc = c;
		r = read(fd, &c, 1);
		if (r < 0 || (r == 0 && cc != 0))
			return (ft_free_ptr((void **)line));
		if (r == 0 || c == '\n')
			break ;
		else
			r = ft_add(line, size++, c);
	}
	return (r);
}
