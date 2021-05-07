/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:39:31 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/04 07:16:28 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_asc(t_list *a)
{
	while (a)
	{
		if (a->next && ft_content_cmp(a->content, a->next->content) > 0)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_stack_desc(t_list *a)
{
	while (a)
	{
		if (a->next && ft_content_cmp(a->content, a->next->content) < 0)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_stack_show(t_stack *stack, int num, char *name, t_option *opt)
{
	int		fd;

	fd = opt->fd;
	if (opt->prgm == 'c')
		fd = FDOUT;
	if (opt->c)
		ft_set_color(CINS);
	ft_putnbr_fd(num, fd);
	if (num == 0)
		ft_putstr_fd(". Init A and B", fd);
	else
	{
		ft_putstr_fd(". Exec ", fd);
		ft_putstr_fd(name, fd);
	}
	ft_lst_show(stack, opt, fd);
	ft_step(opt);
}

int	ft_stack_set(t_list **a, char **nbrs, int start, int size)
{
	char	**strs;
	int		s;

	s = 0;
	while (--size >= start)
	{
		strs = ft_split(nbrs[size], ' ');
		if (!ft_add_element(a, strs, &s))
		{
			free(strs);
			return (0);
		}
		free(strs);
	}
	return (s);
}
