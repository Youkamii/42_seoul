#include "libft.h"

char    *ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if(!*str)
		return ((char *)str);
	while(str[i] && i < len)
	{
		j = 0;
		while(str[i + j] == find[j] && i + j < len)
		{
			if (!find[j])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
