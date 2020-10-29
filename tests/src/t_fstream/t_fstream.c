/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fstream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:45:06 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/29 22:30:36 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "t_fstream.h"
#include <libft.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_SIZE (1024 * 1024)

START_TEST (t_fstream_fd)
{
	t_fstream *fstream;
	int fd;
	char buf[READ_SIZE];
	char buf2[READ_SIZE];

	fd = open("./Makefile", O_RDONLY);
	read(fd, buf, READ_SIZE);
	lseek(fd, 0, SEEK_SET);
	buf2[0] = '\0';
	fstream = ft_fstream_setup_fd(fd, 123);
	while(ft_fstream(fstream))
		strncat(buf2, (char*)fstream->p.buf, fstream->p.len);
	ft_fstream_kill(fstream);
	ck_assert(strcmp(buf, buf2) == 0);
}
END_TEST

START_TEST (t_fstream_fname)
{
	t_fstream *fstream;
	int fd;
	char buf[READ_SIZE];
	char buf2[READ_SIZE];

	fd = open("./Makefile", O_RDONLY);
	read(fd, buf, READ_SIZE);
	close(fd);
	buf2[0] = '\0';
	fstream = ft_fstream_setup_fname("./Makefile", 1);
	while(ft_fstream(fstream))
		strncat(buf2, (char*)fstream->p.buf, fstream->p.len);
	ft_fstream_kill(fstream);
	ck_assert(strcmp(buf, buf2) == 0);

	buf2[0] = '\0';
	fstream = ft_fstream_setup_fname("./Makefile", 999999);
	while(ft_fstream(fstream))
		strncat(buf2, (char*)fstream->p.buf, fstream->p.len);
	ft_fstream_kill(fstream);
	ck_assert(strcmp(buf, buf2) == 0);

}
END_TEST

START_TEST (t_fstream_str)
{
	t_fstream *fstream;
	char buf0[] = "huifsduigiugILGIUFSFSDFuifslgew";
	char buf1[32];

	buf1[0] = '\0';
	fstream = ft_fstream_setup_str(buf0, 5);
	while(ft_fstream(fstream))
		strncat(buf1, (char*)fstream->p.buf, fstream->p.len);
	ft_fstream_kill(fstream);
	ck_assert(strcmp(buf0, buf1) == 0);
}
END_TEST


Suite	*build_suite_t_fstream(void)
{
	Suite	*s = suite_create("t_fstream");
	TCase	*tc = tcase_create("t_fstream");
	suite_add_tcase(s, tc);
	tcase_add_test(tc, t_fstream_fd);
	tcase_add_test(tc, t_fstream_fname);
	tcase_add_test(tc, t_fstream_str);
	return (s);
}


void		build_tests_t_fstream(SRunner *sr)
{
	srunner_add_suite(sr, build_suite_t_fstream());
}
