#include <stdio.h>
#include <stdlib.h>
#include "arista.h"
#include "colap.h"


int main (void){
	colap cp;
	arista e;
	
	int i=0;
	
	cp=colap_create(30);
	
	while (i<20){
		e=arista_create(1,10,i);
		colap_encolar(cp,e);
		printf("%i\n",arista_weight(e));
		i++;
	}
	printf ("\n\nahora mostramos los tops\n");
	i=0;
	
	while (i<20){
		e=colap_primero(cp);
		printf("%i\n",arista_weight(e));
		e=arista_destroy(e);
		colap_pop(cp);
		i++;
	}
	
	cp=colap_destroy(cp);
	
	return 0;
}

