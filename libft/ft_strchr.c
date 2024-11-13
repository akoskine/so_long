/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:37:53 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:19:21 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	if (!s)
		return (0);
	ret = (char *)s;
	while (*ret != (char )c)
	{
		if (*ret == '\0')
			return (0);
		ret++;
	}
	return (ret);
}
