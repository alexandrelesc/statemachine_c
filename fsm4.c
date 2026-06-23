#include <stdio.h>

typedef enum {
    Idle_State,
    Card_Inserted_State,
    Pin_Entered_State,
    Option_Selected_State,
    Amount_Entered_State
} eSystemState;

typedef enum {
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event,
    Invalid_Event
} eSystemEvent;

eSystemState AmountDispatchHandler(void) {
    printf("Dinheiro entregue\n");
    return Idle_State;
}

eSystemState EnterAmountHandler(void) {
    printf("Valor informado\n");
    return Amount_Entered_State;
}

eSystemState OptionSelectionHandler(void) {
    printf("Opcao selecionada\n");
    return Option_Selected_State;
}

eSystemState EnterPinHandler(void) {
    printf("PIN informado\n");
    return Pin_Entered_State;
}

eSystemState InsertCardHandler(void) {
    printf("Cartao inserido\n");
    return Card_Inserted_State;
}

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

int main(void) {
    eSystemState eNextState = Idle_State;
    eSystemEvent eNewEvent;

    while (1) {
        eNewEvent = ReadEvent();

        switch (eNextState) {
            case Idle_State:
                printf("Estado atual: Idle_State\n");
                if (eNewEvent == Card_Insert_Event)
                    eNextState = InsertCardHandler();
                else
                    printf("Evento invalido nesse estado\n");
                break;

            case Card_Inserted_State:
                printf("Estado atual: Card_Inserted_State\n");
                if (eNewEvent == Pin_Enter_Event)
                    eNextState = EnterPinHandler();
                else
                    printf("Evento invalido nesse estado\n");
                break;

            case Pin_Entered_State:
                printf("Estado atual: Pin_Entered_State\n");
                if (eNewEvent == Option_Selection_Event)
                    eNextState = OptionSelectionHandler();
                else
                    printf("Evento invalido nesse estado\n");
                break;

            case Option_Selected_State:
                printf("Estado atual: Option_Selected_State\n");
                if (eNewEvent == Amount_Enter_Event)
                    eNextState = EnterAmountHandler();
                else
                    printf("Evento invalido nesse estado\n");
                break;

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
