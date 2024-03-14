//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO sqrt128.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o sqrt128 sqrt128.c


//Cabeçalho
#include"sqrt128.h"


//Função principal
int main(){
//Variáveis locais
char number_string[40];
__int128_t n, root;


//Procedimentos
//Recebendo input
printf("Valor: ");
scanf("%s", number_string);

n=scanf128(number_string);



//Calculando o produto das duas parcelas
root=sqrt128(n);

printf("Raíz quadrada: ");
printf128(root);

//Finalizando a aplicação 
return 0;
          }

