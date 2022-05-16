/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:28:11 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/16 11:14:54 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	shell_lvl(t_envp *envp)
{
	t_envp	*shlvl;
	int		lvl;
	char	*lvl_str;

	shlvl = find_node("SHLVL", envp);
	if (ft_strcmp(shlvl->value, "") == 0)
		return ;
	lvl = ft_atoi(shlvl->value)+ 1;
	ft_memdel(shlvl->value);
	ft_memdel(shlvl->str);
	lvl_str = ft_itoa(lvl);
	shlvl->value = lvl_str;
	shlvl->str = ft_strjoin("SHLVL=", shlvl->value);
}