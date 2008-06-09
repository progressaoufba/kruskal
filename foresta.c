#include "foresta.h"


union_find
uf_create(const tufpos max) {
	union_find uf;
	uf = (union_find)calloc(1,sizeof (struct sunion_find));
	uf->rep = ()calloc(max,sizeof int);
	