/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:36:53 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/30 23:42:37 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_prtf.h>
#include <libft/t_fstream.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void			ft_fstream_kill(t_fstream **dat)
{
	t_fstream	*d;

	if (!dat || !*dat)
		return ;
	d = *dat;
	if (d->priv.type != FSTREAM_BUF_MUT)
		free(d->priv.buf);
	if (d->priv.fname && __builtin_expect((close(d->priv.fd) == -1), 0))
		ft_printf("Could not close %s: %s", d->priv.fname, strerror(errno));
	free(d);
	*dat = NULL;
}
