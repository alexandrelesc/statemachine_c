#include <stdio.h>

/*
 * Enumeração dos estados possíveis da máquina de estados.
 * Cada valor representa uma etapa da operação do caixa eletrônico.
 */
typedef enum {
    Idle_State,             // Estado inicial (aguardando cartão)
    Card_Inserted_State,    // Cartão inserido
    Pin_Entered_State,      // PIN digitado
    Option_Selected_State,  // Operação selecionada
    Amount_Entered_State    // Valor informado
} eSystemState;

/*
 * Enumeração dos eventos que podem ocorrer no sistema.
 * Os eventos provocam transições entre estados.
 */
typedef enum {
    Card_Insert_Event,       // Usuário inseriu o cartão
    Pin_Enter_Event,         // Usuário digitou o PIN
    Option_Selection_Event,  // Usuário escolheu uma operação
    Amount_Enter_Event,      // Usuário informou um valor
    Amount_Dispatch_Event,   // Sistema entregou o dinheiro
    Invalid_Event            // Evento inválido
} eSystemEvent;


/*
 * Função executada quando o dinheiro é entregue.
 * Após a operação, o ATM retorna ao estado inicial.
 */
eSystemState AmountDispatchHandler(void) {
    printf("Dinheiro entregue\n");
    return Idle_State;
}

/*
 * Função executada quando o valor do saque é informado.
 */
eSystemState EnterAmountHandler(void) {
    printf("Valor informado\n");
    return Amount_Entered_State;
}

/*
 * Função executada quando o usuário seleciona uma operação.
 */
eSystemState OptionSelectionHandler(void) {
    printf("Opcao selecionada\n");
    return Option_Selected_State;
}

/*
 * Função executada quando o PIN é digitado.
 */
eSystemState EnterPinHandler(void) {
    printf("PIN informado\n");
    return Pin_Entered_State;
}

/*
 * Função executada quando o cartão é inserido.
 */
eSystemState InsertCardHandler(void) {
    printf("Cartao inserido\n");
    return Card_Inserted_State;
}


/*
 * Lê um evento do teclado.
 *
 * Mapeamento:
 * a -> inserir cartão
 * b -> digitar PIN
 * c -> selecionar operação
 * d -> informar valor
 * e -> entregar dinheiro
 */
eSystemEvent ReadEvent(void) {

    char inputEvent;

    printf("\nEventos:\n");
    printf("a - inserir cartao\n");
    printf("b - digitar PIN\n");
    printf("c - selecionar opcao\n");
    printf("d - informar valor\n");
    printf("e - entregar dinheiro\n");
    printf("Escolha: ");

    scanf(" %c", &inputEvent);

    if (inputEvent == 'a') return Card_Insert_Event;
    if (inputEvent == 'b') return Pin_Enter_Event;
    if (inputEvent == 'c') return Option_Selection_Event;
    if (inputEvent == 'd') return Amount_Enter_Event;
    if (inputEvent == 'e') return Amount_Dispatch_Event;

    return Invalid_Event;
}


/*
 * Função principal.
 */
int main(void) {

    /*
     * Estado atual da máquina.
     * Inicialmente o ATM está aguardando o cartão.
     */
    eSystemState eNextState = Idle_State;

    /*
     * Armazena o evento recebido do usuário.
     */
    eSystemEvent eNewEvent;

    /*
     * Loop infinito da máquina de estados.
     */
    while (1) {

        /*
         * Aguarda a ocorrência de um evento.
         */
        eNewEvent = ReadEvent();

        /*
         * Executa a lógica correspondente ao estado atual.
         */
        switch (eNextState) {

            /*
             * Estado: aguardando inserção do cartão.
             */
            case Idle_State:

                printf("Estado atual: Idle_State\n");

                if (eNewEvent == Card_Insert_Event)
                    eNextState = InsertCardHandler();
                else
                    printf("Evento invalido nesse estado\n");

                break;

            /*
             * Estado: cartão já inserido.
             * Próximo passo esperado: digitar PIN.
             */
            case Card_Inserted_State:

                printf("Estado atual: Card_Inserted_State\n");

                if (eNewEvent == Pin_Enter_Event)
                    eNextState = EnterPinHandler();
                else
                    printf("Evento invalido nesse estado\n");

                break;

            /*
             * Estado: PIN já digitado.
             * Próximo passo esperado: escolher operação.
             */
            case Pin_Entered_State:

                printf("Estado atual: Pin_Entered_State\n");

                if (eNewEvent == Option_Selection_Event)
                    eNextState = OptionSelectionHandler();
                else
                    printf("Evento invalido nesse estado\n");

                break;

            /*
             * Estado: operação selecionada.
             * Próximo passo esperado: informar valor.
             */
            case Option_Selected_State:

                printf("Estado atual: Option_Selected_State\n");

                if (eNewEvent == Amount_Enter_Event)
                    eNextState = EnterAmountHandler();
                else
                    printf("Evento invalido nesse estado\n");

                break;

            /*
             * Estado: valor informado.
             * Próximo passo esperado: entregar dinheiro.
             */
            case Amount_Entered_State:

                printf("Estado atual: Amount_Entered_State\n");

                if (eNewEvent == Amount_Dispatch_Event)
                    eNextState = AmountDispatchHandler();
                else
                    printf("Evento invalido nesse estado\n");

                break;
        }
    }

    return 0;
}
