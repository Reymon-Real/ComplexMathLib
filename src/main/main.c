#include <stdio.h>
#include <stdlib.h>
#include <funcs.h>

int main(void) {
	complejo_t a = init_complejo(1, 1);
	complejo_t b = init_complejo(1, -10);
	complejo_t c = suma_complejos(a, b);
	printf_complejo(c);
	return EXIT_SUCCESS;
}