/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:33 by jashin            #+#    #+#             */
/*   Updated: 2022/09/13 21:13:55 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sort_big_last(t_stack *stack)
{
	int	min_location;

	min_location = set_a_location_min(stack);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stack);
			min_location--;
		}
		else
		{
			rra(stack);
			min_location++;
		}
	}
}

void	ft_sort_with_pivot(t_stack *stack, int pivot1, int pivot2)
{
	if (stack->a_top->content < pivot1)
	{
		pb(stack);
		rb(stack);
	}
	else if (stack->a_top->content < pivot2)
		pb(stack);
	else
		ra(stack);
}

void	ft_sort_three_division(t_stack *stack)
{
	int	index;
	int	pivot1;
	int	pivot2;

	index = stack->a_size / 3;
	pivot1 = stack->array[index];
	index = stack->a_size * 2 / 3;
	pivot2 = stack->array[index];
	index = stack->a_size;
	while (index)
	{
		ft_sort_with_pivot(stack, pivot1, pivot2);
		index--;
	}
}

int	get_unsigned_smaller(int a, int b, int a_location, int b_location)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_location < 0)
		a_location = a_location * -1;
	if (b_location < 0)
		b_location = b_location * -1;
	if (a + b > a_location + b_location)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_stack *stack, int *a, int *b)
{
	int				a_location;
	int				b_location;
	int				index;
	t_num			*num_b;
	int				num;

	index = 0;
	num_b = stack->b_top;
	while (index < stack->b_size)
	{
		num = num_b->content;
		a_location = set_a_location(num, stack);
		if (index >= (stack->b_size + 1) / 2)
			b_location = (stack->b_size - index) * -1;
		else
			b_location = index;
		if (index == 0 || get_unsigned_smaller(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		num_b = num_b->next;
		index++;
	}
}
