/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:35:11 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/30 10:19:57 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_content_color(void *content, int color)
{
	((t_content *)content)->color = color;
}

int	ft_content_cmp(void *content1, void *content2)
{
	return (((t_content *)content1)->nb - ((t_content *)content2)->nb);
}

void	ft_content_del(void *content)
{
	ft_free_ptr(&content);
}

void	ft_content_print(void *content, void *opt)
{
	int	fd;

	fd = ((t_option *)opt)->fd;
	if (((t_option *)opt)->prgm == 'c')
		fd = FDOUT;
	if (((t_option *)opt)->c)
		ft_set_color(((t_content *)content)->color);
	ft_putnbr_fd(((t_content *)content)->nb, fd);
	if (DEBUG)
	{
		ft_putstr_fd(" (", fd);
		ft_putnbr_fd(((t_content *)content)->ipiv, fd);
		ft_putstr_fd(")", fd);
	}
	if (((t_option *)opt)->c)
		ft_set_color(CDEF);
	ft_content_color(content, CLST);
	ft_putstr_fd(" ", fd);
}

void	*ft_content_new(char *str)
{
	t_content	*content;
	int			nb;

	if (!ft_toint(str, &nb))
		return (NULL);
	content = malloc(sizeof(t_content));
	if (content == NULL)
		return (NULL);
	content->nb = nb;
	content->color = CLST;
	content->ipiv = -1;
	return (content);
}
