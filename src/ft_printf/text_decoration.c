/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_decoration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:59:21 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 20:36:21 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		color_part2(char *out)
{
	if (!ft_strncmp(out + 1, "cyn", 3))
		ft_memcpy(out, "\e[36m", 5);
	else if (!ft_strncmp(out + 1, "CYN", 3))
		ft_memcpy(out, "\e[96m", 5);
	else if (!ft_strncmp(out + 1, "wht", 3))
		ft_memcpy(out, "\e[37m", 5);
	else if (!ft_strncmp(out + 1, "WHT", 3))
		ft_memcpy(out, "\e[97m", 5);
	else if (!ft_strncmp(out + 1, "inv", 3))
		ft_memcpy(out, "\e[7m", 5);
	else if (!ft_strncmp(out + 1, "eoc", 3))
		ft_memcpy(out, "\e[39m", 5);
}

static void		set_color(char *out)
{
	if (!ft_strncmp(out + 1, "red", 3))
		ft_memcpy(out, "\e[31m", 5);
	else if (!ft_strncmp(out + 1, "RED", 3))
		ft_memcpy(out, "\e[91m", 5);
	else if (!ft_strncmp(out + 1, "grn", 3))
		ft_memcpy(out, "\e[32m", 5);
	else if (!ft_strncmp(out + 1, "GRN", 3))
		ft_memcpy(out, "\e[92m", 5);
	else if (!ft_strncmp(out + 1, "ylw", 3))
		ft_memcpy(out, "\e[33m", 5);
	else if (!ft_strncmp(out + 1, "YLW", 3))
		ft_memcpy(out, "\e[93m", 5);
	else if (!ft_strncmp(out + 1, "blu", 3))
		ft_memcpy(out, "\e[34m", 5);
	else if (!ft_strncmp(out + 1, "BLU", 3))
		ft_memcpy(out, "\e[94m", 5);
	else if (!ft_strncmp(out + 1, "pnk", 3))
		ft_memcpy(out, "\e[35m", 5);
	else if (!ft_strncmp(out + 1, "PNK", 3))
		ft_memcpy(out, "\e[95m", 5);
	else
		color_part2(out);
}

static void		set_decoration(char *out)
{
	if (!ft_strncmp(out, "<underline>", 11))
		ft_memcpy(out, "\e[00000004m", 11);
	else if (!ft_strncmp(out, "</underline>", 12))
		ft_memcpy(out, "\e[000000024m", 12);
	else if (!ft_strncmp(out, "<bold>", 6))
		ft_memcpy(out, "\e[001m", 6);
	else if (!ft_strncmp(out, "</bold>", 7))
		ft_memcpy(out, "\e[0022m", 7);
	else if (!ft_strncmp(out, "<rst>", 5))
		ft_memcpy(out, "\e[00m", 5);
}

void			prtf__parse_bonus(t_string *out)
{
	size_t	i;

	i = 0;
	while (i < out->len)
	{
		if (out->str[i] == '{' && out->str[i + 4] == '}')
			set_color(&out->str[i]);
		else if (out->str[i] == '<')
			set_decoration(&out->str[i]);
		++i;
	}
}
