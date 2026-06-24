#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
srand(time(NULL));
int num = (rand() % 100) + 1;
int chut, cont=0, menor=0,maior=100;
printf("******************************vamos jogar um jogo de adivinhação******************************\n");
while(1){
printf("digite um numero:\n");
scanf("%d",&chut);
cont++;
if(chut==num) {
printf("voce acertou o numero!, a quantidade de chute foi:%d\n", cont);
break;
}else if(chut<num){
    menor=chut;
printf("muito baixo, digite outro numero de %d a %d:\n", menor, maior);
}else if(chut>num){
    maior=chut;
printf("muito alto, digite outro numero de %d a %d:\n", menor, maior);
}
}
return 0;
}