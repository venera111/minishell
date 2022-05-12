/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:52:06 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 10:48:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define ERR_ALLOC	"failed to allocated memory"

typedef struct	s_cmd
{
	int				fd[2];
	int				fd_in;
	int				fd_out;
	int				num_args;
	char			**cmnds;
}				t_cmd;

typedef struct	s_envp
{
	char			*key;
	char			*val;
	char			*kval;
	struct s_envp	*next;
	struct s_envp	*prev;
}				t_envp;

typedef struct s_var_box
{
	int				env_count;
}				t_var_box;

/*
** enviroments
*/
void	make_list(t_envp **ev_list, char **env, int ev_len);
char	**make_env_arr(char **src, int len_src);
void	create_node(t_envp **ev_list, char *env);
void	push_back(t_envp **list, t_envp **new);
t_envp	*get_last(t_envp *head);
char	*get_val(char *env);
char	*get_key(char *env);
char	*get_kval(char *env);
int		count_len_arr(char **arr);

/*
** builtins
*/
int		echo(t_cmd *node);

/*
** clear
*/
void	clear(t_cmd *node);
void	free_arr(char **arr, int arr_len);
void	free_env(t_envp **lst);
void	delete_node(t_envp *node);

void	ft_error(char *s);

#endif