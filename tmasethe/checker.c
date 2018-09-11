/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:17:17 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/11 12:22:44 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		instructions(t_stack *a, t_stack *b, int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line))
	{
		get_commands(line, argc, argv);
		do_operations(a, b, line);
	}
}

t_stack		*create_stack(int size)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * size);
	if (stack)
	{
		stack->list = (int *)malloc(sizeof(int) * size);
		stack->size = 0;
		stack->capacity = size;
	}
	return (stack);
}

void		free_leaks(t_stack *a, t_stack *b)
{
	free(a->list);
	free(b->list);
	free(a);
	free(b);
}
int			main(int argc, char **argv)
{
	t_stack stack;
	t_stack *a;
	t_stack *b;

	if (argc == 1)
		return (0);
	//(argc > 2) ? stack.size = argc - 1 : 0;
	if (!(check_numbers(&stack, argc, argv)) || !check_args(argc, argv)
		|| !check_duplicates(argc, argv))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	a = create_stack(stack.size);
	b = create_stack(stack.size);
	if (get_numbers(a, argc, argv))
		instructions(a, b, argc, argv);
	if (ft_issorted(a->list, a->size))
		ft_putendl("OK");
	else if (!ft_issorted(a->list, a->size))
		ft_putendl("KO");
	int i = 0;
	while (i < a->size)
	{
		printf("%d \n", a->list[i]);
		i++;
	}
	//free_leaks(a, b);
	return (0);
}
