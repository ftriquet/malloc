/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:57:47 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/02 18:54:25 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_match(char *string, char *regex)
{
	if (!*string && !*regex)
		return (1);
	if (!*string && *regex == '*')
		return (ft_match(string, ++regex));
	if (*regex == '*' && *string)
		return (ft_match(++string, regex) || ft_match(--string, ++regex));
	if (*string == *regex)
		return (ft_match(++string, ++regex));
	return (0);
}
