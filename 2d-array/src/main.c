#include <stdio.h>

#include "array.h"

int main()
{
	int n=0;
	struct array a;
	init_array(&a, 50, 30);

	n = get_rows(&a);
	printf("%d\n", n);
	n = get_cols(&a);
	printf("%d\n", n);

	for(int i = 0; i<50; i++) {
		for(int j = 0; j<30; j++) {
			set(&a, i, j, i*50+j);
		}
	}

	n = get(&a, 0, 0);
	printf("%d\n", n);

	n = get(&a, 3, 2);
	printf("%d\n", n);
	n = get(&a, 3, 1);
	printf("%d\n", n);
	n = get(&a, 3, 0);
	printf("%d\n", n);

	uninit_array(&a);

	return 0;
}
