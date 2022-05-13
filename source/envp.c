/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:10:28 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/13 20:16:54 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_envp	*find_node(char *key, t_envp *envp)
{
	while (envp)
	{
		if (ft_strcmp(key, envp->key))
			envp = envp->next;
		else
			break ;
	}
	return (envp);
}

static void	fill_envp(char *env, t_envp *node)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i] == '=')
		{
			node->key = ft_substr(env, 0, i);
			node->value = ft_substr(env, i + 1, \
				ft_strlen(env) - ft_strlen(node->key));
			node->str = ft_strdup(env);
		}
	}
}

void	envp_init(t_shell *shell, char **envp)
{
	t_envp	*env;
	t_envp	*new;
	int		i;

	env = malloc(sizeof(t_envp));
	if (!env)
		ft_error(ERR_ALLOC);
	fill_envp(envp[0], env);
	env->next = NULL;
	env->prev = NULL;
	shell->envp = env;
	i = 1;
	while (envp && envp[0] && envp[i])
	{
		new = malloc(sizeof(t_envp));
		if (!new)
			ft_error(ERR_ALLOC);
		fill_envp(envp[i], new);
		new->prev = env;
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
}
