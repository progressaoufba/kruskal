#ifndef HEAP_H
#define HEAP_H

#include "halpha.h"



/*debemos definir :
		  bool halpha_menor(halpha a,halpha b); return a<b;
		  void halpha_swap(halpha *x,int a, int b);
		  halpha halpha_clone(halpha a);
		  void halpha_destroy (halpha a);
		  */
typedef struct sheap * heap;

heap
heap_create(const size_t tam); /*constructor, tam=tamaño del arreglo, hay q hacerlo mas general
			 . usar otro tipo en vez de size_t*/

heap
heap_insert(heap h, const halpha a); /* encolar */

/*tener en cuenta que hay que llamarlo solo si no es vacio
  ademas GENERA MEMORIA, halpha_clone*/
halpha
heap_first(const heap h); /* primero en la cola */

heap
heap_pop(heap h); /* saca primero osea el maximo */

bool
heap_vacio(const heap h); /* cola vacia? */

bool
heap_lleno(const heap h); /* cola llena? */

/*tener en cuenta que GENERA MEMORIA, hacerle free al halpha*/
halpha
heap_saca(heap h); /* saca y obtiene cualquier elemento, en este caso el ultimo
		      esto es mas eficiente*/


/*vamos a destruir todo el heap completo con todos los datos adentro
  tener cuidado, porque al borrar cada halpha despues no vamos a poder
  acceder nunca mas a esos datos*/
heap
heap_destroy(heap h); /* destructor*/ 


#endif
