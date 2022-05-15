/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:52:06 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 19:29:42 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/param.h>

/*
** warnings
*/
# define ERR_ALLOC	"failed to allocated memory"

/*
** pipes and command struct
*/
typedef struct	s_cmd
{
	int				fd[2];
	int				fd_in;
	int				fd_out;
	int				num_args;
	char			**cmnds;
}				t_cmd;

/*
** enviroments struct
*/
typedef struct	s_envp
{
	char			*key;
	char			*value;
	char			*str;
	struct s_envp	*next;
	struct s_envp	*prev;
}				t_envp;

/*
** shell struct
*/
typedef struct s_shell
{
	char			**env_arr; //переменные окружения
	char			*tmp_cwd;
	int				env_count;
	char			arr[MAXPATHLEN];
	t_envp			*envp; //переменные окружения
	t_envp			*start;
	t_envp			*tmp;
	t_cmd			node;
	int				i;
}				t_shell;

/*
** enviroments
*/
void	envp_init(t_shell *shell, char **envp);
char	**make_env_arr(char **src, int len_src);
t_envp	*find_node(char *key, t_envp *envp);

/*
** builtins
*/
int		echo(t_cmd *node);
void	cd(t_shell *shell);
void	pwd(t_shell *shell);
void	export(t_shell *shell);

/*
** clear
*/
void	free_arr(char **arr, int arr_len);
void	delete_node(t_envp *node);
void	free_env(t_envp *envp);
void	free_builtins(t_cmd *node);
void	clear_all(t_shell *shell);

/*
** error
*/
void	ft_error(char *s);

#endif