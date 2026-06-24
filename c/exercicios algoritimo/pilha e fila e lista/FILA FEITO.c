#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemen;

typedef struct{
    elemen *inicio;
    elemen *fim;
}fila;

fila *initQueue(){
    fila *f=(fila *)malloc(sizeof(fila));
    //verificacao da fila
    if(f==NULL){
        printf("ERRO NA INICIALIZACAO DA FILA");
        exit(1);
    }

    f->fim=NULL;
    f->inicio=NULL;
    return f;
}

//funcao para add elemen na fila
void enQueue(fila *f, int valor){
    //verifica se existe fila
    if(f==NULL){
        printf("FILA NAO INICIADA! ");
        exit(1);
    }

    //aloca um novo elemento
    elemen *novo=(elemen *)malloc(sizeof(elemen));
    if(novo==NULL){
        printF("ERROR...NA CRIACAO DO NOVO NO");
        exit(1);
    }

    novo->valor=valor;
    novo->prox=NULL;
//verifica se a fila esta vazia
    if(f->fim==NULL){
        f->fim=novo;
        f->inicio=novo;
    }else{
        f->fim->prox=novo;
        f->fim=novo;
    }

}

//tirar o elemento da fila
int deenQueue(fila *f){

    //verica se ja existe a fila
    if(f==NULL){
        printf("A FILA AINDA NAO FOI INICIALIZADA");
        exit(1);
    }

    int a=f->inicio->valor;

    //remover o valor fo inicio da fila
    elemen *temp=f->inicio;
    f->inicio=temp->prox;
    free(temp);

    if(f->inicio==NULL){
        f->fim=NULL;
    }

    return a;
}

void printEnqueue(fila *f){
    //verifica se existe a fila
    if(f==NULL){
        printf("A FILA AINDA NAO FOI INICIALIZADA!");
        exit(1);
    }

    elemen *temp=f->inicio;//ponteiro para percorrer

    printf("\nFila:\n");
    while(temp!=NULL){
        printf("%d\t", temp->valor);
        temp=temp->prox;
    }
}


int freeQueue(fila *f){
    // 1: Verifica se a fila é NULL
    if(f == NULL){
        // Retorna -1 para indicar que a fila é inválida
        return -1; 
    }

    // 2: Inicia um ponteiro de Elem para percorrer a fila
    elemen *current = f->inicio;

    // 3: Percorre a fila enquanto o ponteiro atual não for NULL
    while(current != NULL){
        // Armazena o próximo elemento antes de liberar o atual
        elemen *temp = current;
        // Move o ponteiro para o próximo elemento
        current = current->prox;
        // Libera a memória do elemento atual
        free(temp);
    }

    // 4: Libera a memória da estrutura da fila
    free(f);
    return 0;
}
