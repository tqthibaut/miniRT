/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:49:26 by tthibaut          #+#    #+#             */
/*   Updated: 2022/02/03 09:56:37 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_totallen_plus(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			i++;
	}
	if (s2)
	{
		while (s2[j++])
			i++;
	}
	return (i);
}

char	*ft_strjoin_plus(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	i = ft_totallen_plus(s1, s2);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (s1)
		while (s1[k] && j < i)
			str[j++] = s1[k++];
	k = 0;
	if (s2)
		while (s2[k] && j < i)
			str[j++] = s2[k++];
	str[j] = '\0';
	free(s1);
	return (str);
}
/*
/!\ Ce strjoin ne renvoie pas une erreur quand une des strings
est manquante, faire super gaffe a la gestion d'erreur de malloc
ou autre probleme dans les strings.
Renvoie une NOUVELLE string contenant au moins une des strings
de l'argument
*/
