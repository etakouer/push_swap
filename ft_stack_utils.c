/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:47:00 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/04 07:19:29 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lst_show(t_stack *stack, t_option *opt, int fd)
{
	ft_putstr_fd(" :\n", fd);
	if (opt->c)
		ft_set_color(CLST);
	ft_putstr_fd(" A -> ", fd);
	ft_lstiter_opt(stack->a, ft_content_print, opt);
	if (opt->c)
		ft_set_color(CLST);
	ft_putstr_fd("\n B -> ", fd);
	ft_lstiter_opt(stack->b, ft_content_print, opt);
	if (opt->c)
		ft_set_color(CDEF);
	ft_putstr_fd("\n", fd);
}

void	ft_step(t_option *opt)
{
	char	step[BFS];

	if (opt->s > 1)
		opt->s--;
	if (opt->s == 1)
	{
		read(1, step, BFS);
		opt->s = ft_atoi(step) + 1;
		if (opt->s == 0)
			opt->s = 1;
	}
}

int	ft_stack_find(t_list *a, void *content)
{
	while (a && ft_content_cmp(a->content, content))
		a = a->next;
	return (a != NULL);
}

int	ft_add_element(t_list **a, char **strs, int *s)
{
	int		i;
	void	*content;
	t_list	*new;

	i = -1;
	while (strs[++i])
		;
	while (i--)
	{
		content = ft_content_new(strs[i]);
		free(strs[i]);
		new = ft_lstnew(content);
		if (content == NULL || new == NULL || ft_stack_find(*a, content))
		{
			ft_lstdelone(new, ft_content_del);
			ft_lstclear(a, ft_content_del);
			while (--i >= 0)
				free(strs[i]);
			return (0);
		}
		new->next = *a;
		*a = new;
		(*s)++;
	}
	return (1);
}
