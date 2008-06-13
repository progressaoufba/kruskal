#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "bool.h"
#include "stalpha.h"

typedef struct sstack * stack;

stack
stack_create(const size_t maxt); /*constructor con maximo del tamaño */

stack
stack_apilar(stack s,const stalpha a);/*agregamos un elemento*/


bool
stack_vacia (const stack s);


/*generamos memoria, tener en cuenta que hay q borrarla*/
stalpha
stack_top(const stack s);/*devolvemos el de mas arriva*/

stack
stack_desapilar (stack s);/*sacamos el de mas arriva*/

/*vamos a eliminar todos los elementos que contiene el stack y despues lo liberamos*/
stack
stack_destroy(stack s);/*destructor*/

#endif
