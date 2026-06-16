#include <stdio.h>

// Protótipos das funções que representam os estados
void EstadoInicial(void);       //função que representa o estado inicial da máquina de estados
void CaracterDigitadoA(void);   //função que representa o estado ao qual já foi digitada a letra 'a'
void CaracterDigitadoB(void);   //função que representa o estado ao qual já foi digitada a letra 'b'
void CaracterDigitadoC(void);   //função que representa o estado ao qual já foi digitada a letra 'c'

// Ponteiro de função que aponta para o estado atual
void (*PonteiroDeFuncao)(void);

// Função auxiliar para ler uma tecla
char LerTecla(void)
{
    char tecla;

    printf("Digite uma tecla: ");
    scanf(" %c", &tecla); // ignora ENTER anterior

    return tecla;
}

// Estado inicial: espera a letra 'a'
void EstadoInicial(void)
{
    char TeclaLida = LerTecla();

    if (TeclaLida == 'a')
    {
        PonteiroDeFuncao = CaracterDigitadoA;
        printf("Letra 'a' correta. Indo para o estado A.\n\n");
    }
    else
    {
        printf("Caracter esperado: a. Permanece no estado inicial.\n\n");
    }
}

// Estado após digitar 'a': espera a letra 'b'
void CaracterDigitadoA(void)
{
    char TeclaLida = LerTecla();

    if (TeclaLida == 'b')
    {
        PonteiroDeFuncao = CaracterDigitadoB;
        printf("Letra 'b' correta. Indo para o estado B.\n\n");
    }
    else
    {
        printf("Caracter esperado: b. Voltando ao estado inicial.\n\n");
        PonteiroDeFuncao = EstadoInicial;
    }
}

// Estado após digitar 'a' e 'b': espera a letra 'c'
void CaracterDigitadoB(void)
{
    char TeclaLida = LerTecla();

    if (TeclaLida == 'c')
    {
        PonteiroDeFuncao = CaracterDigitadoC;
        printf("Letra 'c' correta. Indo para o estado C.\n\n");
    }
    else
    {
        printf("Caracter esperado: c. Voltando ao estado inicial.\n\n");
        PonteiroDeFuncao = EstadoInicial;
    }
}

// Estado após digitar 'a', 'b' e 'c': espera a letra 'd'
void CaracterDigitadoC(void)
{
    char TeclaLida = LerTecla();

    if (TeclaLida == 'd')
    {
        printf("OK! Sequencia correta: a b c d\n\n");
    }
    else
    {
        printf("Caracter esperado: d. Voltando ao estado inicial.\n\n");
    }

    PonteiroDeFuncao = EstadoInicial;
}

int main(void)
{
    // Estado inicial da máquina
    PonteiroDeFuncao = EstadoInicial;

    // Executa a máquina continuamente
    while (1)
    {
        PonteiroDeFuncao();
    }

    return 0;
}
