/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:20:31 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/11 11:09:10 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]) && !ft_isspace(argv[1][i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		get_commands(char *line, int argc, char **argv)
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

int		check_numbers(t_stack *stack, int argc, char **argv)
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
			stack->size = argc - 1;
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

/*int		check_duplicates(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	if (check_numbers(stack, argc, argv))
	{
		if (argc > 2)
		{
			while (i++ < argc - 1)
			{
				j = i + 1;
				while (j++ < argc - 1)
					if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
						return (0);
			}
		}
		else if (argc == 2)
		{
			str = ft_strsplit(argv[1], ' ');
			while (str[i])
			{
				j = i + 1;
				while (str[j])
				{
					if (ft_atoi(str[i]) == ft_atoi(str[j]))
						return (0);
					j++;
				}
				i++;
			}
		}
	}
	return (1);
}

int		check_sorted(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**str;

	i = 1;
	if (check_numbers(stack, argc, argv))
	{
		if (argc > 2)
		{
			while (i++ < argc)
				if (ft_atoi(argv[i - 1]) > ft_atoi(argv[i]))
					return (0);
		}
		else if (argc == 2)
		{
			str = ft_strsplit(argv[1], ' ');
			while (str[i++])
				if (ft_atoi(str[i - 1]) > ft_atoi(str[i]))
					return (0);
		}
	}
	else if (!check_numbers(stack, argc, argv))
	{
		ft_putendl("OK");
		return (0);
	}
	return (1);
}*/
