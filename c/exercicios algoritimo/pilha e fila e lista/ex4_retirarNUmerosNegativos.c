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

//funcao para inicializar a fila
fila *initQueue(){
    fila *f = (fila *)malloc(sizeof(fila));
    if(f==NULL){
        printf("FILA NAO INICIALIZADO COM SUCESSO!\n");
        exit(1);
    }
    f->fim=NULL;
    f->inicio=NULL;
    return f;
}

//funcao para inserir dados na fila
void push(fila *f, int valor){
    if(f==NULL){
        printf("FILA NAO INICIALIZADA AINDA!\n");
        exit(1);
    }

    elemen *novo = (elemen*)malloc(sizeof(elemen));
    if(novo==NULL){
        printf("ERRO NA CRIACAO DO NOVO ELEMENTO!\n");
        exit(1);
    }

    novo->valor=valor;
    novo->prox=NULL;
    if(f->fim==NULL){
        f->inicio=novo;
        f->fim=novo;
    }else{
        f->fim->prox=novo;
        f->fim=novo;
    }
}

//funcao para tirar os numeros negativos
void removerNegativos(fila *f){
    if(f == NULL){ 
        printf("FILA NAO INICIALIZADA!\n"); 
        exit(1); 
    } 

    elemen *atual = f->inicio;
    elemen *anterior = NULL;
    elemen *temp = NULL;

    while(atual != NULL){
        if(atual->valor < 0){
            temp = atual; 

            if(atual == f->inicio){
                f->inicio = atual->prox;
                atual = f->inicio;
            } else {
                anterior->prox = atual->prox;
                atual = anterior->prox;
            }

            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    f->fim = anterior;
}

//funcao para imprimir a fila na tela
void printQueue(fila *f){
    if(f == NULL || f->inicio == NULL){
        printf("Fila vazia!\n");
        return;
    }
    
    elemen *atual = f->inicio;
    while(atual != NULL){
        printf("[%d] -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

//funcao para liberar toda a memoria da fila
void freeQueue(fila *f){
    if(f == NULL) return;
    
    elemen *atual = f->inicio;
    elemen *temp = NULL;
    
    // Libera elemento por elemento
    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    // Por fim, libera a estrutura da fila
    free(f);
}

//funcao principal para testar o codigo
int main(){
    // 1. Cria e inicializa a fila
    fila *minhaFila = initQueue();

    // 2. Insere vários números (positivos e negativos)
    push(minhaFila, 10);
    push(minhaFila, -5);
    push(minhaFila, 20);
    push(minhaFila, -3);
    push(minhaFila, -1);
    push(minhaFila, 30);

    // 3. Mostra a fila antes da limpeza
    printf("Fila original:\n");
    printQueue(minhaFila);

    // 4. Remove os negativos
    removerNegativos(minhaFila);

    // 5. Mostra a fila depois da limpeza
    printf("\nFila apos remover os negativos:\n");
    printQueue(minhaFila);

    // 6. Limpa a fila da memória antes de fechar o programa
    freeQueue(minhaFila);

    return 0;
}