#include "libft.h"
#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *tmp_s;
    unsigned int    i;

    i = n;
    tmp_s = (unsigned char *)s;
    while (i)
    {
        if (*tmp_s == c)
            return (tmp_s);
        tmp_s++;
        i--;
    }
    return ((void *)0);
}