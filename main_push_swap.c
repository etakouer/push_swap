/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:22:38 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 09:43:29 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	t_stack		stack;
	t_option	opt;

	opt.ac = ac;
	opt.av = av;
	opt.num = 0;
	opt.prgm = 's';
	ft_init(&opt, NULL, &stack, NULL);
	if (opt.fd > 1)
		opt.c = 0;
	ft_sort(&stack, &opt);
	ft_free(NULL, &stack, NULL);
	if (opt.fd > 1)
		ft_putstr_fd("Writing success !\n", FDOUT);
	return (0);
}
