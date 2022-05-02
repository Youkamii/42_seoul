char    *ft_strchr(const char *str, int c)
{
    int i;

    if (!(*str))
        return (0);
    else
        i = ft_strlen(str);
    while (i >= 0)
    {
        if(str[i] == c)
            return ((char *)str[i]);
        --i;
    }
    return (0);
}