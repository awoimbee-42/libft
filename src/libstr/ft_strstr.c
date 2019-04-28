/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:54:33 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 04:54:27 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_found(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return (1);
	if (*haystack == '\0' || *haystack != *needle)
		return (0);
	if (*haystack == *needle)
	{
		return (is_found(haystack + 1, needle + 1));
	}
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (is_found(haystack, needle))
			return ((char *)haystack);
		++haystack;
	}
	return (0);
}
