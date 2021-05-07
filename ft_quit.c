/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:57:32 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 12:58:11 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_err_exit_file(char *name)
{
	ft_putstr_fd("Error\nFile \"", FDERR);
	ft_putstr_fd(name, FDERR);
	ft_putstr_fd("\" !\n", FDERR);
	exit(0);
}

void	ft_err_exit_args(char prgm)
{
	ft_putstr_fd("Error\n", FDERR);
	if (prgm == 'c')
		ft_putstr_fd("USAGE: checker [options] <int1> <int2> ...\n", FDERR);
	else
		ft_putstr_fd("USAGE : push_swap [options] <int1> <int2> ...\n", FDERR);
	ft_putstr_fd(" <int1> <int2> ... : Different integers.\n", FDERR);
	ft_putstr_fd(" [Options] :\n", FDERR);
	ft_putstr_fd(" -v : Display the stack’s status after operation.\n", FDERR);
	ft_putstr_fd(" -s : Display step by step.\n", FDERR);
	ft_putstr_fd(" -c : Show in colours the last operation.\n", FDERR);
	ft_putstr_fd(" --file=<name> :", FDERR);
	if (prgm == 'c')
		ft_putstr_fd(" Reading instructions from a file.\n", FDERR);
	else
		ft_putstr_fd(" Writing instructions into a file.\n", FDERR);
	exit(0);
}

int	ft_free_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (-1);
}

void	ft_free(t_gnl *gnl, t_stack *stack, t_list **inst)
{
	if (gnl && gnl->line)
		ft_free_ptr((void **)&(gnl->line));
	if (stack && stack->a)
		ft_lstclear(&stack->a, ft_content_del);
	if (stack && stack->b)
		ft_lstclear(&stack->b, ft_content_del);
	if (inst && *inst)
		ft_lstclear(inst, ft_content_del);
}

void	ft_err_exit(t_gnl *gnl, t_stack *stack, t_list **inst)
{
	ft_putstr_fd("Error\n", FDERR);
	ft_free(gnl, stack, inst);
	exit(0);
}
