/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:37:24 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/09 19:35:13 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
#define FT_EXIT_H

void			ft_msg_exit(const char *msg, const void *data);
void			ft_assert(int exp, const char *fmt, ...);

/* assert for pointers, doesn't use any memory alocation (uses msg_exit) */
void			ft_assertp_safe(void *notnul, const char *msg, const void *d);

#endif
