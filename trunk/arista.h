#ifndef ARISTA_H
#define ARISTA_H

typedef struct sarista *arista;

arista 
arista_create (int v1, int v2, int weight);

int
arista_fst (arista e);

int
arista_snd (arista e);

int
arista_weight (arista e);

arista
arista_clone(arista e);

arista
arista_destroy(arista e);


#endif
