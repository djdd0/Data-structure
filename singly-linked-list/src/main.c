#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	/* */
	T a;
	int i,n;
	struct singly_linked_list *l;
	l = create_list();
	for(i=0; i<20; i++)
	{
		l = insert(l, i, i+100);
	}
	l = delete_at(l, 2);
	n = size(l);
	printf("\n%d\n", n);
	a = get(l, 1);
	printf("\n%d\n", a);
	replace(l, 1, 55);
	n = index(l, 116);
	printf("\n%d\n", n);
	free(l);
	return 0;
}
