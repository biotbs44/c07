/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:06:33 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/30 00:26:11 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert_base.h"

int	ft_base_to_ten(char *nbr, char *base, int base_size)
{
	int	nbr_idx;
	int	base_idx;
	int	sum;
	int	backup_base_size;

	nbr_idx = 0;
	base_idx = 0;
	backup_base_size = base_size;
	base_size = 1;
	while (nbr[nbr_idx] != '\0')
	{
		base_idx = 0;
		while (nbr[nbr_idx] != base[base_idx])
		{
			base_idx++;
			if (base[base_idx] == '\0')
				return (sum);
		}
		sum = sum * base_size + base_idx;
		base_size = backup_base_size;
		nbr_idx++;
	}
	return (sum);
}

void	ft_count_digit(int *count, int base_decimal, int base_to_size)
{
	if (base_decimal >= base_to_size)
	{
		ft_count_digit(count, base_decimal / base_to_size, base_to_size);
		(*count)++;
	}
	else
	{
		(*count)++;
		return ;
	}
	return ;
}

char	*ft_putnbr_base(int base_decimal, char *base_to, \
	int base_to_size)
{
	int		count;
	int		end_idx;
	int		i;
	char	*base_digits;

	i = 0;
	ft_count_digit(&count, base_decimal, base_to_size);
	end_idx = count - 1;
	base_digits = (char *)malloc((sizeof(char) * count) + 1);
	while (i < count)
	{
		base_decimal /= base_to_size;
		base_digits[end_idx] = base_to[base_decimal % base_to_size];
		end_idx--;
		i++;
	}
	base_digits[count] = '\0';
	return (base_digits);
}
