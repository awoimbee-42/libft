/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:05:02 by awoimbee          #+#    #+#             */
/*   Updated: 2019/01/02 00:51:28 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prtf__atoi_move(const char **nptr)
{
	short int		sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	while (**nptr == ' ' || **nptr == '\n' || **nptr == '\t'
		|| **nptr == '\f' || **nptr == '\v' || **nptr == '\r')
		++(*nptr);
	if (**nptr == '-' && ++(*nptr))
		sign = -1;
	else if (**nptr == '+')
		++(*nptr);
	while ('0' <= **nptr && **nptr <= '9')
		result = result * 10UL + ((unsigned long)*((*nptr)++) - 48UL);
	return ((int)result * sign);
}

int		prtf__t_strncat(t_string *s1, char const *s2, size_t size)
{
	char		*nw_str;

	if ((!s1->str) && s2 && size != 0)
	{
		if (!(nw_str = ft_strnew(size)))
			prtf__msg_exit(MALLOC_ERR);
		ft_memcpy(nw_str, s2, size);
		s1->str = nw_str;
		s1->len = size;
	}
	else if (s2 && size != 0)
	{
		if (!(nw_str = ft_strnew(size + s1->len)))
			prtf__msg_exit(MALLOC_ERR);
		ft_strncat(ft_mempcpy(nw_str, s1->str, s1->len), s2, size);
		free(s1->str);
		s1->str = nw_str;
		s1->len += size;
	}
	return (1);
}

int		prtf__msg_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	write(1, "error.\n", 7);
	exit(EXIT_FAILURE);
}

char	*prtf__strsubrev(char *str, int begin)
{
	char	*start;
	char	*end;
	char	buff;

	start = str + begin;
	end = str;
	while (*(end + 1))
		++end;
	while (start < end)
	{
		buff = *start;
		*start = *end;
		*end = buff;
		start++;
		end--;
	}
	return (str);
}
