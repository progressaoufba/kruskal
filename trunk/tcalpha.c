#include <stdio.h>
#include "tcalpha.h"


alpha
alpha_clone (alpha a) {
	return arista_clone(a);
}

alpha
alpha_destroy (alpha a) {
	return arista_destroy(a);
}
