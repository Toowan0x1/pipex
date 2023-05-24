/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-houm <oel-houm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:05:46 by oel-houm          #+#    #+#             */
/*   Updated: 2022/11/27 15:58:11 by oel-houm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define PIPEX_MSG		"pipex: "
# define ERRMSG_ARGC    "invalid number of arguments.\n"
# define ERRMSG_USAGE0  "usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERRMSG_USAGE1  "usage: ./pipex <file1> <cmd1> <cmd2>...<cmdn> <file2>\n"
# define ERRMSG_USAGE2  "usage: ./pipex here_doc LIMITER <cmd1> <cmd2> <file>\n"
# define ERRMSG_NOTCMD  ": command not found\n"
# define ERRMSG_NOFILE  ": no such file or directory\n"
# define ERRMSG_NOPERM  ": permission denied\n"

# define GNL_BUFFER_SIZE    1

# define STDIN      0
# define STDOUT     1
# define STDERR     2

# define INFILE     0
# define OUTFILE    1

typedef struct s_files
{
	int	input;
	int	output;
}	t_files;

char	*get_next_line(int fd);
char	*ft_line(char **line, char **str, int fd, int ret);
char	*ft_next(char **line, char **str);

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_strichr(char *str, char c);
char	*ft_strdup(char *s1);
char	*ft_strdup_sep(char *s, char sep);
char	**ft_split(char *s, char sep);
void	ft_putstr_fd(char *s, int fd);

void	error_argc_mandatory(void);
void	error_argc_bonus(void);
void	error_nofile(char *filename);
void	error_notcmd(char *cmd_name);
void	erro_noperm(char *cmd_name);

int		openfile(char *filename, int mode);
void	piping(char *cmd, char **env, int outputfile);
void	piping_child_cmd(char *cmd, char **env, int outputfile);
void	exec_cmd(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
char	*path_join(char *dir, char *cmd);
void	piping_heredoc(int ac, char **av);
void	write_heredoc(char *limiter, int fd[2]);

#endif
