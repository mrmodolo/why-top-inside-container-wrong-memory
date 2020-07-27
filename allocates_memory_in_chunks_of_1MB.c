#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEGABYTE (1 << 20)
#define ALLOCATIONS 20


/**
 * alloc - a "leaky" program that just allocated
 *         a predefined amount of memory and then
 *         exits.
 */
int
main(/*int argc, char** argv*/)
{
	printf("allocating: %dMB\n", ALLOCATIONS);


	void* p;
	int   i = ALLOCATIONS;


	while (i-- > 0) {
		// Allocate 1MB (not initializing it
		// though).
		p = malloc(MEGABYTE);
		if (p == NULL) {
			perror("malloc");
			return 1;
		}

		// Explicitly initialize the area that
		// has been allocated.
		memset(p, 65, MEGABYTE);

		printf("remaining\t%d\n", i);
	}
}
