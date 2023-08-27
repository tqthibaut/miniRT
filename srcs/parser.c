/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:31:10 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/26 14:19:32 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ERROR);
	if (*str != ' ' && *str != '\n' && *str != '\0')
		return (FALSE);
	if (*str == '\n')
		return (TRUE);
	while (*str == ' ')
	{
		str++;
		i++;
		if (*str != ' ' && *str != '\n' && *str != '\0')
			return (FALSE);
	}
	if (*str != '\n' && i > 0)
		return (TRUE);
	else
		return (FALSE);
}

int	check_arg(int ac, char **av)
{
	int	fd;

	fd = -1;
	if (ac != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (ERROR);
	}
	if (!av[1])
		return (ERROR);
	if (check_extension(av[1]) == ERROR)
		return (ERROR);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: wrong path/file\n", 2);
		return (ERROR);
	}
	return (fd);
}

int	check_and_make(char **tab, t_data *data)
{
	if (checker_line(tab) == ERROR)
	{
		free_tab(tab);
		return (ERROR);
	}
	if (structure_maker(tab, data) == ERROR)
	{
		free_tab(tab);
		free_struct(data);
		return (ERROR);
	}
	return (TRUE);
}

int	split_and_check(char *str, char **tab, t_data *data, int fd)
{
	while (str)
	{
		tab = ft_split_plus(str, ',');
		if (!tab)
		{
			free(str);
			return (ERROR);
		}
		free(str);
		str = NULL;
		if (check_and_make(tab, data) == ERROR)
			return (ERROR);
		free_tab(tab);
		tab = NULL;
		str = get_next_line(fd);
		while (check_empty(str) == TRUE)
		{
			free(str);
			str = get_next_line(fd);
			if (!str)
				return (TRUE);
		}
	}
	return (TRUE);
}

int	parser(int ac, char **av, t_data *data)
{
	int		fd;
	char	*str;
	char	**tab;

	tab = NULL;
	fd = check_arg(ac, av);
	if (fd == -1)
		return (ERROR);
	str = get_next_line(fd);
	while (check_empty(str) == TRUE)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (!str)
		return (ERROR);
	if (split_and_check(str, tab, data, fd) == ERROR)
	{
		str = NULL;
		return (ERROR);
	}
	str = NULL;
	return (TRUE);
}
