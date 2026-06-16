#include <stdio.h>   // Biblioteca para funções de entrada e saída (printf, scanf)

// Definição dos estados da máquina de estados
#define ESTADO_INICIAL           0  //define que representa o estado inicial
#define ESTADO_DIGITOU_LETRA_A   1  //define que representa o estado no qual a letra 'a' foi digitada
#define ESTADO_DIGITOU_LETRA_B   2  //define que representa o estado no qual a letra 'b' foi digitada
#define ESTADO_DIGITOU_LETRA_C   3  //define que representa o estado no qual a letra 'c' foi digitada

// Variável global responsável por armazenar o estado atual da máquina
static char ControleMaquinaEstado;

// Protótipo da função que executa a máquina de estados
void ExecutaMaquinaDeEstados(void);

/*
 * Função responsável por executar a máquina de estados.
 * A cada chamada:
 *  1. Lê um caractere digitado pelo usuário.
 *  2. Verifica o estado atual.
 *  3. Executa as transições entre estados.
 */
void ExecutaMaquinaDeEstados(void)
{
    // Variável local utilizada para armazenar a tecla digitada
    char TeclaLida;

    // Solicita ao usuário um caractere
    printf("Digite uma tecla: ");

    /*
     * O espaço antes do %c faz com que o scanf ignore
     * espaços e ENTERs pendentes no buffer.
     */
    scanf(" %c", &TeclaLida);

    // Exibe o caractere lido
    printf("TeclaLida = %c\n", TeclaLida);

    /*
     * Máquina de estados implementada utilizando switch/case.
     * Cada case representa um estado diferente.
     */
    switch (ControleMaquinaEstado)
    {
        //--------------------------------------------------
        // ESTADO INICIAL
        //--------------------------------------------------
        case ESTADO_INICIAL:

            /*
             * Neste estado a máquina espera receber
             * a letra 'a'.
             */
            if (TeclaLida == 'a')
            {
                // Transição para o próximo estado
                ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_A;

                printf("Letra 'a' correta. Agora digite 'b'.\n\n");
            }
            else
            {
                // Permanece no estado inicial
                printf("Caracter esperado: a. Permanece no estado inicial.\n\n");
            }

            break;

        //--------------------------------------------------
        // ESTADO APÓS DIGITAR 'a'
        //--------------------------------------------------
        case ESTADO_DIGITOU_LETRA_A:

            /*
             * Agora a máquina espera receber
             * a letra 'b'.
             */
            if (TeclaLida == 'b')
            {
                // Transição para o próximo estado
                ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_B;

                printf("Letra 'b' correta. Agora digite 'c'.\n\n");
            }
            else
            {
                /*
                 * Qualquer caractere diferente de 'b'
                 * faz a máquina retornar ao estado inicial.
                 */
                printf("Caracter esperado: b. Voltando ao estado inicial.\n\n");

                ControleMaquinaEstado = ESTADO_INICIAL;
            }

            break;

        //--------------------------------------------------
        // ESTADO APÓS DIGITAR 'a' E 'b'
        //--------------------------------------------------
        case ESTADO_DIGITOU_LETRA_B:

            /*
             * Agora a máquina espera receber
             * a letra 'c'.
             */
            if (TeclaLida == 'c')
            {
                // Transição para o próximo estado
                ControleMaquinaEstado = ESTADO_DIGITOU_LETRA_C;

                printf("Letra 'c' correta. Agora digite 'd'.\n\n");
            }
            else
            {
                /*
                 * Qualquer caractere diferente de 'c'
                 * faz a máquina retornar ao estado inicial.
                 */
                printf("Caracter esperado: c. Voltando ao estado inicial.\n\n");

                ControleMaquinaEstado = ESTADO_INICIAL;
            }

            break;

        //--------------------------------------------------
        // ESTADO APÓS DIGITAR 'a', 'b' E 'c'
        //--------------------------------------------------
        case ESTADO_DIGITOU_LETRA_C:

            /*
             * Última verificação da sequência.
             * A máquina espera receber a letra 'd'.
             */
            if (TeclaLida == 'd')
            {
                // Sequência completa reconhecida
                printf("OK! Sequencia correta: a b c d\n\n");
            }
            else
            {
                // Sequência inválida
                printf("Caracter esperado: d. Voltando ao estado inicial.\n\n");
            }

            /*
             * Após finalizar a sequência (correta ou incorreta),
             * a máquina volta para o estado inicial.
             */
            ControleMaquinaEstado = ESTADO_INICIAL;

            break;
    }
}

/*
 * Função principal do programa.
 */
int main(void)
{
    /*
     * Inicialização da máquina de estados.
     * Toda máquina de estados deve começar em um estado conhecido.
     */
    ControleMaquinaEstado = ESTADO_INICIAL;

    /*
     * Loop infinito.
     * A máquina de estados será executada continuamente.
     */
    while (1)
    {
        ExecutaMaquinaDeEstados();
    }

    // Nunca será executado devido ao while(1)
    return 0;
}
