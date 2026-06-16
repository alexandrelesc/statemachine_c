#include <stdio.h>
#include <stdlib.h>

#define ESTADO_INICIAL 0 //define que representa o estado inicial
#define ESTADO_DIGITOU_LETRA_A 1   //define que representa o estado no qual a letra 'a' foi digitada
#define ESTADO_DIGITOU_LETRA_B 2   //define que representa o estado no qual a letra 'b' foi digitada
#define ESTADO_DIGITOU_LETRA_C 3   //define que representa o estado no qual a letra 'c' foi digitada

//variaveis globais:
static char ControleMaquinaEstado;  //variável responsável por armazenar o estado atual da máquina de estados

//prototypes:
void ExecutaMaquinaDeEstados(void);   //função que contém o switch/case com a máquina de estados

//função de execução da máquina de estados via switch/case
void ExecutaMaquinaDeEstados(void)
{
  static char TeclaLida;
  //faz a leitura da tecla pressionada
  fflush(stdin); //limpa o buffer de teclado
  //scanf("$[^\\n]", &TeclaLida);
  TeclaLida = getchar();
  getchar();
  printf("TeclaLida = %c\r\n", TeclaLida);

 


  //executa a máquina de estados
  switch(ControleMaquinaEstado)
  {
    case ESTADO_INICIAL:
    {
      //somente muda de estado se for digitada a letra 'a'
      if (TeclaLida == 'a'){
        ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_A;
        printf("Estou no estado Inicial... para mudar digite o próximo estado...\n\n"); 
      } else
        printf("\n\n- Caracter esperado: a. Permanece no estado inicial\n\n"); 
      break; 
    }

    case ESTADO_DIGITOU_LETRA_A:
    {
      //Vai para proximo estado se for digitada a letra 'b'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
      if (TeclaLida == 'b')
        ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_B;
      else
      {
        printf("\n\n- Caracter esperado: b. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
        ControleMaquinaEstado = ESTADO_INICIAL;
      }
      break; 
    }

    case ESTADO_DIGITOU_LETRA_B:
    {
      //Vai para proximo estado se for digitada a letra 'c'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
      if (TeclaLida == 'c')
        ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_C;
      else
      {
        printf("\n\n- Caracter esperado: c. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
        ControleMaquinaEstado = ESTADO_INICIAL;
      }
      break; 
    }

    case ESTADO_DIGITOU_LETRA_C:
    {
      //Valida seqüência se se for digitada a letra 'd'. Caso contrario, volta ao estado inicial (aguardar letra 'a')
      if (TeclaLida != 'd')
        printf("\n\n- Caracter esperado: d. Caracter lido: %c. Voltando ao estado inicial\n\n",TeclaLida);
      else
        printf("OK\n\n"); //a seqüência de letras digitada é correta. Escreve "OK" na tela e volta ao estado inicial

      ControleMaquinaEstado = ESTADO_INICIAL;
      break; 
    } 
  }
}

//programa principal
int main(int argc, char *argv[])
{
  ControleMaquinaEstado = ESTADO_INICIAL; //estado inicial da variável de estado (Nunca esquecer de definir um estado inicial em uma máquina de estados!!!)

  while(1)
  {
    ExecutaMaquinaDeEstados();    //executa "para sempre" a máquina de estados
  }

  system("PAUSE"); 
  return 0;
}
