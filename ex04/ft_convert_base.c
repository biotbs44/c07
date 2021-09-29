/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:06:40 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/30 00:28:27 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_convert_base.h"
#include <stdlib.h>

char	*ft_check_str(char *nbr, int *p_odd)
{
	int	idx;

	idx = 0;
	while (nbr[idx] == '\t' || nbr[idx] == '\n' \
		|| nbr[idx] == ' ')
		idx++;
	while (nbr[idx] == '-' || nbr[idx] == '+')
	{
		if (nbr[idx] == '-')
			*p_odd *= -1;
		idx++;
	}
	return (nbr);
}

int	ft_check_base(char *base, int base_size)
{
	int	idx;
	int	next_idx;

	idx = 0;
	next_idx = 0;
	if (*base == '\0' || base_size == 1)
		return (1);
	while (idx < base_size - 1)
	{
		next_idx = idx + 1;
		while (next_idx < base_size)
		{
			if (base[idx] == base[next_idx])
				return (1);
			next_idx++;
		}
		idx++;
	}
	idx = -1;
	while (++idx < base_size)
		if (base[idx] == '+' || base[idx] == '-' || base[idx] == ' ' || \
			base[idx] == '\n' || base[idx] == '\t')
			return (1);
	return (0);
}

int	ft_check_params(char *base_from, int base_from_size, \
					char *base_to, int base_to_size)
{
	if (ft_check_base(base_from, base_from_size) && \
		(ft_check_base(base_to, base_to_size)))
		return (1);
	return (0);
}

int	ft_strlen(char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	return (count);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_size;
	int		base_to_size;
	int		base_decimal;
	int		odd;
	char	*ret;

	odd = 1;
	base_from_size = ft_strlen(base_from);
	base_to_size = ft_strlen(base_to);
	if (ft_check_params(base_from, base_from_size, \
						base_to, base_to_size))
		return (NULL);
	nbr = (ft_check_str(nbr, &odd));
	base_decimal = ft_base_to_ten(nbr, base_from, base_from_size);
	ret = ft_putnbr_base(base_decimal, base_to, base_to_size);
	return (ret);
}
