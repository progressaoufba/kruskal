#ifndef HEAP_H
#define HEAP_H
#include <stdlib.h>
#include "bool.h"
#include "thalpha.h"


/*debemos definir :
		  bool thalpha_menor(thalpha a,thalpha b); return a<b;
		  void thalpha_swap(thalpha *x,int a, int b);
		  thalpha thalpha_clone(thalpha a);
		  void thalpha_destroy (thalpha a);
		  */
typedef struct sheap * heap;

heap
heap_create(const size_t tam); /* constructor */

heap
heap_insert(heap h, const thalpha a); /* encolar */

thalpha
heap_first(const heap h); /* primero en la cola */
/*tener en cuenta que hay que llamarlo solo si no es vacio
  ademas GENERA MEMORIA, thalpha_clone*/

heap
heap_pop(heap h); /* saca primero osea el maximo */

bool
heap_vacio(const heap h); /* cola vacia? */

bool
heap_lleno(const heap h); /* cola llena? */

/*tener en cuenta que GENERA MEMORIA, hacerle free al thalpha*/
thalpha
heap_saca(heap h); /* saca y obtiene cualquier elemento, en este caso el ultimo
		      esto es mas eficiente*/


/*vamos a destruir todo el heap completo con todos los datos adentro
  tener cuidado, porque al borrar cada thalpha despues no vamos a poder
  acceder nunca mas a esos datos*/
heap
heap_destroy(heap h); /* destructor*/ 


#endif
