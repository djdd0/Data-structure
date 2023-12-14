#include <stdio.h>
#include <malloc.h>
#include "list.h"

int main()
{
	/* */
	T a;
	int i,n;
	struct list *l;
	l = create_list();
	for(i=0; i<5; i++)
	{
		l = insert(l, i, 'A'+i);
	}
	l = delete_at(l, 2);
	n = size(l);
	printf("\n%d\n", n);
	a = get(l, 1);
	printf("\n%c\n", a);
	replace(l, 1, 'H');
	n = index(l, 'D');
	printf("\n%d\n", n);
	free(l);
	return 0;
}
