/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:32 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 02:06:38 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_manager_00(void)
{
	write(1, "just a comment:\n", 16);
	write(1, "error_manager00.c file is to add additional things \
			  to handle errors perfectly", 1);
}
