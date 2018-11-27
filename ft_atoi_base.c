/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:11:26 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/27 17:08:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	str_to_int(char *input, long int coeff, int base_coeff, char *base)
{
	int		return_nb;
	int		digit;

	return_nb = 0;
	while (*input)
	{
		digit = 0;
		while (base[digit])
		{
			if (base[digit] == *input)
			{
				return_nb += digit * coeff;
				break ;
			}
			++digit;
		}
		++input;
		coeff /= base_coeff;
	}
	return (return_nb);
}

static int	allowed_char(char *tested, char *base, int check_duplicate)
{
	int		i;

	i = -1;
	if (*tested == '+'
		|| *tested == '-'
		|| *tested < 33
		|| *tested > 126)
		return (0);
	if (check_duplicate)
	{
		while (&base[++i] < tested)
		{
			if (base[i] == *tested)
				return (0);
		}
		return (1);
	}
	return (1);
}

static int	get_base_len(char *base)
{
	long int	baselen;
	int			base_start;
	int			base_end;

	baselen = -1;
	while (base[++baselen])
	{
		if (!allowed_char(&base[baselen], base, 1) || baselen > 2147483647)
			return (0);
	}
	base_start = 0;
	base_end = baselen;
	while (base_start < (base_end - 1))
	{
		while (base_start < --base_end)
		{
			if (base[base_start] == base[base_end])
				return (0);
			++base_start;
		}
		base_start = 0;
	}
	return (baselen);
}

int			ft_atoi_base(char *str, char *base)
{
	char		*str_start;
	long int	coeff;
	int			base_coeff;

	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		++str;
	base_coeff = get_base_len(base);
	if (base_coeff < 2)
		return (0);
	coeff = 1;
	if (*str == '-' && ++str)
		coeff = -1;
	else if (*str == '+')
		++str;
	str_start = str;
	while (allowed_char(str, base, 0))
	{
		coeff *= base_coeff;
		++str;
	}
	coeff /= base_coeff;
	return (str_to_int(str_start, coeff, base_coeff, base));
}
