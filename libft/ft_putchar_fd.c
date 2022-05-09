#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char*	tmp_str;
	size_t	len_str1;
	size_t	len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	if (!str1 || !str2)
		return (NULL);
	tmp_str = (char *)malloc(sizeof(char * (len_str1 + len_str2 + 1)));
	if (!tmp_str)
		return (NULL);
	ft_strlcpy(tmp_str, str1, len_str1 + 1);
	ft_strlcat(tmp_str, str2, len_str2 + 1);
	return (tmp_str);
}

int main()
{
	char s1[] = "peanut";
	char s2[] = "butter";

	printf("%s\n", ft_strjoin(s1, s2));

	return 0;
}