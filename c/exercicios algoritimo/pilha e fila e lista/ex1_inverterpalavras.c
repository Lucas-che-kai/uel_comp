#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    char letra;
    struct elemento *prox;
}elemen;

typedef struct{
    elemen *topo;
} pilha;

pilha *initstack(){
    pilha *p=(pilha *)malloc(sizeof(pilha));
    if(p==NULL){
        printf("ERRO NA CRIACAO DA PILHA!");
        exit(1);
    }    

    p->topo=NULL;
    return p;
}

void push(pilha *p, char c){
    
    //verificar se existe a pilha 
    if(p==NULL){
        printf("ERROR....NAO EXISTE A PILHA!");
        exit(1);
    }

    elemen *novo=(elemen *)malloc(sizeof(elemen));
    if(novo==NULL){
        printf("ERRO NA CRIACAO DE UM NOVO ELEMENTO");
        exit(1);
    }
    novo->prox =  p->topo;
    p->topo = novo;
    novo->letra=c;
}

void pop(pilha *p){

    //verificar se existe 
    if(p==NULL){
        printf("NAO EXISTE A PILHA..ERROR!");
        exit(1);
    }

    if(p->topo == NULL)
    return;

    //ponteiro temporal
    elemen *temp=p->topo;

    p->topo=temp->prox;
    // nao retornei um char porque nao preciso do valor
    free(temp);
}

void freeStack(pilha *p){
    //verifica se a pilha existe
    if(p==NULL){
        printf("NAO EXISTE A PILHA!");
        exit(1);
    }

    //temp
    elemen *atual=p->topo;

    while(atual!=NULL){
        elemen *temp=atual;
        atual=atual->prox;
        free(temp);//LIBERAR OS NÓS

    }
    //LIBERAR A PILHA
    free(p);
}

int main(){

    //init stack
    pilha *p = initstack();
    char frase[100];

    //entrada da frase
    printf("digite uma frase qualquer que temina com ponto:\n");
    setbuf(stdin, NULL);
    fgets(frase, 100, stdin);

    //empilhar e desempilhar
    for (int i=0; frase[i]!='\0'; i++){
        if(frase[i]!=' '&&frase[i]!='.'){
            push(p, frase[i]);
        }else{
            while(p->topo!=NULL){
                printf("%c", p->topo->letra);
                pop(p);
            }
            printf("%c", frase[i]);
            if(frase[i]=='.'){
                break;
            }
        }
    }

    freeStack(p);
    return 0;
}
