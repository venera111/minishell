// void	free_env(t_envp *envp)
// {
// 	t_envp	*tmp;

// 	while (envp)
// 	{
// 		if (envp->next)
// 		{
// 			tmp = envp;
// 			envp = envp->next;
// 		}
// 		ft_memdel(tmp->str);
// 		ft_memdel(tmp->key);
// 		ft_memdel(tmp->value);
// 		ft_memdel(tmp);
// 	}
// 	ft_memdel(envp);
// }