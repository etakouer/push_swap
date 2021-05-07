/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 06:49:56 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 10:44:23 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_execute(char *name, t_stack *stack, t_option *opt, int num)
{
	t_fcts	fct;
	int		i;

	fct.names = (char *[NBFCT + 1]){"sa", "sb", "ss", "pa", "pb", \
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	fct.ptrs = (void *[NBFCT]){ft_sa, ft_sb, ft_ss, ft_pa, ft_pb, \
			ft_ra, ft_rb, ft_rr, ft_rra, ft_rrb, ft_rrr};
	fct.nb_params = (int [NBFCT]){0, 1, 2, 2, 2, 0, 1, 2, 0, 1, 2};
	i = -1;
	while (++i < NBFCT)
	{
		if (!ft_strcmp(name, fct.names[i]))
		{
			ft_exec_fct(fct, i, stack);
			if (opt->v)
				ft_stack_show(stack, num, name, opt);
			else
			{
				ft_putstr_fd(name, opt->fd);
				ft_putstr_fd("\n", opt->fd);
			}
			break ;
		}
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_get_pivot(t_list *a, int size, int ipiv)
{
	int	i;
	int	*tab;
	int	piv;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = -1;
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv)
			tab[++i] = ((t_content *)a->content)->nb;
		a = a->next;
	}
	ft_sort_int_tab(tab, size);
	piv = tab[size / 2];
	free(tab);
	return (piv);
}
