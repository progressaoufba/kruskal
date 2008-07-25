#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "bool.h"
#include "thalpha.h"

struct sheap{
	int tam; /*tamaÃ±o*/
	size_t tmax; /*tamaÃ±o maximo del arreglo*/
	thalpha * elems;
};

/**********************funciones adicionales***************/
int
hijo_izq(int p){ /*tiene que tener hijo*/
	return 2*p;
}

int
hijo_der(int p){/*tiene que tener hijo*/
	return 2*p+1;
}

int
padre (int h){/*no tiene q ser el de arriba de todos*/
	return (int) h/2;
}

bool
tiene_hijo (heap h, int p){
	if (p <= h->tam && p>=1)
		return (2*p<=h->tam);
	else
		return FALSE;
}

bool
tiene_padre(heap h, int p){
	return (p>1 && p <= h->tam);
}

int
hijo_menor (heap h, int p){
	if (tiene_hijo(h,p))
		if (hijo_der(p)<= h->tam && thalpha_menor(h->elems[hijo_der(p)],h->elems[hijo_izq(p)]))
			return hijo_der(p);
		else
			return hijo_izq(p);
	else
		/*ERROR:...*/
	
	return 0;
}
	

heap
subir (heap h, int q){
	int p;
	
	p=padre(q);
	thalpha_swap(h->elems,p,q);
	return h;
}

bool
debe_subir (heap h, int q){
	if (q>=1 && q<=h->tam)
		return thalpha_menor(h->elems[q],h->elems[padre(q)]);
	else
		return FALSE;
}

heap
flotar (heap h, int q){
	int p;
	p=q;
	while (tiene_padre(h,p) && debe_subir(h,p)){
		h=subir(h,p);
		p=padre(p);
	}
	return h;

}

heap
hundir(heap h,int q){
	int p;
	p=q;
	while(tiene_hijo(h,p) && debe_subir(h,hijo_menor(h,p))){
		p=hijo_menor(h,p);
		h=subir(h,p);
	}
	return h;
}
	
	
/*************************funciones propias del heap*******************************/

heap
heap_create(const size_t maxt){ 
	heap h;
	
	h=(heap)calloc(1,sizeof(struct sheap));
	if(h!=NULL){
		h->tam=0;
		h->tmax=maxt;
		h->elems=(thalpha*)calloc(maxt+1,sizeof(thalpha));
	}

	return h;
}	
	

heap
heap_insert(heap h, const thalpha a){
	if (h!=NULL)
	if (!heap_lleno(h)){
		h->tam=h->tam+1;
		h->elems[h->tam]=a;
		h=flotar(h,h->tam);
	}
	else
		printf("El heap esta lleno, ya no se puede agregar mas\n");
	
	return h;
}

thalpha
heap_first(const heap h){
	thalpha a;
	a=thalpha_clone(h->elems[1]);
	return a;
}

heap
heap_pop(heap h){
	/*vamos a reemplazar el primero por el ultimo y hacerlo hundir, ineficiente, 
	la forma eficiente de hacer esto seria con 2 enteros
	que me digan donde empieza y donde termina e ir moviendo esos numeros(punto *)*/
	if (!heap_vacio(h)){
		thalpha_destroy(h->elems[1]); /*evitamos el memory leak?*/
		h->elems[1]=h->elems[h->tam];
		h->tam=h->tam-1;
		h=hundir(h,1);
	}
	return h;
}
	

bool
heap_vacio(const heap h){
	return (h->tam==0);
}

bool
heap_lleno(const heap h){
	return (h->tmax<=h->tam);/*porque en heap_create hicimos un calloc (tmax+1...)*/
}


thalpha
heap_saca(heap h){
	thalpha a=NULL;
	if (!heap_vacio(h)){
		a = h->elems[h->tam];
		h->tam=h->tam-1;
	}
	return a;
}
	

heap
heap_destroy(heap h){
	 /*vamos a destruir todo el heap completo con todos los datos adentro*/
	int i=0;
	if (h!=NULL){
		for (i=1;i<=h->tam;i++)
			thalpha_destroy(h->elems[i]);
		free(h->elems);
		free(h);
	}
	return NULL;
}

