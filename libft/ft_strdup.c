#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*tmp_str;

	len = ft_strlen(str);
	i = 0;
	*tmp_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp_str)
		return (0);
	while (i < len)
	{
		tmp_str[i] = str[i];
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}