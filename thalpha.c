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
	return 
