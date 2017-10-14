/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:27:25 by arosset           #+#    #+#             */
/*   Updated: 2017/10/14 14:27:26 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_set_init(t_set *set, int (*ft_match)(void *k1, void *k2)
		, void (*ft_destroy)(void *data))
{
	ft_list_init(set, ft_destroy);
	set->ft_match = ft_match;
}

int		ft_set_insert(t_set *set, void *data)
{
	if (ft_set_ismember(set, data) == 1)
		return (1);
	return (ft_list_ins_next(set, LIST_TAIL(set), data));
}

int		ft_set_remove(t_set *set, void **data)
{
	t_listelem		*tmp;
	t_listelem		*ptr;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(*data, LIST_DATA(tmp)) == 0)
			break ;
		ptr = tmp;
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	return (ft_list_rem_next(set, ptr, data));
}

int		ft_set_ismember(t_set *set, void *data)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(data, LIST_DATA(tmp)) == 0)
			return (1);
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_issubnet(t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	if (LIST_SIZE(set1) > LIST_SIZE(set2))
		return (0);
	tmp = LIST_HEAD(set1);
	while (tmp != NULL)
	{
		if (ft_set_ismember(set2, LIST_DATA(tmp)) == 0)
			return (0);
		tmp = LIST_NEXT(tmp);
	}
	return (1);
}
