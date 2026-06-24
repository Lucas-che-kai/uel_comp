#include <stdio.h>
#include <stdlib.h>

//exercicio apenas focado para implementar a funcao reverso
typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemen;

typedef struct{
    elemen *inicio;
    elemen *fim;
}fila;

//funcao que inverte a fila
void reverso(fila *p){

    if (p == NULL || p->inicio == NULL || p->inicio == p->fim) {
        return;
    }

    elemen *anterior=NULL;
    elemen *atual=p->inicio;
    elemen *proximo=NULL;

    //guardar o inicio para futuramento o fim
    elemen *antigo_inicio = p->inicio;

    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    //redefinir o fim e o inicio
    p->fim=antigo_inicio;
    p->inicio=anterior;
}