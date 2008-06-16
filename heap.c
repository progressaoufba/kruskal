#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct sheap{
	int size;	/*tamaño*/
	int max_size;	/*tamaño maximo del arreglo*/
	thalpha * elems;
};

/******************************funciones adicionales****************************/

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
	if (p <= h->size && p>=1)
		return (2*p<=h->size);
	else
		return FALSE;
}

bool
tiene_padre(heap h, int p){
	return (p>1 && p <= h->size);
}

int
hijo_menor (heap h, int p){
	if (tiene_hijo(h,p))
		if (hijo_der(p)<= h->size && thalpha_menor(h->elems[hijo_der(p)],h->elems[hijo_izq(p)]))
			return hijo_der(p);
		else
			return hijo_izq(p);
	else
		/*ERROR:...*/
	
	return 0;
}
	
	
bool
heap_vacio(const heap h){
	return (h->size==0);
}

bool
heap_lleno(const heap h){
	return (h->size>=h->max_size);/*porque en heap_create hicimos un calloc (tmax+1...)*/
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
	if (q>=1 && q<=h->size)
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
	
/**********************************************************************/

heap
heap_create(const size_t maxt){ 
	heap h;
	
	h=(heap)calloc(1,sizeof(struct sheap));
	if(h!=NULL){
		h->size=0;
		h->max_size=maxt;
		h->elems=(thalpha*)calloc(maxt+1,sizeof(thalpha));
	}
	/*else
		ERROR:........*/
	
	return h;
}	
	

heap
heap_insert(heap h, const thalpha a){
	if (!heap_lleno(h)){
		h->size=h->size+1;
		h->elems[h->size]=a;
		h=flotar(h,h->size);
	}
	else
		printf("El heap esta lleno, ya no se puede agregar mas\n");/*ERROR....*/
	
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
		/*h->elems[1]=*/thalpha_destroy(h->elems[1]); /*evitamos el memory leak?*/
		h->elems[1]=h->elems[h->size];
		h->size=h->size-1;
		h=hundir(h,1);
	}
	return h;
}
	



thalpha
heap_saca(heap h){
	thalpha a=NULL;
	if (!heap_vacio(h)){
		a=thalpha_clone(h->elems[h->size]);
		/*h->elems[h->size]=*/thalpha_destroy(h->elems[h->size]);
		h->size=h->size-1;
	}
	return a;
}
	

heap
heap_destroy(heap h){
	 /*vamos a destruir todo el heap completo con todos los datos adentro*/
	int i=0;
	if (h!=NULL){
		for (i=0;i<=h->size;i++)
			thalpha_destroy(h->elems[i]);
		free(h->elems);
		free(h);
	}
	return NULL;
}

