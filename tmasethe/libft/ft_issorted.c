/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:32:43 by tmasethe          #+#    #+#             */
/*   Updated: 2018/09/10 09:00:54 by tmasethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_issorted(int *arr, unsigned int n)
{
	unsigned int i;

	i = 1;
	if (n == 0 || n == 1)
		return (1);
	while (i < n - 1)
		if (arr[i] > arr[i + 1])
			return (0);
		else
			++i;
	return (1);
}
