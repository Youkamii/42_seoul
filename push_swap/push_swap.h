/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:17:55 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 23:00:25 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_num
{
	struct s_num	*prev;
	int				content;
	struct s_num	*next;
}			t_num;

typedef struct s_stack
{
	int				*array;
	int				a_size;
	struct s_num	*a_top;
	struct s_num	*a_bottom;
	int				b_size;
	struct s_num	*b_top;
	struct s_num	*b_bottom;
}			t_stack;

int				get_size(int ac, char *av[]);
int				*av_to_array(int ac, char *av[], int size);
void			array_to_stack(t_stack *stack, int *int_array, int size);
void			check_sorted(int *int_array, int size, int index);
int				throw_error(int error_code);
t_num			*init_num(void);
t_stack			*init_stack(void);
int				main(int ac, char *av[]);
int				get_stack_min(t_num *stack);
int				set_a_location_min(t_stack *stack);
int				get_stack_max(t_num *stack);
int				set_a_location_max(t_stack *stack);
int				set_a_location_mid(int num, t_stack *stack);
int				set_a_location(int num, t_stack *stack);
void			ft_rotation_same(t_stack *stack, int *a, int *b);
void			ft_rotation_a(t_stack *stack, int a);
void			ft_rotation_b(t_stack *stack, int b);
void			ft_sort_big_last(t_stack *stack);
void			ft_sort_with_pivot(t_stack *stack, int pivot1, int pivot2);
void			ft_sort_three_division(t_stack *stack);
int				get_unsigned_smaller(int a, int b, int a_location, int b_location);
void			get_min_rotate(t_stack *stack, int *a, int *b);
void			ft_sort_three(t_stack *stack);
void			ft_sort_big(t_stack *stack);
void			ft_sort(t_stack *stack);
int				split_str_count(char **split_str);
void			free_all(char **split_strs);
int				special_atoi(const char *str);
void			split_str_to_int(int *int_array, int *arr_index, char **split_strs);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);
void			pa(t_stack *stack);
void			pb(t_stack *stack);

#endif
