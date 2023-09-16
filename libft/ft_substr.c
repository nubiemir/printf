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