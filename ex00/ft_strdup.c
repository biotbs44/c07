/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyang <jungyang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:12:03 by jungyang          #+#    #+#             */
/*   Updated: 2021/09/29 13:21:56 by jungyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	count;
	int	idx;

	idx = 0;
	count = 0;
	while (src[idx] != '\0')
	{
		idx++;
		count++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*temp;

	temp = (char *)malloc(ft_strlen(src) + 1);
	if (temp == NULL)
		return (NULL);
	else
		return (ft_strcpy(temp, src));
}
