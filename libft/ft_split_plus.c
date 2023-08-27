/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:33:39 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/12 16:26:50 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitstrlcpy_plus(char *dst, const char *src, size_t size)
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

static char	**ft_free(char const **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_fill_row_plus(char **dst, char const *src, char c)
{
	size_t	k;

	size_t (j) = 0;
	size_t (row) = 0;
	while (src[j])
	{
		while (src[j] == c || src[j] == '\n' || src[j] == ' ' || src[j] == '\t')
			j++;
		k = j;
		while (src[j] != c && src[j] && src[j] != '\n'
			&& src[j] != ' ' && src[j] != '\t')
		{
			j++;
			if (!src[j] || src[j] == c || src[j] == '\n'
				|| src[j] == ' ' || src[j] == '\t')
			{
				dst[row] = ((char *)malloc(sizeof(char) * (j - k + 1)));
				if (!dst[row])
					return (ft_free((char const **)dst, row));
				ft_splitstrlcpy_plus(dst[row++], src + k, (j - k));
			}
		}
	}
	dst[row] = 0;
	return (dst);
}

char	**ft_split_plus(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (s == NULL)
		return (0);
	i = ft_count_words(s, c);
	str = ((char **)malloc(sizeof(char *) * (i + 1)));
	if (!str)
		return (0);
	return (ft_fill_row_plus(str, s, c));
}

/* SPLIT_PLUS c'est comme split, mais en pas pareil                      */
/* Ah oui en fait il split avec le '\n' en plus du char c                */
/* Faut que je refasse cette fonction pour qu'elle accepte un set de char*/
/* en separateur */
/* Bouge toi le cul futur moi                                            */
