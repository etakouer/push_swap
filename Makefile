# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakouer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 15:10:29 by etakouer          #+#    #+#              #
#    Updated: 2021/05/07 15:41:45 by etakouer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CH		= ft_content.c ft_inst_utils.c ft_quit.c ft_reverse.c ft_swap.c main_utils.c ft_inst.c ft_push.c ft_reader.c ft_rotate.c ft_stack.c ft_stack_utils.c ft_utils.c main_checker.c

SRCS_PS		= ft_content.c ft_inst_utils.c ft_quit.c ft_reverse.c ft_sort.c ft_swap.c main_utils.c ft_inst.c ft_push.c ft_reader.c ft_rotate.c ft_stack.c ft_stack_utils.c ft_utils.c  main_push_swap.c ft_sort_utils.c ft_max_min.c ft_near.c ft_lower.c ft_greater.c

OBJS_CH		= $(SRCS_CH:.c=.o)

OBJS_PS		= $(SRCS_PS:.c=.o)

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror 

NAME_CH		= checker

NAME_PS		= push_swap

NAME 		=  $(NAME_CH)  $(NAME_PS)

LIBFT		= libft.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : 		$(NAME)

$(NAME_CH) :	$(LIBFT) $(OBJS_CH) 
			gcc $(CFLAGS) -o $(NAME_CH) $(OBJS_CH) $(LIBFT) 
$(NAME_PS) :	$(LIBFT) $(OBJS_PS) 
			gcc $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) $(LIBFT)

$(LIBFT) : 
			make -C libft
			mv libft/libft.a .

clean :
			make clean -C libft
			rm -f $(OBJS_CH) $(OBJS_PS) 

fclean :	clean
			rm -f $(NAME) $(LIBFT)

re :		fclean all

.PHONY: all clean fclean re
