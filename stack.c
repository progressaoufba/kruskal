#include "stack.h"

struct sstack {
	int tam;
	stalpha * elems;
};

stack
stack_create(const size_t maxt){
	stack s=NULL;
	s=(stack)calloc(1,sizeof(struct sstack));
	if (s!=NULL){
		s->tam=0;
		s->elems=(stalpha *)calloc(maxt,sizeof(stalpha));
	}
	return s;
}

stack
stack_push(stack s,const stalpha a){
	s->elems[s->tam]=a;
	s->tam++;
	return s;
}


bool
stack_empty (const stack s){
	return (s->tam<=0);
}




stalpha
stack_top(const stack s){
	stalpha a;
	a=stalpha_clone(s->elems[s->tam-1]); /*generamos memoria*/
	return a;
}

stack
stack_pop (stack s){
	if (!stack_empty(s)){
		stalpha_destroy(s->elems[s->tam]);
		s->tam=s->tam-1;
	}
	return s;
}
	


stack
stack_destroy(stack s){
	while(!stack_empty(s)){
		s=stack_pop(s);
	}
	free(s->elems);
	free(s);
	return NULL;
}
