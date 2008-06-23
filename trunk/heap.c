#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "err.h"

struct sheap{
	int size;	/*tamaño*/
	int start;
	int end;
	int max_size;	/*tamaño maximo del arreglo*/
	thalpha * elems;
};

int
hijo_izq(heap h,int p);

int
hijo_der(heap h,int p);

int
padre(heap h,int p);

bool
tiene_padre(heap h, int p);

bool
tiene_hijo(heap h, int p);

int
hijo_menor(heap h, int p);

heap
subir (heap h, int q);

bool
debe_subir (heap h, int q);

heap
flotar (heap h, int q);

heap
hundir(heap h,int q);



/******************************funciones adicionales****************************/


int
hijo_izq(heap h, int p){ /*tiene que tener hijo*/
	int paux;
	if (p<=h->start){
		paux=2*p;
	}
	else{
		paux=h->start-p;
		paux=(2*paux+h->start)%h->max_size;
		
	}
	
	return paux;
}

int
hijo_der(heap h,int p){/*tiene que tener hijo*/
	int paux;
	if (p<=h->start){
		paux=2*p+1;
	}
	else{
		paux=h->start-p;
		paux=(2*paux+1+h->start)%h->max_size;
		
	}
	
	return paux;
}

int
padre(heap h,int p){/*no tiene q ser el de arriba de todos*/
	int paux;
	if (p< h->start){
		paux=p+(h->max_size - h->start);
		paux=(int) paux/2;
		paux=(h->start+paux)%h->max_size;
	}
	else{
		paux=p-h->start;
		paux=(int)paux/2;
		paux=paux+h->start;
	}
	
	return paux;
}

bool
tiene_hijo(heap h, int p){
	if (p <= h->size && p>=1)
		return (2*p<=h->size);
	else
		return FALSE;
}

bool
tiene_padre(heap h, int p){
	return (p!=h->start);
}

int
hijo_menor(heap h, int p){
	if (tiene_hijo(h,p))
		if (hijo_der(h,p)<= h->size && thalpha_menor(h->elems[hijo_der(h,p)],h->elems[hijo_izq(h,p)]))
			return hijo_der(h,p);
		else
			return hijo_izq(h,p);
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
	return (h->size >= h->max_size);/*porque en heap_create hicimos un calloc (tmax+1...)*/
}


heap
subir (heap h, int q){
	int p;
	
	p=padre(h,q);
	thalpha_swap(h->elems,p,q);
	return h;
}

bool
debe_subir (heap h, int q){
	if ((q>=h->start && q<= h->end) || ((q>=h->start && q<=h->max_size) || q<= h->end))
		return thalpha_menor(h->elems[q],h->elems[padre(h,q)]);
	else
		return FALSE;
}

heap
flotar (heap h, int q){
	int p;
	p=q;
	while (tiene_padre(h,p) && debe_subir(h,p)){
		h=subir(h,p);
		p=padre(h,p);
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
		h->start=1;
		h->end=0;
		h->max_size=maxt;
		h->elems=(thalpha*)calloc(maxt,sizeof(thalpha));
		
	}
	/*else
		ERROR:........*/
	
	return h;
}	
	

heap
heap_insert(heap h, const thalpha a){
	/*printf ("\n\nstart:%i\tend:%i\tsize:%i\n",h->start,h->end,h->size);*/
	if (!heap_lleno(h)){
		
		h->size=h->size+1;
		h->end=(h->end +1)%h->max_size;
		
		h->elems[h->end]=a;
		h=flotar(h,h->end);
	}
	else
		warnx("El heap esta lleno, ya no se puede agregar mas\n");/*ERROR....*/
	
	
	return h;
}

thalpha
heap_first(const heap h){
	thalpha a;
	
	a=thalpha_clone(h->elems[h->start]);
	return a;
}

heap
heap_pop(heap h){
	/*vamos a reemplazar el primero por el ultimo y hacerlo hundir, ineficiente, 
	la forma eficiente de hacer esto seria con 2 enteros
	que me digan donde empieza y donde termina e ir moviendo esos numeros(punto *)*/
	if (!heap_vacio(h)){
		
		/*h->elems[1]=*/thalpha_destroy(h->elems[h->start]); /*evitamos el memory leak?*/
		h->start=(h->start+1) % h->max_size;
		h->size=h->size-1;
		
	}
	return h;
}
	



thalpha
heap_saca(heap h){
	thalpha a=NULL;
	/*if (!heap_vacio(h)){
		a=thalpha_clone(h->elems[h->end]);
		thalpha_destroy(h->elems[h->end]);
		h->size=h->size-1;
		if (h->end == 1)
			h->end=h->max_size-1;
		else
			h->end=h->end-1;
		
	}*/
	a=heap_first(h);
	h=heap_pop(h);
	return a;
}
	

heap
heap_destroy(heap h){
	 /*vamos a destruir todo el heap completo con todos los datos adentro*/
	int i=0;
	if (h!=NULL){
		for (i=0;i<=h->size;i++)
			h=heap_pop(h);
		
		free(h->elems);
		free(h);
	}


	return NULL;
}

