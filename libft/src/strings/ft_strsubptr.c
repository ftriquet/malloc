/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 20:22:02 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/03 20:31:44 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsubptr(char *beg, char *end)
{
	char	*res;

	if (!(res = malloc((end - beg + 1) * sizeof(*res))))
		return (NULL);
	ft_strncpy(res, beg, end - beg);
	res[end - beg] = '\0';
	return (res);
}
