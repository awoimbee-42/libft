
// C program for Red-Black Tree insertion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libft.h"

#define RBTREE_NB_ELEMS 10000
#define RBTREE_NB_TESTS 50

int g_tmp0 = 0;

void	check_rbtree(struct s_rbt_node *root)
{
	static int last = __INT_MAX__ + 1;

	if (root == NULL)
		return;
	check_rbtree(root->lft);
	++g_tmp0;
	if (root->dat < last)
		printf("RED AND BLACK TREE NOT IN ORDER !\n"
			"current: %d last: %d\n",
			root->dat, last);
	last = root->dat;
	check_rbtree(root->rgt);
	last = __INT_MAX__ + 1;
}

void	test_rbtree(void)
{
	struct s_rbt_node *root = NULL;

	for (int i = 0; i < 50; ++i)
	{
		clock_t t0 = clock();
		for (int i = 0; i < RBTREE_NB_ELEMS; ++i)
			rbt_insert(&root, random());
		clock_t t1 = clock();
		check_rbtree(root);
		if (g_tmp0 != RBTREE_NB_ELEMS)
			printf("Found %lu elems instead of %d\n", g_tmp0, RBTREE_NB_ELEMS);
		g_tmp0 = 0;
		printf("insertion took %fms -> %fus/elem\n",
			(float)(t1 - t0) / CLOCKS_PER_SEC * 1000,
			(float)(t1 - t0) / CLOCKS_PER_SEC * 1000 / RBTREE_NB_ELEMS * 1000);
		rb_freeall(&root);
	}
}

int main()
{
	srandom(time(NULL));
	test_rbtree();
	return 0;
}
