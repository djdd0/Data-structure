#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
	/* */
	T a;
	int i;
	bool n = false;
	struct stack *s;
	s = create_stack();
	n = is_empty(s);
	printf("\n%d\n", n);
	for(i=0; i<20; i++)
	{
		s = push(s, i);
	}
	a = top(s);
	printf("\n%d\n", a);
	n = is_empty(s);
	printf("\n%d\n", n);
	a = pop(s);
	printf("\n%d\n", a);
	a = top(s);
	printf("\n%d\n", a);
	free(s);
	return 0;
}
