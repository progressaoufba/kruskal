#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cinta.h"
#include "cra.h"


struct scintrar {
	int vcant;
	int acant;
	cinta c;
	int arem;
	bool arr;
};

cintrar
cra_create(void) { /* constructor */
	cintrar cra;
	cra->vcant = 0;
	cra->acant = 0;
	cra->c = cinta_create(aList_vacia());
	cra->arem = 0;
	cra->arr = FALSE;
	return cra;
	
}

void
cra_arr(cintrar cra) { /* arrancar */
	int vcant,acant;
	if (cra != NULL) {
		fscanf (stdin,"# %d %d",&vcant, &acant);
		cra->vcant = vcant;
		cra->acant = acant;
		cra->arem = acant;
		cra->arr = TRUE; 
		while (getchar() !='\n');
		cra_av(cra);
	}
}	

void
cra_av(cintrar cra) {
	assert (cra->arr==TRUE);
	assert (!cra_fin(cra));
	
	int v1,v2,weight;
	arista e;
	e = NULL;
	scanf("%d -- %d [label = %d];",&v1,&v2,&weight);
	e = arista_create(v1,v2,weight);	
	cinta_ins(cra->c,e);
	arista_destroy(e);
	cra->arem--;
}

arista
cra_elec(const cintrar cra) {
	assert (cra->arr==TRUE);
	
	return cinta_elec(cra->c);
}

bool
cra_fin(const cintrar cra) {
	assert (cra->arr==TRUE);
	
	return cra->arem==0;
}
	
int
cra_vcant(const cintrar cra) { /* devuelve la cantidad de vertices*/
	assert (cra->arr==TRUE);
	
	return cra->vcant;
}

int
cra_acant(const cintrar cra) { /*devuelve la cantidad de aristas*/
	assert (cra->arr==TRUE);
	
	return cra->acant;
}
	
cintrar
cra_destroy(cintrar cra) { /* destructor */
	free(cra);
	cra = NULL;
	return cra;
}
