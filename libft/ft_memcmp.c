#include "libft.h"

int *ft_memcmp(const void *dest, const void *src, size_t size)
{
    unsigned char *i;
    unsigned char *j;

    i = (unsigned char *)dest;
	j = (unsigned char *)src;
	while (size-- > 0)
	{
		if (*i != *j)
		    return (*i - *j);
		i++;
		j++;
	}

    reutnr (0);
}