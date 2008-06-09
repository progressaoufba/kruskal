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
		s->elems=(stalpha *)calloc(maxt+1,sizeof(stalpha));
	}
	return s;
}

stack
stack_apilar(stack s,const stalpha a){
	s->tam=s->tam+1;
	s->elems[s->tam]=a;
	return s;
}


bool
stack_vacia (const stack s){
	return (s->tam<=0);
}




stalpha
stack_top(const stack s){
	stalpha a;
	a=stalpha_clone(s->elems[s->tam]); /*generamos memoria*/
	return a;
}

stack
stack_desapilar (stack s){
	if (!stack_vacia(s)){
		stalpha_destroy(s->elems[s->tam]);
		s->tam=s->tam-1;
	}
	return s;
}
	


stack
stack_destroy(stack s){
	while(!stack_vacia(s)){
		s=stack_desapilar(s);
	}
	free(s->elems);
	free(s);
	return NULL;
}
