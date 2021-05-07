/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:25:50 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/26 06:56:18 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start < slen)
	{
		if (len > slen)
			len = slen - start + 1;
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	else
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = 0;
	}
	return (str);
}
