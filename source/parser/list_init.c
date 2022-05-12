/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:32 by yono              #+#    #+#             */
/*   Updated: 2022/05/12 10:48:04 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_val(char *env)
{
	int		start;
	char	*res;

	start = 0;
	while (env[start] && env[start] != '=')
		start++;
	res = ft_substr(env, ++start, ft_strlen(env));
	return (res);	
}

char	*get_key(char *env)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (env[len] != '=')
		len++;
	env[len] = '\0';
	res = ft_calloc(len, sizeof(char));
	if (!res)
		ft_error(ERR_ALLOC);
	while (++i < len)
		res[i] =  env[i];
	return (res);	
}

char	*get_kval(char *env)
{
	char	*res;
	int		i;
	int		len_ev;

	i = -1;
	len_ev = ft_strlen(env);
	res = ft_calloc((len_ev + 1), sizeof(char));
	if (!res)
		ft_error(ERR_ALLOC);
	while (++i < len_ev)
		res[i] = env[i];
	return (res);	
}

int	count_len_arr(char **arr)
{
	int	i;

	i = 0;
	while (*(arr + i))
		i++;
	return(i);
}