#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "colap.h"
#include "arista.h"
#include "union_find.h"
#include "cra.h"
#include "cintwar.h"


int main (void){
/*	Var cp : cola_prioridad; ccv : conjunto_de_conjuntos_de_vertices
     cr : cinta_lectura_arista; cw : cinta_escritura_arista
     s1, s2 : stack; e : arista
     
.*/
	cintrar cr;
	cintwar cw;
	colap cp;
	union_find ccv;
	union_find cv1,cv2;
.	arista e;
	stack s1,s2;
.	int cantAristas,cantVertices;
	
 /*********** construyo e inicializo todos los TAD’s ******************/
		
	cr=cra_create();/*creamos la cinta de escritura*/
	cra_arr(cr); /*la arrancamos*/
	
	cantAristas=cra_acant(cr) +1;
	cantVertices=cra_vcant(cr)+1;
	
	cp=colap_create(cantAristas); /*creamos la colap con cantaristas+1*/
	s1=stack_create(cantAristas+1);/*por las dudas tambien lo mismo para las stacks*/
	s2=stack_create(cantAristas+1);
	
	ccv=uf_create(cantVertices);/*inicializamos el conj de conj de vertices con la cantidad de vertices*/
	
	cw=cwa_create();/*inicializamos la cinta de escritura*/
	cwa_arr(cw);
	
/************* comenzamos con el algoritmo *********************/
	/*tenemos que tener en cuenta varias cosas como por ejemplo la arista e que estamos usando que no produzca memorys  
	leaks*/
	
	/*do ¬esﬁn(cr) →
	e := elecorr(cr)
	cp := encolo(cp, e)
	ccv := agrego_singulete(ccv, vertice1(e)); ccv := agrego_singulete(ccv, vertice2(e))
	avanzo(cr)
	od*/
	
	while (!cra_fin(cr)){
		e=cra_elec(cr);
		cp=colap_encolar(cp,e);
		uf_add_singulete(ccv,arista_fst(e)); /*no sirve de nada....*/
		uf_add_singulete(arista_snd(e)); /*no sirve de nada*/
.		cra_av(cr);
	}
	

/*do cantidad_conjuntos(ccv) > 1 ∧ ¬vacia(cp) →
  e := primero(cp); cp := saco_primero(cp)
  cv1 := busco_conjunto(ccv, vertice1(e)); cv2 := busco_conjunto(ccv, vertice2(e))
  if cv1 = cv2 →
     ccv := union(ccv, cv1, cv2)
     s1 := push(s1, e)
      cv1 = cv2 →
     s2 := push(s2, e)
  ﬁ
od*/
	while (!uf_oneset(ccv) && !colap_vacia(cp)){
		e=colap_primero(cp);
		

			do ¬vacia(s1) →
  e := top(s1); s1 := pop(s1)
  escribo_arbol_min(cw, e)
  e := destruyo(e)
od
do ¬vacia(s2) →
  e := top(s2); s2 := pop(s2)
  escribo_grafo_restante(cw, e)
  e := destruyo(e)
od
do ¬vacia(cp) →
  (e, cp) := saco_cualquiera(cp)
  escribo_grafo_restante(cw, e)
  e := destruyo(e)
od
.
.
.
destruyo todos los TAD’s
.
.
.
