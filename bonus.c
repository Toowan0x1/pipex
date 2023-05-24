/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:29:32 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 01:21:34 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piping_child_cmd(char *cmd, char **env, int outputfile)
{
	pid_t	ps;
	int		fd[2];

	pipe(fd);
	ps = fork();
	if (ps == 0)
	{
		if (outputfile == -1)
		{
			close(fd[0]);
			close(fd[1]);
			exit(EXIT_FAILURE);
		}
		dup2(fd[1], STDOUT);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(cmd, env);
	}
	dup2(fd[0], STDIN);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, NULL, WNOHANG);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd, ' ');
	if (ft_strichr(cmd_args[0], '/') > -1)
		path = cmd_args[0];
	else
		path = get_path(cmd_args[0], env);
	execve(path, cmd_args, env);
	error_notcmd(cmd);
}

char	*path_join(char *dir, char *cmd)
{
	char	*ret;
	int		total_lens;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_lens = ft_strlen(dir) + ft_strlen(cmd);
	ret = malloc(sizeof(char) * (total_lens + 2));
	while (dir[i])
	{
		ret[j] = dir[i];
		j++;
		i++;
	}
	ret[j++] = '/';
	i = 0;
	while (cmd[i])
	{
		ret[j] = cmd[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strdup_sep(path, ':');
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

int	main(int ac, char **av, char **env)
{
	t_files	files;
	int		cmd_index;

	cmd_index = 2;
	if (!(ac >= 5))
		error_argc_bonus();
	else if (av[1] && !ft_strncmp(av[1], "here_doc", 8) && av[1][8] == '\0')
	{
		cmd_index = 3;
		piping_heredoc(ac, av);
		files.output = openfile(av[5], STDOUT);
	}
	else
	{
		files.input = openfile(av[1], INFILE);
		files.output = openfile(av[ac - 1], OUTFILE);
		dup2(files.input, STDIN);
		dup2(files.output, STDOUT);
	}
	while (cmd_index < ac - 2)
		piping_child_cmd(av[cmd_index++], env, files.output);
	dup2(files.output, STDOUT);
	exec_cmd(av[ac - 2], env);
	return (1);
}
