/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:23:39 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 04:46:32 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	write_heredoc(char *limiter, int fd[2])
{
	size_t	limiter_length;
	char	*line;

	limiter_length = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("pipex here_doc> ", 1);
		line = get_next_line(STDIN);
		if (!line)
		{
			close(fd[0]);
			close(fd[1]);
			exit(EXIT_FAILURE);
		}
		if (line[limiter_length] == '\n' && limiter && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close(fd[0]);
			close(fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = NULL;
	}
}

void	piping_heredoc(int ac, char **av)
{
	pid_t	ps;
	int		fd[2];

	if (ac != 6)
		error_argc_bonus();
	pipe(fd);
	ps = fork();
	if (ps)
	{
		dup2(fd[0], STDIN);
		close(fd[0]);
		close(fd[1]);
		waitpid(ps, NULL, 0);
	}
	else if (ps == 0)
		write_heredoc(av[2], fd);
}
