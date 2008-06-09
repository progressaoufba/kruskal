#include "foresta.h"
#include <err.h>

struct sunion_find {
	tufset *rep;
	int max_size;
};

union_find
uf_create(const tufpos max) {
	union_find uf;
	uf = (union_find)calloc(1,sizeof(struct sunion_find));
	if (uf!=NULL) {
		uf->rep = (tufset)calloc((size_t)max,sizeof tufset);
		if (uf->rep!=NULL) {
			for (i=0,i<=max_size,i++)
				uf->rep[i] = -1;
			uf->max_size = max;
		}
	}
}

void
uf_add_singulete(union_find uf, const tufalpha el) {}

tufset
uf_find(union_find uf, const tufalpha el) {
	tufpos aux;
	aux = el;
	if (uf==NULL)
		errx (ENOMEM,"no hay memoria")
		if (uf->rep!=NULL)
			if (uf->rep[aux]>=0)
				aux = rep[aux];
	return aux;
		
		
		