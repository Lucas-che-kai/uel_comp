#include <stdio.h>
#include <stdlib.h>


typedef struct elemento{
    char letra;
    struct elemento *prox;
}elemen;


typedef struct{
    elemen *topo;
}pilha;


pilha *initStack(){
    //criar pilha dinamicamente
    pilha *p=(pilha *)malloc(sizeof(pilha));
    if(p==NULL){


        printf("ERRO NA INICALIZACAO DA PILHA !");
        exit(1);
    }


    //apontar o topo para o null
    p->topo=NULL;
    return p;
}


void push(pilha *p, char letra){
    //verificar se existe a pilha
    if(p==NULL){
        printf("PILHA NAO INICIALIZADO!");
        exit(1);
    }


    //alocar um novo elemento
    elemen *novo=(elemen *)malloc(sizeof(elemen));
    if(novo==NULL){
        printf("ERRO NA CRIACAO DO NOVO ELEMENTO");
        exit(1);
    }
    //colocar na pilha o elemento
    novo->letra=letra; 
    novo->prox=p->topo;
    p->topo=novo;
}

char pop(pilha *p){
    //verifica se existe a pilha
    if(p==NULL){
        printf("PILHA AINDA NAO FOI INICIALIZADO!");
        exit(1);
    }

    //verifica se a pilha esta vazia

    if(p->topo == NULL){
        printf("PILHA VAZIA!");
        exit(1);
    }

    //ponteiro para receber o elemento
    elemen *temp=p->topo;
    char a = temp->letra;
    p->topo=temp->prox;
    free(temp);
    //nessa preciso retornar o char
    return a;
}

void freeStack(pilha *p){
    //verifica se existe a pilha 
    if(p==NULL){
        printf("PILHA AINDA NAO FOI INICIALIZADO!");
        exit(1);
    }

    //ponteiro para percorrer cada elemennto
    elemen *temp = p->topo;

    while(temp!=NULL){
        //elemento p dar free
        elemen *lixo=temp;
        temp=temp->prox;
        free(lixo);
    }

    free(p);
}

int main(){

    char palavra[30];
    int sinal=1;

    //pegar a palavra
    printf("digite a palavra para verificar se é palindromo:\n");
    setbuf(stdin, NULL);
    fgets(palavra, 30, stdin);

    //tirar o \n
    for(int i=0; palavra[i] != '\0'; i++){
    if(palavra[i] == '\n'){
        palavra[i] = '\0';
        break;
    }
}

    //inicializar a pilha
    pilha *p= initStack();

    //empilhar a palavra de letra a letra na pilha
    for(int i=0; palavra[i]!='\0'; i++){
        push(p, palavra[i]);
    }

    //desempilhar a pilha e comparar
    for (int i=0; palavra[i]!='\0'; i++){
        char temp=pop(p);
        if(palavra[i]!=temp){
            sinal=0;
            break;
        }
    }

    if(sinal==1){
        printf("a palavra: \"%s\" é um palindromo", palavra);
    }else if(sinal==0){
        printf("a palavra: \"%s\" não é um palindromo", palavra);
    }
    freeStack(p);
    return 0;
}