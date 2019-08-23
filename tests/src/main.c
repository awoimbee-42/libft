#include <tests.h>

int		main(void)
{
	SRunner	*sr;
	int		nf;

	printf(PRTF_GRN "Testing libft..." PRTF_EOC "\n");
	srandom(time(NULL));
	sr = srunner_create(suite_create(""));

	build_tests_libmem(sr);
	build_tests_libstr(sr);

	srunner_run_all(sr, CK_ENV);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (nf == 0 ? 0 : 1);
}
