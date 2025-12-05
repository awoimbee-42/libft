/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:13:17 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/09 19:36:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/ft_nb.h>
#include <libft/ft_str.h>

/*
**	msg_exit : a printf for crashing cleanly.
**	USAGE : msg_exit("error %[d, s]...", memory)
**		%s = string (char*)
**		%d = int
**	When %[...] is read,
**	 msg_exit will interpret memory as pointing to the specified datatype.
*/

void	msgexit__static_itoa(char* buf, int n)
{
	int			i;
	short		sign;
	int			tenpow;

	sign = (n < 0) ? 2 : 1;
	i = 1;
	tenpow = 1;
	while ((n / tenpow / 10) != 0 && ++i)
		tenpow *= 10;
	i = 0;
	if (sign == 2 && (sign = -1))
		buf[i++] = '-';
	while (tenpow != 0)
	{
		buf[i++] = (char)((int)n / tenpow * sign + 48);
		n %= tenpow;
		tenpow /= 10;
	}
	buf[i++] = '\0';
}

void	ft_msg_exit(const char *msg, const void *data)
{
	size_t	len;
	char	buf[128];

	if (msg)
	{
		while (*msg)
		{
			len = 1;
			while (msg[len] && msg[len-1] != '%')
				++len;
			write(2, (void *)msg, len);
			if (msg[len] == 'd')
			{
				msgexit__static_itoa(buf, *(int*)data);
				write(2, buf, ft_strlen(buf));
				len += 2;
			}
			else if (msg[len+1] == 's')
			{
				write(2, data, ft_strlen(data));
				len += 2;
			}
			msg = &msg[len];
		}
		write(2, "\n", 1);
	}
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}
