/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:10:28 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/13 16:22:19 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	envp_init(t_shell *shell, char **envp)
{
	t_envp	*env;
	t_envp	*new;
	int		i;

	if (!(env = malloc(sizeof(t_envp))))
		ft_error(ERR_ALLOC);
	env->str = ft_strdup(envp[0]);
	env->next = NULL;
	shell->envp = env;
	i = 1;
	while (envp && envp[0] && envp[i])
	{
		if (!(new = malloc(sizeof(t_envp))))
			ft_error(ERR_ALLOC);
		new->str = ft_strdup(envp[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
}