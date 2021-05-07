/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:57:19 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/26 08:27:06 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) * sizeof(char) + 1);
	return (dest);
}
