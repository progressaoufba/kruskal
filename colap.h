#ifndef COLAP_H
#define COLAP_H
#include "bool.h"
#include "heap.h"
#include "tcpalpha.h"
#include "tcppos.h"
#include "tcpprior.h"

typedef heap colap;

/* como implementamos colap con un heap, los tipos parametricos deben coincidir, osea:
					-tcpalpha = thalpha
					-tcppos   = size_t (int)		*/

colap
colap_create(const tcppos max); /* constructor */

colap
colap_push(colap c, const tcpalpha elem); /* encolar */

tcpalpha
colap_primero(const colap c); /* primero en la cola */

void
colap_pop(colap c); /* saca primero */

bool
colap_empty(const colap c); /* cola vacia? */

bool
colap_full(const colap c); /* cola llena? */

tcpalpha
colap_saca(colap c); /* sacar y obtiene cualquier elemento */

colap
colap_destroy(colap c); /* destructor */

#endif
