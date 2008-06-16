#ifndef THAPLHA_H
#define THAPLHA_H

#include <stdlib.h>
#include "arista.h"
#include "bool.h"

typedef arista thalpha;

thalpha
thalpha_clone (thalpha a);

thalpha
thalpha_destroy (thalpha a);

bool 
thalpha_menor(thalpha a,thalpha b);

void
thalpha_swap(thalpha *x,int a, int b);


#endif
