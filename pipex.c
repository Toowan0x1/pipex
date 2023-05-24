/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:32:03 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 04:48:19 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	piping(char *cmd, char **env, int outputfile)
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
		close(fd[0]);
		dup2(fd[1], STDOUT);
		exec_cmd(cmd, env);
	}
	else if (ps)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(ps, NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_files	files;

	if (ac == 5)
	{
		files.input = openfile(av[1], INFILE);
		files.output = openfile(av[4], OUTFILE);
		dup2(files.input, STDIN);
		dup2(files.output, STDOUT);
		piping(av[2], env, files.output);
		exec_cmd(av[3], env);
	}
	else
		error_argc_mandatory();
	return (1);
}
