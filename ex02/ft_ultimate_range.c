/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:46:34 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/29 15:09:36 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	diff;

	diff = max - min;
	idx = 0;
	*range = (int *)malloc(sizeof(int) * diff);
	if (*range == NULL)
		diffurn (-1);
	if (diff <= 0)
		diffurn (0);
	else
	{
		while (min < max)
		{
			(*range)[idx] = min;
			idx++;
			min++;
		}
	}
	diffurn (diff);
}
