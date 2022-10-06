/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:24:33 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 06:11:22 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;

char				*ft_itoa(int nbr);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *str1, char const *str2);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);
char				*ft_strchr(const char *str, int c);

#endif
