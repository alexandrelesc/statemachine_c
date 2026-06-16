#include <stdio.h>
#include <stdlib.h>


//variaveis globais:
void (*PonteiroDeFuncao)(); //ponteiro de função da máquina de estados. Ele aponta sempre para a função da máquina de estados que deve ser executada

//prototypes:
void EstadoInicial(void);       //função que representa o estado inicial da máquina de estados
void CaracterDigitadoA(void);   //função que representa o estado ao qual já foi digitada a letra 'a'
void CaracterDigitadoB(void);   //função que representa o estado ao qual já foi digitada a letra 'b'
void CaracterDigitadoC(void);   //função que representa o estado ao qual já foi digitada a letra 'c'

//Estado inicial da máquina de estados. Somente muda de estado se for digitada a letra 'a'
void EstadoInicial(void)
{
  char TeclaLida;
  //faz a leitura da tecla pressionada
  fflush(stdin); //limpa o buffer de teclado
  TeclaLida = getchar();
  getchar();

  if (TeclaLida == 'a'){
    PonteiroDeFuncao = CaracterDigitadoA;
    printf("Estamos indo para o próximo estado A\r\n");    
  } else 
    printf("\n\n- Caracter esperado: a. Permanece no estado inicial\n\n"); 
}

//Vai para proximo estado se for digitada a letra 'b'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
void CaracterDigitadoA(void)
{
  char TeclaLida;
  //faz a leitura da tecla pressionada
  fflush(stdin); //limpa o buffer de teclado
  TeclaLida = getchar();
  getchar();

  if (TeclaLida == 'b'){
    PonteiroDeFuncao = CaracterDigitadoB;
    printf("Estamos indo para o próximo estado B\r\n");
  } else
  {
    printf("\n\n- Caracter esperado: b. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
    PonteiroDeFuncao = EstadoInicial;
  }
}

//Vai para proximo estado se for digitada a letra 'c'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
void CaracterDigitadoB(void)
{
  char TeclaLida;
  //faz a leitura da tecla pressionada
  fflush(stdin); //limpa o buffer de teclado
  TeclaLida = getchar();
  getchar();

  if (TeclaLida == 'c'){
    PonteiroDeFuncao = CaracterDigitadoC;
    printf("Estamos indo para o próximo estado D\r\n"); 
    }  else
  {
    printf("\n\n- Caracter esperado: c. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
    PonteiroDeFuncao = EstadoInicial;
  } 
}

//Valida seqüência se se for digitada a letra 'd'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
void CaracterDigitadoC(void)
{
  char TeclaLida;
  //faz a leitura da tecla pressionada
  fflush(stdin); //limpa o buffer de teclado
  TeclaLida = getchar(); 
  getchar();

  if (TeclaLida != 'd')
    printf("\n\n- Caracter esperado: d. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
  else
    printf("OK\n\n"); //a seqüência de letras digitada é correta. Escreve "OK" na tela e volta ao estado inicial

  PonteiroDeFuncao = EstadoInicial;
}


int main(int argc, char *argv[])
{
  PonteiroDeFuncao = EstadoInicial; //aponta para o estado inicial. Nunca esquecer de informar um estado inicial (senão, nesse caso em específico, pode haver um erro fatal / hard fault).

  while(1)
  {
    (*PonteiroDeFuncao)();    //chama a função apontada pelo ponteiro de função (logo, chama o estado corrente)
  }
  system("PAUSE"); 
  return 0;
}
