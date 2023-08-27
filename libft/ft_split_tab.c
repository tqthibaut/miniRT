/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 08:57:47 by tthibaut          #+#    #+#             */
/*   Updated: 2022/02/11 17:12:45 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitstrlcpy_tab(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	**ft_free(char const **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_fill_row_tab(char **tab, char const *src, char c)
{
	size_t	j;
	size_t	k;
	size_t	row;

	j = 0;
	row = 0;
	while (src[j])
	{
		while (src[j] == c || src[j] == '\n')
			j++;
		k = j;
		while (src[j] != c && src[j] && src[j] != '\n')
		{
			j++;
			if (!src[j] || src[j] == c || src[j] == '\n')
			{
				tab[row] = ((char *)malloc(sizeof(char) * (j - k + 1)));
				if (!tab[row])
					return (ft_free((char const **)tab, row));
				ft_splitstrlcpy_tab(tab[row++], src + k, (j - k));
			}
		}
	}
	tab[row] = 0;
	return (tab);
}

char	**ft_split_tab(char const *s)
{
	size_t	i;
	char	**tab;

	if (s == NULL)
		return (0);
	i = ft_count_words(s, '\n');
	tab = ((char **)malloc(sizeof(char *) * (i + 1)));
	if (!tab)
		return (0);
	return (ft_fill_row_tab(tab, s, '\n'));
}
