#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char	*ft_strndup(char *src, int len)
{
	char	*entry;
	char	*ptr;

	entry = malloc(len + 1);
	ptr = entry;
	if (entry == NULL)
		return (NULL);
	while (len-- && *src)
		*entry++ = *src++;
	*entry = '\0';
	return (ptr);
}

bool	check_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (true);
		sep++;
	}
	return (false);
}

int	count_words(char *str, char *sep)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (*str)
	{
		if (check_sep(*str, sep))
		{
			if (len > 0)
				count++;
			len = 0;
		}
		if (!check_sep(*str, sep))
			len++;
		str++;
	}
	if (len > 0)
		count++;
	return (count);
}

char	**split(char *str, char *charset)
{
	char	**strs;
	int		word_count;
	int		i;
	int		len;

	i = 0;
	word_count = count_words(str, charset);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	while (i < word_count)
	{
		len = 0;
		while (*str)
		{
			if (check_sep(*str++, charset))
				break ;
			len++;
		}
		if (len > 0)
			strs[i++] = strndup(str - (len + 1), len);
	}
	strs[i] = 0;
	return (strs);
}
