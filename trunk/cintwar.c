#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "cintwar.h"
#include "bool.h"
#define  OUTFILE  stdout;



struct scintwar
 {
	FILE * f;
  	bool arr;
};

cintwar
cwa_create(void) {
	cintwar cwa;
	cwa = (cintwar)calloc(1,sizeof(struct scintwar));
	if (cwa!=NULL) {
		cwa->f   = OUTFILE;
		cwa->arr = FALSE;
	}
	return cwa;
}

void
cwa_arr(cintwar cwa) {
	if (cwa!=NULL)
		if (cwa->arr==FALSE) {
			cwa->arr = TRUE;
			fprintf(cwa->f,"graph G {\n");
		}
}

void
cwa_insarbol(cintwar cwa, arista a) { 
	int v1,v2,w;
	if (cwa==NULL)
		errx(1,"La cinta es nula");
	if (cwa->arr==FALSE)
		errx(1,"La cinta no esta arrancada");
	if (a!=NULL) {
	v1 = arista_fst(a);
	v2 = arista_snd(a);
	w  = arista_weight(a);
	fprintf(cwa->f,"  %d--%d [label=%d];\n",v1,v2,w);
	}
}

void
cwa_ainsrest(cintwar cwa, arista a) {
	int v1,v2,w;
	if (cwa==NULL)
		errx(1,"La cinta es nula");
	if (cwa->arr==FALSE)
		errx(1,"La cinta no esta arrancada");
	if (a!=NULL) {
	v1 = arista_fst(a);
	v2 = arista_snd(a);
	w  = arista_weight(a);
	fprintf(cwa->f,"  %d--%d [label=%d,style=dotted];\n",v1,v2,w);
	}
}

void
cwa_insmsg(cintwar cwa, char *msg ) {
	fprintf(cwa->f,msg);
}

cintwar
cwa_destroy(cintwar cwa) {
	if (cwa!=NULL) {
	fprintf (cwa->f,"}\n");
	free (cwa);
	}
	return NULL;
}

