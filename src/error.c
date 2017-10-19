/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:40 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:05:42 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	ft_free_env(t_env *env)
{
	if (env)
	{
		if (env->room)
			ft_free_list(&env->room);
		if (env->init)
			ft_free_list(&env->init);
		if (env->road)
			ft_free_road(&env->road);
		if (env->start)
			ft_strdel(&env->start);
		if (env->end)
			ft_strdel(&env->end);
		free (env);
	}
}

void 	ft_free_road(t_road **road)
{
	t_road *tmp;

	tmp = (*road);
	while (tmp)
	{
		tmp = (*road)->next;
		if ((*road)->src)
			free((*road)->src);
		if ((*road)->dest)
			free((*road)->dest);
		free(*road);
		*road = tmp;
	}
}

void 	ft_free_list(t_list **list)
{
	t_list *tmp;

	tmp = (*list);
	while (tmp)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

void 	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

void 	ft_error(t_env *env)
{
	ft_free_env(env);
	ft_printf("Error\n");
	exit(1);
}

void 	malloc_error()
{
	exit(1);
}
