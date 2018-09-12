/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:48:42 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/12 12:14:48 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	duplicate(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			check_duplicates(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 1;
	if (argc == 2)
	{
		str = ft_strsplit(argv[1], ' ');
		if (duplicate(str))
			return (0);
	}
	else if (argc > 2)
	{
		if (duplicate(argv))
			return (0);
	}
	return (1);
}
