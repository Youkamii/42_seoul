/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:17:47 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:33:19 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	throw_error(int error_code)
{
	if (error_code >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

t_num	*init_num(void)
{
	t_num	*new_num;

	new_num = (t_num *)malloc(sizeof(t_num));
	new_num->prev = NULL;
	new_num->content = 0;
	new_num->next = NULL;
	return (new_num);
}

t_stack	*init_stack(void)
{
	t_num		*num;
	t_stack		*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	num = init_num();
	new_stack->array = NULL;
	new_stack->a_size = 0;
	new_stack->a_top = num;
	new_stack->a_bottom = num;
	new_stack->b_size = 0;
	return (new_stack);
}

int	main(int ac, char *av[])
{
	int			array_size;
	int			*array_num;
	t_stack		*stack;

	if (ac <= 1)
		throw_error(-1);
	stack = init_stack();
	array_size = get_size(ac, av);
	array_num = av_to_array(ac, av, array_size);
	array_to_stack(stack, array_num, array_size);
	check_sorted(array_num, array_size, 0);
	stack->array = (int *)array_num;
	ft_sort(stack);
	return (0);
}
