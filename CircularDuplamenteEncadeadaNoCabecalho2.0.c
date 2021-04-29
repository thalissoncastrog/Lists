#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo *ant;         // Anterior
	struct nodo *prox;	      // Proximo
}NODO;

typedef NODO *LISTA_CIR_DUP_ENC_NC;

void cria_lista(LISTA_CIR_DUP_ENC_NC *);
int eh_vazia(LISTA_CIR_DUP_ENC_NC);
int tam(LISTA_CIR_DUP_ENC_NC);
void ins(LISTA_CIR_DUP_ENC_NC, int, int);   // Implementação que ocorre mudanças em comparação a listas anteriores deste assunto.
int recup(LISTA_CIR_DUP_ENC_NC, int);       // Implementação que ocorre mudanças em comparação a listas anteriores deste assunto.
void ret(LISTA_CIR_DUP_ENC_NC, int);        // Implementação que ocorre mudanças em comparação a listas anteriores deste assunto.
void destruir(LISTA_CIR_DUP_ENC_NC);
void inverter_lista(LISTA_CIR_DUP_ENC_NC);

int main()
{
    LISTA_CIR_DUP_ENC_NC LISTA;

    cria_lista(&LISTA);

    ins(LISTA, 10, 1);

    return 0;
}

void cria_lista(LISTA_CIR_DUP_ENC_NC *pl){
	*pl = (LISTA_CIR_DUP_ENC_NC) malloc (sizeof(NODO));
	if(!(*pl)){
		printf("\nERRO! Memória insuficiente!\n");
		exit(1);
	}
	(*pl)->inf=0;
	(*pl)->ant=(*pl)->prox=*pl;
}

int eh_vazia(LISTA_CIR_DUP_ENC_NC l){
	return(l->inf==0);
}

int tam(LISTA_CIR_DUP_ENC_NC l){
	return(l->inf);
}

void ins(LISTA_CIR_DUP_ENC_NC l, int v, int k){
	LISTA_CIR_DUP_ENC_NC aux, novo;

	if(k < 1 || k > l->inf+1){
		printf("\nERRO! Posição inválida para inserção.\n");
		exit(2);
	}

	novo = (LISTA_CIR_DUP_ENC_NC)malloc (sizeof(NODO));
	if(!novo){
		printf("\nERRO! Memória insuficiente!\n");
		exit(3);
	}

	novo->inf = v;
		novo->inf = v;
    if(k<=(l->inf)/2){
    	for(aux=l; k>1; aux=aux->prox, k--);
    	novo->prox = aux->prox;
    	novo->ant = aux;
    	aux->prox = novo;
    	novo->prox->ant = novo;
    }else{
    	for(aux=l; k<=l->inf; aux=aux->ant, k++);
    	novo->ant = aux->ant;
    	novo->prox = aux;
    	aux->ant = novo;
    	novo->ant->prox = novo;
	}
	l->inf++;
}

int recup(LISTA_CIR_DUP_ENC_NC l, int k){
	int tamanho = l->inf;
	if(k < 1 || k > tamanho){
		printf("\nERRO! Consulta invalida.");
		exit(4);
	}
	if(k <= tamanho/2)
		for(; k>0; k--)
			l=l->prox;
	else
		for(; k<=tamanho; k++)
			l = l->ant;
	return (l->inf);
}

void ret(LISTA_CIR_DUP_ENC_NC l, int k){
	int tamanho = l->inf;

	if(k < 1 || k > tamanho){
	printf("\nERRO! Posição inválida para inserção.\n");
	exit(5);
	}

	l->inf--;
	if(k<=(l->inf)/2)
		for(; k>0; k--, l=l->prox);
	else
		for(; k<=tamanho; k++, l=l->ant);
	l->ant->prox = l->prox;
	l->prox->ant = l->ant;
	free(l);
}

void destruir(LISTA_CIR_DUP_ENC_NC l){
	LISTA_CIR_DUP_ENC_NC aux;
	int tam = l->inf;

	do{
		aux = l;
		l = l->prox;
		free(aux);
	}while (tam--);
}

void inverter_lista(LISTA_CIR_DUP_ENC_NC l){
	int i=tam(l);

	if(i>1){
		NODO *aux;
		for(i++; i; l=l->ant, i--){
			aux = l->ant;
			l->ant = l->prox;
			l->prox = aux;
		}
	}
}
