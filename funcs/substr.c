/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:53:58 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/25 10:19:00 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*x;

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (len >= slen)
		len = slen;
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (x == NULL)
		return (NULL);
	i = 0;
	if (slen > start)
	{
		while (i < len)
		{
			x[i] = s[start];
			start++;
			i++;
		}
	}
	x[i] = '\0';
	return (x);
}
