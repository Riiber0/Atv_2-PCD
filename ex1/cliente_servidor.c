#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define numT 2

int request = 0, respond = 0, soma = 0;

void* cliente(void* arg){
	int id = *((int*)arg);
	id++;

	while(soma < 20){
		while(respond != id) request = id;
		int local = soma;
		sleep(rand()%2);
		soma = local + 1;
		printf("cliente %d incrementou soma, valor atual: %d\n", id, soma);
		respond = 0;
	}

	pthread_exit(NULL);
}

void* server(void* arg){
	while(soma < 20){
		while (request = 0);
		respond = request;
		while (respond != 0); 
		request = 0;
	}

	pthread_exit(NULL);
}

int main(int argc, int argv){
	pthread_t t[numT], s;

	for(int i = 0; i < numT; i++){
		int* aux = (int*)malloc(sizeof(int));
		*aux = i;
		pthread_create(&t[i], NULL, cliente, aux);
	}
	pthread_create(&s, NULL, server, NULL);
	pthread_join(s, NULL);
	printf("soma final: %d\n",soma);
	return 0;
}
