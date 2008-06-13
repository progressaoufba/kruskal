#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "bool.h"

typedef int tufpos;
typedef int tufalpha; 
typedef int tufset;


typedef struct sunion_find *union_find;

union_find
uf_create(const tufpos max); /* constructor */

void
uf_add_singulete(union_find uf, const tufalpha el); /* agrega singulete */

tufset
uf_find(union_find uf, const tufalpha el); /* buzca conjunto a partir de un elemento que le pertenece */

void
uf_union(union_find uf, const tufset s1, const tufset s2);/* union de los conjuntos */

bool
uf_oneset(const union_find uf); /* hay solo un conjunto? */

union_find
uf_destroy(union_find uf); /* destructor */

#endif
