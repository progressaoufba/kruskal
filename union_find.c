#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef tufset *ptufset;

struct sunion_find {
	tufset *rep;
	int max_size;
	int cant_conj;
};

bool
es_rep(const union_find uf, const tufpos el);  /* funcion auxiliar */

tufpos
rep_find(const union_find uf, const tufpos el);/* funcion auxiliar */

/********************************************************************************************/
union_find
uf_create(const tufpos max) {
	int i;
	union_find uf;
	uf = (union_find)calloc(1,sizeof(struct sunion_find));
	if (uf!=NULL) {
		uf->rep = (ptufset)calloc(max+1,sizeof(tufset));
		if (uf->rep!=NULL)
			for (i=1;i<=max;i++)
				uf->rep[i] = -1;
		uf->max_size = max;
		uf->cant_conj = max;
	}
	return uf;
}

void
uf_add_singulete(union_find uf, const tufalpha el) {}

tufset
uf_find(union_find uf, const tufalpha el) {
	tufpos r,k;
	tufset j;

	if (uf!=NULL)
		if (uf->rep!=NULL) {
			r = el;
			k = el;
			while (!es_rep(uf,r))
				r = uf->rep[r];
				
			while (!es_rep(uf,k)) {
				j = uf->rep[k];
				uf->rep[k] = r;
				k = j;
			}
		}
	return r;
}

void
uf_union(union_find uf, const tufset s1, const tufset s2) {
	if (!es_rep(uf,s1) || !es_rep(uf,s2))
		errx(1,"Error, los argumentos de uf_union no son representantes!.\n");
	else {
		if (uf->rep[s1] < uf->rep[s2]) {
			uf->rep[s1] += uf->rep[s2];
			uf->rep[s2]  = s1;
		}
		else {
			uf->rep[s2] += uf->rep[s1];
			uf->rep[s1]  = s2;	
		}
		uf->cant_conj--;
	}
}

bool
uf_oneset(const union_find uf) {
	return (uf->cant_conj==1);
}

int
uf_cant_conj(union_find uf) {
	return uf->cant_conj;
}

union_find
uf_destroy(union_find uf) {
	free (uf->rep);
	free (uf);
	return NULL;
}

/******************Funciones Auxiliares**************************/	
bool
es_rep(const union_find uf, const tufpos el) { 
	return uf->rep[el]<0;
}

tufpos
rep_find(const union_find uf, const tufpos el) {
	tufpos r = el;
	while (!es_rep(uf,r))
		r = uf->rep[r];
	return r;
}

