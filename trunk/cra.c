#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cinta.h"
#include "cra.h"
#include "arista.h"

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
	cra=(cintrar)calloc(1,sizeof(struct scintrar));
	if (cra!=NULL) {
		cra->vcant = 0;
		cra->acant = 0;
		cra->c = cinta_create(aList_vacia());
		cra->arem = 0;
		cra->arr = FALSE;
	}
	return cra;
	
}

void
cra_arr(cintrar cra) { /* arrancar */
	int vcant,acant;
	fscanf (stdin,"# %d %d\n",&vcant, &acant);
	cra->vcant = vcant;
	cra->acant = acant;
	cra->arem = acant+1; /*el +1 es porque keremos que cra_fin signifique que no hay 					mas elementos para leer*/
	cra->arr = TRUE; 
	while (getchar()!='\n');
	cra_av(cra);
}

void
cra_av(cintrar cra) {
	if (cra_fin(cra)) 
		warnx("Error, Fin de cinta");
	if (!cra->arr) 
		warnx("Error, la cinta no esta arrancada");
	
	int v1,v2,weight;
	arista e;
	e = NULL;
	scanf("%d -- %d [label = %d];",&v1,&v2,&weight);
	e = arista_create(v1,v2,weight);	
	cinta_ins(cra->c,e);
	e = arista_destroy(e);
	cra->arem--;
}

arista
cra_elec(const cintrar cra) {
	if (!cra->arr) 
		warnx("Error, la cinta no esta arrancada");
	
	return cinta_elec(cra->c);
}

bool
cra_fin(const cintrar cra) {
	if (!cra->arr) 
		warnx("Error, la cinta no esta arrancada");
	
	return cra->arem==0;
}
	
int
cra_vcant(const cintrar cra) { /* devuelve la cantidad de vertices*/
	if (!cra->arr) 
		warnx("Error, la cinta no esta arrancada");
	
	return cra->vcant;
}

int
cra_acant(const cintrar cra) { /*devuelve la cantidad de aristas*/
	if (!cra->arr) 
		warnx("Error, la cinta no esta arrancada");
		
	return cra->acant;
}
	
cintrar
cra_destroy(cintrar cra) { /* destructor */
	cinta_arr(cra->c);
	while (!cinta_fin(cra->c))
		cinta_del(cra->c);

	cinta_destroy(cra->c);
	free(cra);
	cra = NULL;
	return cra;
}
