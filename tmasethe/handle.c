/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:49:55 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/12 11:36:14 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i])
				&& str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int			check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	if (argc > 2)
	{
		while (i++ < argc - 1)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])
						&& argv[i][j] != '-' && argv[i][j] != '+')
					return (0);
				j++;
			}
		}
	}
	else if (argc == 2)
	{
		if (!check_str(argv[1]))
			return (0);
	}
	return (1);
}

int			get_commands(char *line, int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		if (check_commands(line))
			ft_strdel(&line);
		else if (!check_commands(line))
		{
			ft_strdel(&line);
			ft_putendl("Error");
			exit(0);
		}
	}
	return (1);
}

int			check_numbers(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	if (check_args(argc, argv))
	{
		if (argc > 2)
		{
			while (i++ < argc - 1)
				if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
					return (0);
		}
		else if (argc == 2)
		{
			str = ft_strsplit(argv[1], ' ');
			while (str[i])
			{
				if (ft_atol(str[i]) > MAX_INT || ft_atol(str[i]) < MIN_INT)
					return (0);
				i++;
			}
			stack->size = i;
		}
	}
	return (1);
}
