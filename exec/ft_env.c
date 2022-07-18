/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:54:41 by marvin            #+#    #+#             */
/*   Updated: 2022/06/15 16:54:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void    init_env(t_env **env_v, char **env)
{
    t_env	*new;
	char	**spl;	
    int i;

    new = NULL;
    i = 0;
    while (env[i])
    {
		if (strstr(env[i], "="))
		{
			spl = ft_split(env[i],'=');
        	new = ft_lstnew(spl[0], spl[1]);
			free(spl);
		}
		else
			new->name = env[i];
		if (env_v != NULL && new != NULL)
        	ft_lstadd_back(env_v, new);
		
        i++;
	}
}

void	ft_env(t_env **env_v, char **av)
{
	t_env *env;
	int i;

	i = 0;
	env = *env_v;
	if (av[i + 1] == '\0' && search_element(env_v, "PATH"))
	{
		while (env)
		{
			if (env->data != NULL)
				printf("%s=%s\n",env->name , env->data);
			env = env->next;
		}
	}
	else
	{
		get_nb_status = 127;
		if (search_element(env_v, "PATH"))
			printf("env : %s :  No such file or directory\n", av[i + 1]);
		else
			printf("env : No such file or directory\n");
	}
}
