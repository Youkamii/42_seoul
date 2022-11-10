/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:17:20 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:40:58 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_size(int ac, char *av[])
{
	int		index1;
	int		index2;
	char	**split_str;
	int		i;

	index1 = 1;
	i = 0;
	while (index1 < ac)
	{
		index2 = 0;
		while (av[index1][index2])
		{
			if (!ft_isspace(av[index1][index2]))
				break ;
			index2++;
		}
		if (av[index1][index2] == '\0')
			throw_error(1);
		split_str = ft_split(av[index1], ' ');
		i += split_str_count(split_str);
		free_all(split_str);
		index1++;
	}
	return (i);
}

int	*av_to_array(int ac, char *av[], int size)
{
	int		ac_index;
	int		array_index;
	int		*new_array;
	char	**split_str;

	ac_index = 1;
	array_index = 0;
	new_array = (int *)malloc(sizeof(int) * size);
	if (!new_array)
		throw_error(1);
	while (ac_index < ac)
	{
		split_str = ft_split(av[ac_index], ' ');
		split_str_to_int(new_array, &array_index, split_str);
		free_all(split_str);
		ac_index++;
	}
	new_array[array_index] = '\0';
	return (new_array);
}

void	array_to_stack(t_stack *info, int *int_array, int size)
{
	t_num	*new_node;
	int		index;

	index = 0;
	while (index < size)
	{
		new_node = init_num();
		info->a_size += 1;
		info->a_bottom->content = (int)int_array[index];
		info->a_bottom->next = new_node;
		new_node->prev = info->a_bottom;
		info->a_bottom = new_node;
		index++;
	}
	info->a_bottom = info->a_bottom->prev;
	free(new_node);
}

void	check_sorted(int *int_array, int size, int index)
{
	int	i;
	int	same_check;
	int	temp;

	same_check = 0;
	while (index < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (int_array[i] > int_array[i + 1])
			{
				temp = int_array[i];
				int_array[i] = int_array[i + 1];
				int_array[i + 1] = temp;
				same_check++;
			}
			i++;
		}
		if (int_array[index] == int_array[index + 1])
			throw_error(1);
		index++;
	}
	if (same_check == 0)
		throw_error(-1);
}
