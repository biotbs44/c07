/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:10:29 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/29 17:26:50 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (src[idx] != '\0')
	{
		count++;
		idx++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (temp);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	**string;
	char	*ret;
	int		sum;
	int		string_idx;

	string = strs;
	sum = 0;
	sum += ft_strlen(string[0]);
	string_idx = 1;
	while (string_idx < size)
		sum += ft_strlen(sep) + ft_strlen(string[string_idx++]);
	if (size == 0)
	{
		ret = (char *)malloc(0);
		return (ret);
	}
	ret = (char *)malloc((sizeof(char) * sum) + 1);
	ft_strcpy(ret, string[0]);
	string_idx = 1;
	while (string_idx < size)
	{
		ft_strcat(ret, sep);
		ft_strcat(ret, string[string_idx++]);
	}	
	return (ret);
}
