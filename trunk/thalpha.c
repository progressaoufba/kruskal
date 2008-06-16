#include "thalpha.h"

thalpha
thalpha_clone (thalpha a) {
	return arista_clone(a);
}

thalpha
thalpha_destroy (thalpha a) {
	return arista_destroy(a);
}

bool 
thalpha_menor(thalpha a,thalpha b) {
	return (arista_weight(a)<arista_weight(b));
}

void
thalpha_swap(thalpha *x,int a, int b){
	arista e;
	
	e=arista_clone(x[a]);
	arista_destroy(x[a]);
	x[a]=x[b];
	x[b]=e;
}
	
