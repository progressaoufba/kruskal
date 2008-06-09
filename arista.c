#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arista.h"

struct sarista {
	int v1;
	int v2;
	int weight;
};

arista 
arista_create (int v1, int v2, int weight) {
	arista e = NULL;
	e = (arista)calloc(1,sizeof(struct sarista));
	if (e!=NULL) {
		e->v1 = v1;
		e->v2 = v2;
		e->weight = weight;
	}
	return e;
}

int
arista_fst (arista e) {
	assert (e != NULL);
	return e->v1;
}

int
arista_snd (arista e) {
	assert (e != NULL);
	return e->v2;
}

int
arista_weight (arista e) {
	assert (e != NULL);
	return e->weight;
}

arista
arista_clone(arista e) {
	return arista_create(e->v1,e->v2,e->weight);
}

arista
arista_destroy(arista e) {
	free (e);
	return NULL;
}
