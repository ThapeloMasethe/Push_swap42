/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:48:42 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/11 15:31:56 by tmasethe         ###   ########.fr       */
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
	int		j;
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
		while (i < argc - 1)
		{
			j = i + 1;
			while (argv[j])
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}
