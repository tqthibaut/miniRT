/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:34:02 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/06 15:58:20 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listtab	*ft_lstnew(char **content)
{
	t_listtab	*new;

	new = (t_listtab *)malloc(sizeof(t_listtab));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->arg = content;
}
