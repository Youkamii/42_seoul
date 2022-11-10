/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:07 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 23:01:16 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_sort_three(t_stack *stack)
{
	int	i;
	int	j;
	int	k;

	i = stack->a_top->content;
	j = stack->a_top->next->content;
	k = stack->a_bottom->content;
	if (i > j && j > k)
	{
		sa(stack);
		rra(stack);
	}
	else if (i > k && k > j)
		ra(stack);
	else if (j > k && k > i)
	{
		sa(stack);
		ra(stack);
	}
	else if (k > i && i > j)
		sa(stack);
	else if (j > i && i > k)
		rra(stack);
}

void	ft_sort_big(t_stack *stack)
{
	int	i;
	int	j;

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
		i = 0;
		j = 0;
		get_min_rotate(stack, &i, &j);
		ft_rotation_same(stack, &i, &j);
		ft_rotation_a(stack, i);
		ft_rotation_b(stack, j);
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
