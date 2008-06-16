#include <stdio.h>
#include <stdlib.h>
#include "arista.h"
#include "stack.h"


int main (void){
	
	arista e;
	stack s;
	int i=0;
	
	s=stack_create(30);
	
	while (i<20){
		e=arista_create(1,10,i);
		stack_apilar(s,e);
		printf("%i\n",arista_weight(e));
		i++;
	}
	printf ("\n\nahora mostramos los tops\n");
	i=0;
	
	while (i<20){
		e=stack_top(s);
		printf("%i\n",arista_weight(e));
		s=stack_desapilar(s);
		i++;
	}
	
	
	
	return 0;
}

