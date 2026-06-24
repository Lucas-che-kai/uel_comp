#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *vetor, int tamanho){
    int numero_digitado;
    int repetido;

    printf("\n--- ETAPA 1: DIGITE SUA APOSTA ---\n");
    for (int i=0; i<tamanho; i++){
        printf("Digite o valor do numero %d (0 a 100): ", i+1);
        scanf("%d",&numero_digitado);

        if(numero_digitado<0 || numero_digitado>100){
            printf("[ERRO] Valor fora do limite! Tente novamente.\n\n");
            i--;
            continue;
        }

        repetido = 0;
        for(int j=0; j<i; j++){
            if(vetor[j] == numero_digitado){
                repetido = 1;
                break;
            }
        }

        if(repetido == 1){
            printf("[ERRO] Voce ja escolheu esse numero! Escolha outro.\n\n");
            i--;
        } else {
            vetor[i] = numero_digitado;
        }
    }
}

void sorteia_valores(int *sorteio, int n){
    int numerosorteado;
    int repetido;

    srand(time(NULL));

    for(int i=0; i<n; i++){
        do{
            numerosorteado=rand()%101;
            repetido=0;
            for(int j=0; j<i; j++){
                if(sorteio[j]==numerosorteado){
                    repetido=1;
                    break;
                }
            }
        }while(repetido==1);
        sorteio[i]=numerosorteado;
    }
}

int *compara_aposta(int *aposta, int *sorteio, int *qntdd_acertos, int tamanho){
    int *acertos;
    *qntdd_acertos=0;
    for(int i=0; i<tamanho; i++){
        for (int m=0; m<tamanho; m++){
            if(aposta[i]==sorteio[m]){
                (*qntdd_acertos)++;
            }
        }
    }

    if (*qntdd_acertos == 0) {
        return NULL;
    }

    acertos=(int*)malloc((*qntdd_acertos)*sizeof(int));
    if(acertos==NULL){
        printf("\n[ERRO] Falha grave de memoria!\n");
        exit(1);
    }
    
    int k=0;
    for(int i=0; i<tamanho; i++){
        for (int m=0; m<tamanho; m++){
            if(aposta[i]==sorteio[m]){
                acertos[k]=aposta[i];
                k++;
            }
        }
    }

    return acertos;
}

int main(){
    int n;
    int *aposta, *sorteio, qntdd_acertos=0, *acertos;

    printf("==================================================\n");
    printf("               BINGO DE PROG II                   \n");
    printf("==================================================\n\n");
    
    printf("Quantos números você deseja apostar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nQuantidade invalida! Encerrando...\n");
        return 1;
    }

    aposta = (int *)malloc(n*sizeof(int));
    if(aposta==NULL){
        printf("\n[ERRO] Falha grave de memoria!\n");
        exit(1);
    }
    ler_aposta(aposta,n);

    sorteio = (int *)malloc(n*sizeof(int));
    if(sorteio==NULL){
        printf("\n[ERRO] Falha grave de memoria!\n");
        exit(1);
    }
    sorteia_valores(sorteio, n);
    acertos=compara_aposta(aposta,sorteio, &qntdd_acertos, n);

    printf("\n==================================================\n");
    printf("               RESULTADO DO BINGO                 \n");
    printf("==================================================\n");
    
    printf("\nNumeros que voce escolheu:\n");
    for (int i=0; i<n; i++) {
        printf("[%d] ", aposta[i]);
    }
    
    printf("\n\nNumeros sorteados pelo computador:\n");
    for (int i=0; i<n; i++) {
        printf("[%d] ", sorteio[i]);
    }

    printf("\n\n--------------------------------------------------\n");
    printf("Quantidade de acertos: %d\n", qntdd_acertos);
    
    if (qntdd_acertos > 0) {
        printf("Numeros acertados: ");
        for (int i=0; i<qntdd_acertos; i++){
            printf("%d ", acertos[i]); 
        }
        printf("\n");
    } else {
        printf("Infelizmente voce nao acertou nenhum numero desta vez.\n");
    }
    printf("--------------------------------------------------\n\n");

    if (acertos != NULL) {
        free(acertos);
    }
    free(sorteio);
    free(aposta);
    return 0;
}
