#include <stdio.h>
#include <stdlib.h>

//criar a pilha
typedef struct elemento{
    int valor;
    struct elemento *prox;
}ELEMEN;

typedef struct{
    ELEMEN *topo;
}PILHA;

//funcao para inicializar a pilha
PILHA* initstack(){
    PILHA *p=(PILHA *)malloc(sizeof(PILHA));

    if(p==NULL){
        printf("erro na inicialização da pilha");
        return NULL;
    }

    p->topo=NULL;
    return p;
}

//funcao para inserir um elemento
int push(PILHA *p, int valor){
    //verificar se foi inicializado
    if(p==NULL){
        printf("PILHA NAO INICIALIZADA");
        exit(1);
    }

    //alocar um novo elemento
    ELEMEN *novo=(ELEMEN *)malloc(sizeof(ELEMEN));
    if(novo==NULL){
        printf("ERRO NA CRIACAO DE UM NOVO ELEMENTO");
        exit(1);
    }

    //inserir
    novo->valor=valor;
    novo->prox=p->topo;
    p->topo=novo;
    return 0;
}

//funcao para tirar elemento
int pop(PILHA *p){

    //verificar se a pilha existe
    if(p==NULL){
        printf("A PILHA AINDA NAO EXISTE!");
        exit(1);
    }
//um ponteiro de struct para pegar o endereco do topo, isto é para nao perder o ender para guardar o valor
    ELEMEN *temp= p->topo;
// o topo recebe o valor prox
    p->topo=temp->prox;
//guarda o valor removido
    int a= temp->valor;
    return a;
}

//funcao para exibir
int printStack(PILHA *p){
    // vericar se a pilha existe
    if(p==NULL){
        printf("NAO EXISTE A PILHA !");
        exit(1);
    }

    //um ponteiro de struct para percorrer a pilha
    ELEMEN *atual=p->topo;
    
    printf("PILHA:");
    //percorrer ate o null
    while( atual!=NULL){
        printf("\t%d\t", atual->valor);
        atual=atual->prox;
    }
    printf("\n");
    return 0;
}

//funcao para contar quantidade de elementos
int contadorStack(PILHA *p){
    //verificar se a pilha existe
    if(p==NULL){
        printf("PILHA NAO EXISTE!");
        exit(1);
    }

    //inicializar um contador e um ponteiro de struct
    int cont=0;
    ELEMEN *temp=p->topo;

    // percorrer
    while(temp!=NULL){
        cont++;
        temp=temp->prox;
    }

    return cont;
}

//funcao para reinicializar a pilha
int freeStack(PILHA *p){
    //verifica se a pilha existe
    if(p==NULL){
        printf("NAO EXISTE A PILHA!");
        exit(1);
    }

    //temp
    ELEMEN *atual=p->topo;

    while(atual!=NULL){
        ELEMEN *temp=atual;
        atual=atual->prox;
        free(temp);//LIBERAR OS NÓS

    }
    //LIBERAR A PILHA
    free(p);
    return 0;
}
