/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:22:01 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/25 10:18:05 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	count_strlen_sep(char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != sep))
		i++;
	return (i);
}

int	count_strings(char *s, char sep)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s == sep && trigger == 1)
		{
			trigger = 0;
		}
		else if (*s != sep && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		s++;
	}
	return (count);
}

char	*charge_string(char *s, char c)
{
	int		total_len;
	int		i;
	char	*str;

	i = 0;
	total_len = count_strlen_sep(s, c);
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	while (i < total_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char sep)
{
	char	**strings;
	int		total_strs;
	int		i;

	i = 0;
	total_strs = count_strings(s, sep);
	strings = (char **)malloc(sizeof(char *) * total_strs + 1);
	if (!strings)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == sep))
			s++;
		if (*s)
		{
			strings[i] = charge_string(s, sep);
			i++;
		}
		while (*s && (*s != sep))
			s++;
	}
	strings[i] = NULL;
	return (strings);
}
