#include <stdio.h>
#define tam 3
//inicializar um tabuleiro
void inicializar(char tabuleiro[tam][tam]){
for(int i=0; i<tam; i++){
for (int m=0; m<tam; m++){
tabuleiro[i][m]= ' ';
}
}
}
//exibir

void exibir(char tabuleiro[tam][tam]){
printf("\n");
for (int i=0; i<tam; i++){
for (int m=0; m<tam; m++){
printf(" %c ", tabuleiro[i][m]);
if(m<2){
printf(" | ");
}
}
printf("\n");
if(i<2){
printf("----|-----|----\n");
}
}
printf("\n");
}
//verificar
int verificar(char tabuleiro[tam][tam]){
//linha
for(int i=0; i<tam; i++){
if(tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1]
&& tabuleiro[i][1] == tabuleiro[i][2]){
return 1;
}
}
//coluna
for (int i=0; i<tam; i++){
if(tabuleiro[0][i] != ' ' && tabuleiro[0][i]==tabuleiro[1][i]
&& tabuleiro[1][i]==tabuleiro[2][i]){
return 1;
}
}
//diagonal principal
if(tabuleiro[0][0] != ' ' && tabuleiro[0][0]==tabuleiro[1][1] &&
tabuleiro[1][1]==tabuleiro[2][2]){
return 1;
}
//diagonal secundaria

if(tabuleiro[2][0] != ' ' &&tabuleiro[2][0]==tabuleiro[1][1] &&
tabuleiro[1][1]==tabuleiro[0][2]){
return 1;
}
return 0;
}
//empate
int empate(char tabuleiro[tam][tam]){
for(int i = 0; i < tam; i++) {
for(int j = 0; j < tam; j++) {
if(tabuleiro[i][j] == ' ') {
return 0;
}
}
}
return 1;
}
int main(){
char tabuleiro [tam][tam];
char jogador = 'X';
int linha, coluna;
inicializar(tabuleiro);
while(1){
exibir(tabuleiro);
printf("A vez do jogador %c\n", jogador);
printf("digite a linha que voce quer preencher (1~3):\n");
scanf("%d", &linha);
linha--;
printf("digite a coluna que voce quer preencher (1~3):\n");
scanf("%d", &coluna);
coluna--;
//validar a linha e coluna preenchida
if(linha<0||linha>2||coluna<0||coluna>2){
printf("posicao invalida\n");
continue;
}

//validar se esta ocupado
if(tabuleiro[linha][coluna]!= ' '){
printf("posicao ja preenchida\n");
continue;
}
tabuleiro[linha][coluna]=jogador;
if(verificar(tabuleiro)==1){
exibir(tabuleiro);
printf("o jogador %c GANHOU!!\n", jogador);
break;
}
if(empate(tabuleiro)==1){
printf("O JOGO DEU EMPATE\n");
break;
}
if(jogador== 'X'){
jogador='O';
}else{
jogador='X';
}

}
return 0;
}