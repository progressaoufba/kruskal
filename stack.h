#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "bool.h"
#include "stalpha.h"

typedef struct sstack * stack;

stack
stack_create(const size_t maxt); /*constructor con maximo del tamaño */

stack
stack_push(stack s,const stalpha a);/*agregamos un elemento*/

bool
stack_empty(const stack s);

stalpha
stack_top(const stack s);/*devolvemos el de mas arriva*/
/*generamos memoria, tener en cuenta que hay q borrarla*/

stack
stack_pop (stack s);/*sacamos el de mas arriva*/

/*vamos a eliminar todos los elementos que contiene el stack y despues lo liberamos*/
stack
stack_destroy(stack s);/*destructor*/

#endif
