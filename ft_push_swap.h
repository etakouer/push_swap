/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:23:38 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 12:45:38 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define BLU "\x1B[36m"
# define YEL "\x1B[33m"
# define MAG "\x1B[35m"
# define WHT "\x1B[0m"

# define COK 1 
# define CKO 2 
# define CINS 3
# define CCH 4
# define CLST 5
# define CDEF 0 

# define NBFCT 11
# define FDIN 0
# define FDOUT 1
# define FDERR 2

# define NONE 0
# define LAST 1
# define DEBUG 0
# define MINA 5

# define INTMAX 2147483647
# define INTMIN 2147483648
# define BFS 10000
# define SSA 15

typedef struct s_gnl
{
	char	*line;
	int		ret;
}			t_gnl;

typedef struct s_content
{
	int		nb;
	int		color;
	int		ipiv;
}			t_content;

typedef struct s_option
{
	int			v;
	int			c;
	int			s;
	int			fd;
	char		*path;
	int			ac;
	char		**av;
	int			start;
	char		prgm;
	int			code;
	int			size;
	int			ipiv;
	int			aipiv;
	int			bipiv;
	t_content	piv;
	int			num;
	int			asize;
	int			bsize;
	int			*nbpiv;
	int			not_sorted;
}				t_option;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;

typedef struct s_fcts
{
	void	**ptrs;
	char	**names;
	int		*nb_params;
	void	(*ptr_type1)(t_list **);
	void	(*ptr_type2)(t_list **, t_list**);
}			t_fcts;

void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);

void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);

void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);

void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);

int		ft_add(char **line, int size, char c);
int		ft_get_line(int fd, char **line);

void	ft_check_sort(t_stack *stack, t_option *opt);
void	ft_init(t_option *opt, t_gnl *gnl, t_stack *stack, t_list **inst);
void	ft_set_options(t_option *opt);

void	ft_exec_fct(t_fcts fct, int i, t_stack *stack);
int		ft_inst_add(t_list **inst, t_gnl *gnl);
int		ft_inst_exec(t_stack *stack, t_list *inst, t_option *opt);
void	ft_inst_show(t_list *inst);
void	ft_inst_print(void *content);

int		ft_set_color(int color);
int		ft_toint(const char *str, int *nb);
void	ft_lstiter_opt(t_list *lst, void (*f)(void *, void *), void *opt);

void	ft_content_color(void *content, int color);
void	ft_content_del(void *content);
void	ft_content_print(void *content, void *opt);
void	*ft_content_new(char *str);
int		ft_content_cmp(void *content1, void *content2);

int		ft_stack_asc(t_list *a);
int		ft_stack_desc(t_list *a);
void	ft_stack_show(t_stack *stack, int num, char *name, t_option *opt);
int		ft_stack_set(t_list **a, char **nbrs, int start, int size);

int		ft_stack_find(t_list *a, void *content);
void	ft_lst_show(t_stack *stack, t_option *opt, int fd);
void	ft_step(t_option *opt);
int		ft_add_element(t_list **a, char **strs, int *s);

void	ft_err_exit(t_gnl *gnl, t_stack *stack, t_list **inst);
void	ft_err_exit_file(char *name);
void	ft_err_exit_args(char prgm);
int		ft_free_ptr(void **ptr);
void	ft_free(t_gnl *gnl, t_stack *stack, t_list **inst);

int		ft_get_maxinit(t_list **a, int ipiv, t_content **maxc, int *i);
int		ft_get_max(t_list *a, int *value, int ipiv);
int		ft_get_mininit(t_list **a, int ipiv, t_content **minc, int *i);
int		ft_get_min(t_list *a, int *value, int ipiv);

void	ft_execute(char *name, t_stack *stack, t_option *opt, int num);
void	ft_sort_int_tab(int *tab, int size);
int		ft_get_pivot(t_list *a, int size, int ipiv);

int		ft_get_near_min(t_list **a, t_content *piv, int ipiv, int *i);
int		ft_get_near(t_list *a, t_content *piv, int ipiv);
int		ft_get_near_mini1(t_list **a, t_content *piv, int ipiv, int *i);
int		ft_get_near1(t_list *a, t_content *piv, int ipiv);

int		ft_lower_exist(t_list *a, void *piv, int ipiv);
void	ft_sort_last_asc(t_stack *stack, t_option *opt, int *num);
void	ft_push_lower1(t_stack *stack, t_option *opt, int *num);
void	ft_push_lower(t_stack *stack, t_option *opt, int *num, t_content *piv);

int		ft_greater_exist(t_list *b, void *piv, int ipiv);
void	ft_push_greater1(t_stack *stack, t_option *opt, int *num);
void	ft_push_greater(t_stack *stack, t_option *opt, \
		int *num, t_content *piv);

void	ft_pushb(t_stack *stack, t_option *opt);
void	ft_pusha2(t_stack *stack, t_option *opt);
void	ft_pusha3(t_stack *stack, t_option *opt);
void	ft_pusha(t_stack *stack, t_option *opt);
void	ft_sort(t_stack *stack, t_option *opt);

#endif
