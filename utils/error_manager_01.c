/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:53:32 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 15:51:19 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_argc_mandatory(void)
{
	ft_putstr_fd(PIPEX_MSG, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_ARGC, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_USAGE0, STDERR_FILENO);
	exit(1);
}

void	error_argc_bonus(void)
{
	ft_putstr_fd(PIPEX_MSG, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_ARGC, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_USAGE1, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_USAGE2, STDERR_FILENO);
	exit(1);
}

void	error_notcmd(char *cmd_name)
{
	ft_putstr_fd(PIPEX_MSG, STDERR_FILENO);
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_NOTCMD, STDERR_FILENO);
	exit(127);
}

void	error_noperm(char *filename)
{
	ft_putstr_fd(PIPEX_MSG, STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_NOPERM, STDERR_FILENO);
	exit(126);
}

void	error_nofile(char *filename)
{
	ft_putstr_fd(PIPEX_MSG, STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(ERRMSG_NOFILE, STDERR_FILENO);
	exit(1);
}
