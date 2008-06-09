#include <stdio.h>
#include "cra.h"

int main (void) {
	cintar_t cra = NULL;
	arista_t e = NULL;
	int n1,n2,peso;
	
	cra = cra_create();
	cra_arr(cra);
	while (!cra_fin(cra)) {
		e=arista_create();
		e=cra_elec(cra);
		cra_av(cra);
		n1 = arista_fst(e);
		n2 = arista_snd(e);
		peso = arista_peso(e);
		printf("%d -- %d [label = %d];\n",n1,n2,peso);
		arista_destroy(e);
	}
	return 0;
}
