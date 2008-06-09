#ifndef ARISTA_H
#define ARISTA_H

typedef struct sarista *arista;

arista 
arista_create (int v1, int v2, int weight); /*Hace calloc (aporte de Cancu!!)*/

int
arista_fst (arista e);

int
arista_snd (arista e);

int
arista_weight (arista e);

arista
arista_clone(arista e); /*Hace calloc por que usa arista_create*/

arista
arista_destroy(arista e);


#endif
