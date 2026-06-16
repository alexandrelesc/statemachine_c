#include <stdio.h>
//Different state of ATM machine
typedef enum
{
    Idle_State,
    Card_Inserted_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
} eSystemState;
//Different type events
typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event
} eSystemEvent;
//Prototype of eventhandlers
eSystemState AmountDispatchHandler(void)
{
    printf("AmountDispatchHandler\r\n");
    return Idle_State;
}
eSystemState EnterAmountHandler(void)
{
    printf("EnterAmountHandler \r\n");
    return Amount_Entered_State;
}
eSystemState OptionSelectionHandler(void)
{
    printf("OptionSelectionHandler \r\n");
    return Option_Selected_State;
}
eSystemState EnterPinHandler(void)
{
    printf("EnterPinHandler \r\n");
    return Pin_Eentered_State;
}
eSystemState InsertCardHandler(void)
{
    printf("InsertCardHandler \r\n");
    return Card_Inserted_State;
}

eSystemEvent ReadEvent(void)
{
  char inputEvent = 0;
  printf("waiting for a new event: ");
  scanf("%c", &inputEvent);
  printf("%c\r\n", inputEvent);
  
  if(inputEvent == 'a'){
    return Card_Insert_Event;
  }

  if(inputEvent == 'b'){
    return Pin_Enter_Event;
  }

  if(inputEvent == 'c'){
    return Option_Selection_Event;
  }

  if(inputEvent == 'd'){
    return Amount_Enter_Event;
  }
  
  if(inputEvent == 'e'){
    return Amount_Dispatch_Event;
  }
}

int main(int argc, char *argv[])
{
    eSystemState eNextState = Idle_State;
    eSystemEvent eNewEvent;
    while(1)
    {
        //Read system Events
        eSystemEvent eNewEvent = ReadEvent();
        switch(eNextState)
        {
        case Idle_State:
        {
            printf("Idle_State\r\n");
            if(Card_Insert_Event == eNewEvent)
            {
                printf("Card_Insert_Event\r\n");
                eNextState = InsertCardHandler();
            }
        }
        break;
        case Card_Inserted_State:
        {
            printf("Card_Inserted_State\r\n");
            if(Pin_Enter_Event == eNewEvent)
            {
                printf("Pin_Enter_Event\r\n");
                eNextState = EnterPinHandler();
            }
        }
        break;
        case Pin_Eentered_State:
        {
            printf("Pin_Eentered_State\r\n");
            if(Option_Selection_Event == eNewEvent)
            {
                printf("Option_Selection_Event\r\n");
                eNextState = OptionSelectionHandler();
            }
        }
        break;
        case Option_Selected_State:
        {
            printf("Option_Selected_State\r\n");
            if(Amount_Enter_Event == eNewEvent)
            {
                printf("EnterAmountHandler\r\n");
                eNextState = EnterAmountHandler();
            }
        }
        break;
        case Amount_Entered_State:
        {
            printf("EnterAmountHandler\r\n");
            if(Amount_Dispatch_Event == eNewEvent)
            {
                printf("AmountDispatchHandler\r\n");
                eNextState = AmountDispatchHandler();
            }
        }
        break;
        default:
            break;
        }
    }
    return 0;
}
