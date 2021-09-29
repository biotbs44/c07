/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:34:37 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/29 14:48:00 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{	
	int	*tab;
	int	idx;

	idx = 0;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		tab[idx] = min;
		idx++;
		min++;
	}
	return (tab);
}

int	main(void)
{
	int	*tab;
	int	idx;

	idx = 0;
	tab = ft_range(-2, 2);
	while (idx < 4)
		printf("%d ", tab[idx++]);
}
