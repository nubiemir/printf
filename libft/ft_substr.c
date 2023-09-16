#include "libft.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	res;
	unsigned int	counter;

	counter = 0;
	res = 0;
	while (s[counter])
	{
		counter++;
		res++;
	}
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	len;
	unsigned int	counter;

	len = ft_strlen(s1);
	res = (char *)malloc(len + 1);
	counter = 0;
	if (res != NULL)
	{
		while (counter < len)
		{
			res[counter] = s1[counter];
			counter++;
		}
		res[counter] = '\0';
	}
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	counter;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	counter = 0;
	if (len > ft_strlen(s))
		substring = (char *)malloc((ft_strlen(s) - start) + 1);
	else
		substring = (char *)malloc(len + 1);
	if (substring != NULL)
	{
		while (s[start] && counter < len)
			substring[counter++] = s[start++]; 
		substring[counter] = '\0';
	}
	return (substring);
}