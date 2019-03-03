/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:08:51 by qsebasti          #+#    #+#             */
/*   Updated: 2017/12/02 20:47:35 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstclean(t_list **lst)
{
	void	(*del)(void *a, size_t b);

	del = &ft_dellist;
	ft_lstdel(lst, del);
	return (0);
}
