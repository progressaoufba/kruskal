#include "stack.h"

typedef struct scelda * celda;

struct scelda {
	stalpha elem;
	struct scelda * tl;
};

struct sstack {
	int tam;
	celda cel;
};

stack
stack_create(const size_t maxt){
	stack s=NULL;
	
	s=(stack)calloc(1,sizeof(struct sstack));
	if (s!=NULL){
		s->tam=0;
		/*s->elems=(stalpha *)calloc(maxt+1,sizeof(stalpha));*/
		s->cel=NULL;/* = (celda)calloc(1,sizeof(struct scelda));
		if (s->cel!=NULL){
			s->cel->tl=NULL;
			
		}*/
			
	}
	return s;
}

stack
stack_push(stack s,const stalpha a){
	celda c;
	s->tam=s->tam+1;
	/*s->elems[s->tam]=a;*/
	c=(celda)calloc(1,sizeof(struct scelda));
	if (c!=NULL){
		c->elem=a;
		c->tl=s->cel;
		s->cel=c;
	}
		
	
	return s;
}


bool
stack_empty (const stack s){
	return (s->tam<=0);
}




stalpha
stack_top(const stack s){
	stalpha a;
	a=stalpha_clone(s->cel->elem); /*generamos memoria*/
	return a;
}

stack
stack_pop (stack s){
	celda aux;
	if (!stack_empty(s)){
		aux=s->cel;
		stalpha_destroy(s->cel->elem);
		s->cel=s->cel->tl;
		free (aux);
		s->tam=s->tam-1;
	}
	return s;
}
	


stack
stack_destroy(stack s){
	while(!stack_empty(s)){
		s=stack_pop(s);
	}
	/*free(s->cel);*/
	free(s);
	return NULL;
}
