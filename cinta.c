#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cinta.h"
#include <err.h>


struct celda {
	tcalpha el;
	struct celda * tl;
};

struct scinta {
	struct celda cd;
	aList ppd;
	bool arr;
};


aList 
aList_vacia(void) {
	return NULL;
}

cinta 
cinta_create(aList l) {
	cinta c;
	c=(cinta)calloc(1,sizeof(struct scinta));
	if (c!=NULL){
		(c->cd).tl=l;		
		(c->cd).el=NULL;
		c->arr=FALSE;
	}
	return c;
}

void 
cinta_arr(cinta c) {
	c->ppd=&(c->cd);
	c->arr=TRUE;
}

bool 
cinta_fin(cinta c) {
	if (!c->arr)
		warnx("Error, la cinta no esta arrancada");
		return (c->ppd->tl == NULL);
}

void 
cinta_av(cinta c) {
	if (!c->arr)
		warnx("Error, la cinta no esta arrancada");
	if (cinta_fin(c))
		warnx("Error, esta en fin de cinta");
	else
		c->ppd=c->ppd->tl;
}

tcalpha 
cinta_elec(cinta c) {
	if (!c->arr)
		warnx("Error, la cinta no esta arrancada");
	if (cinta_fin(c)) return NULL;
	return c->ppd->tl->el;
}

void 
cinta_ins(cinta c, tcalpha a) {
	aList cel;
	cel=(aList)calloc(1,sizeof(struct celda));
	if (cel!=NULL) {
		if (c->arr==FALSE)
			cinta_arr(c);
		cel->el=tcalpha_clone(a);
		cel->tl = c->ppd->tl;
		c->ppd->tl=cel;		
	}
	
}

void 
cinta_del(cinta c) {
	aList aux;
	if (!c->arr)
		warnx("Error, la cinta no esta arrancada");
	aux = c->ppd->tl->tl;
	c->ppd->tl->el = tcalpha_destroy(c->ppd->tl->el);
	free (c->ppd->tl);
	c->ppd->tl=aux;
}

aList 
cinta_destroy(cinta c){
	aList aux;
	aux = (c->cd).tl;
	free(c);
	return aux;
}






