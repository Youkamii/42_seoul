/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:17:20 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 22:47:37 by chyeok           ###   ########.fr       */
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
	int		array_idx;
	int		*new_arr;
	char	**split_str;

	ac_index = 1;
	array_idx = 0;
	new_arr = (int *)malloc(sizeof(int) * size);
	if (!new_arr)
		throw_error(1);
	while (ac_index < ac)
	{
		split_str = ft_split(av[ac_index], ' ');
		split_str_to_int(new_arr, &array_idx, split_str);
		free_all(split_str);
		ac_index++;
	}
	new_arr[array_idx] = '\0';
	return (new_arr);
}

void	array_to_stack(t_stack *info, int *int_array, int size)
{
	t_num	*new_nodes;
	int		index;

	index = 0;
	while (index < size)
	{
		new_nodes = init_num();
		info->a_size += 1;
		info->a_bottom->content = (int)int_array[index];
		info->a_bottom->next = new_nodes;
		new_nodes->prev = info->a_bottom;
		info->a_bottom = new_nodes;
		index++;
	}
	info->a_bottom = info->a_bottom->prev;
	free(new_nodes);
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
