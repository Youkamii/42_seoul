/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:17:47 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 22:50:33 by chyeok           ###   ########.fr       */
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
	t_num	*num;

	num = (t_num *)malloc(sizeof(t_num));
	num->prev = NULL;
	num->content = 0;
	num->next = NULL;
	return (num);
}

t_stack	*init_stack(void)
{
	t_num		*num;
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	num = init_num();
	stack->array = NULL;
	stack->a_size = 0;
	stack->a_top = num;
	stack->a_bottom = num;
	stack->b_size = 0;
	return (stack);
}

int	main(int ac, char *av[])
{
	int			size;
	int			*num;
	t_stack		*stack;

	if (ac <= 1)
		throw_error(-1);
	stack = init_stack();
	size = get_size(ac, av);
	num = av_to_array(ac, av, size);
	array_to_stack(stack, num, size);
	check_sorted(num, size, 0);
	stack->array = (int *)num;
	ft_sort(stack);
	return (0);
}
