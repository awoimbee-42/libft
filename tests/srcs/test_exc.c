/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 22:34:28 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/10 12:34:50 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

void	test_exc(void (*f)(void))
{
	jmp_buf 	env;
	int 		val;


	val = setjmp(env);
	if (!val) 
	{
		f();
		longjmp(env, val);
	}
	else if (val != 1) // skip NULL env error if val == 1
	{
		fprintf(stderr,KRED"ERROR: The jmp_buf was %d\n"RESET, val);
	}
}
