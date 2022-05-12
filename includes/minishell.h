/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:52:06 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 16:11:14 by qestefan         ###   ########.fr       */
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
	char			*val;
	char			*kval;
	struct s_envp	*next;
	struct s_envp	*prev;
}				t_envp;

/*
** shell struct
*/
typedef struct s_shell
{
	char			**env_arr;
	char			*tmp_cwd;
	int				env_count;
	t_envp			*ev;
	t_envp			*tmp;
	t_cmd			node;
	int				i;
}				t_shell;

/*
** enviroments
*/
void	make_list(t_envp **ev_list, char **env, int ev_len);
void	create_node(t_envp **ev_list, char *env);
char	**make_env_arr(char **src, int len_src);
void	push_back(t_envp **list, t_envp **new);
int		count_len_arr(char **arr);
t_envp	*get_last(t_envp *head);
char	*get_kval(char *env);
char	*get_val(char *env);
char	*get_key(char *env);

/*
** builtins
*/
int		echo(t_cmd *node);
void	cd(t_shell *shell);

/*
** clear
*/
void	free_arr(char **arr, int arr_len);
void	delete_node(t_envp *node);
void	free_env(t_envp **lst);
void	free_builtins(t_cmd *node);
void	clear_all(t_shell *shell);

/*
** error
*/
void	ft_error(char *s);

#endif