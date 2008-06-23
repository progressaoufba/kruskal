#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "colap.h"
#include "arista.h"
#include "union_find.h"
#include "cra.h"
#include "cintwar.h"
#include "err.h"

int main (void){

	cintrar cr;
	cintwar cw;
	colap cp;
	union_find ccv;
	tufset cv1,cv2;
	arista e;
	stack s1,s2;
	int cantAristas,cantVertices;
	
 /*********** construyo e inicializo todos los TAD’s ******************/
		
	cr = cra_create();	/*creamos la cinta de escritura*/
	cra_arr(cr);		/*la arrancamos*/
	
	cantAristas  = cra_acant(cr);
	cantVertices = cra_vcant(cr);
	cp  = colap_create(cantAristas);
	s1  = stack_create(cantAristas);
	s2  = stack_create(cantAristas);
	ccv = uf_create(cantVertices);
	cw = cwa_create();	/*inicializamos la cinta de escritura*/
	cwa_arr(cw);
	
/************* comenzamos con el algoritmo *********************/
	
	while (!cra_fin(cr)) {
		e  = cra_elec(cr);
		cp = colap_push(cp,e);
		uf_add_singulete(ccv,arista_fst(e));	/* hace nada */
		uf_add_singulete(ccv,arista_snd(e)); 	/* hace nada */
		cra_av(cr);
	}

	while (!uf_oneset(ccv) && !colap_empty(cp)) {
		e = colap_primero(cp); /*genera una arista*/
		colap_pop(cp);
		cv1 = uf_find(ccv,arista_fst(e));
		cv2 = uf_find(ccv,arista_snd(e));
		if (cv1 != cv2) {
			uf_union(ccv,cv1,cv2);
			s1 = stack_push(s1,e);
		}
		else
			s2 = stack_push(s2,e);
	}
	
	while (!stack_empty(s1)) {
		e = stack_top(s1);
		s1 = stack_pop(s1);		
		cwa_insarbol(cw,e);
		e = arista_destroy(e);
	}
	
	while (!stack_empty(s2)) {
		e = stack_top(s2);
		s2 = stack_pop(s2);
		cwa_ainsrest(cw,e);
		e = arista_destroy(e);
	}
	
	while (!colap_empty(cp)) {
		e = colap_saca(cp);
		if (e==NULL)
			warnx("EMPTY\n");
		cwa_ainsrest(cw,e);
		arista_destroy(e);
	}
	
	if (uf_cant_conj(ccv)>=2) 
		cwa_insmsg(cw,"//INFO: ????? componentes conexas.\n");
	/*si el grafo no es conexo, decimos la cant de comp. conexas*/
		
		
/************* Destruimos todos los TADs *********************/

	stack_destroy(s1);
	stack_destroy(s2);
	colap_destroy(cp);
	uf_destroy(ccv);
	cra_destroy(cr);
	cwa_destroy(cw);

	
	return 0;
}

