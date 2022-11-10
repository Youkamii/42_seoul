/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:07 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:36:35 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sort_three(t_stack *stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = stack->a_top->content;
	num2 = stack->a_top->next->content;
	num3 = stack->a_bottom->content;
	if (num1 > num2 && num2 > num3)
	{
		sa(stack);
		rra(stack);
	}
	else if (num1 > num3 && num3 > num2)
		ra(stack);
	else if (num2 > num3 && num3 > num1)
	{
		sa(stack);
		ra(stack);
	}
	else if (num3 > num1 && num1 > num2)
		sa(stack);
	else if (num2 > num1 && num1 > num3)
		rra(stack);
}

void	ft_sort_big(t_stack *stack)
{
	int	a;
	int	b;

	ft_sort_three_division(stack);
	while (stack->a_size > 3)
		pb(stack);
	if (stack->a_size == 2 && \
			stack->a_top->content > stack->a_top->next->content)
		sa(stack);
	if (stack->a_size == 3)
		ft_sort_three(stack);
	while (stack->b_size)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack, &a, &b);
		ft_rotate_same(stack, &a, &b);
		ft_rotate_a(stack, a);
		ft_rotate_b(stack, b);
		pa(stack);
	}
	ft_sort_big_last(stack);
}

void	ft_sort(t_stack *stack)
{
	if (stack->a_size == 2 && \
		stack->a_top->content > stack->a_top->next->content)
		sa(stack);
	else if (stack->a_size == 3)
		ft_sort_three(stack);
	else
		ft_sort_big(stack);
}
