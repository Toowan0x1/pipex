/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_sep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:27:43 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/25 10:18:11 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup_sep(char *s, char sep)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[n] && (s[n] != sep))
		n++;
	ret = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
