#include <stdio.h>

#include "queue.h"

int main()
{
	/* */
	T a;
	int i;
	bool n = false;
	struct queue q;
	
	init_queue(&q);
	n = is_empty(&q);
	printf("\n%d\n", n);
	for(i=2; i<20; i++)
	{
		enter(&q, i);
	}
	a = front(&q);
	printf("\n%d\n", a);
	n = is_empty(&q);
	printf("\n%d\n", n);
	a = leave(&q);
	printf("\n%d\n", a);
	a = front(&q);
	printf("\n%d\n", a);
	return 0;
}
