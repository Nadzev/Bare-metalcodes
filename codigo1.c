#include <avr/io.h>//Bibiloteca com as funções de E/S dos microcontroladores AVR
#include <util/delay.h>//Biblioteca com as funções de delay, como a _delay_ms, utilizada ao longo do 
#include <stdbool.h> //Bliblioteca com as funções booleanas, como true e false, utilizadas ao longo do 

#define INPUT true // Declaração de constante usada na função NewPinMode()
#define OUTPUT false // Declaração de constante usada na função NewPinMode()

//Abaixo, declaração de macros para a ativação dos registradores do tipo PORTx
#define PORTAO_B 1
#define PORTAO_C 2
#define PORTAO_D 3

//Protótipo das funções NewPinMode(), NewDigitalWrite() e NewDigitalRead()
void NewPinMode(int pino, bool modo, int portao);
void NewDigitalWrite(int pino, bool valor, int portao);
bool NewDigitalRead(int pino, int portao);

int main()
{
 newPinMode(DDB5,OUTPUT, PORTAO_B);//definição de PORTAO_B como saida 
  
    while(1)
    {
      newDigitalWrite(PORTB5,HIGH,PORTAO_B);//
    
      _delay_ms(1000); 
    
      newDigitalWrite(PORTB5,LOW,PORTAO_B);

      _delay_ms(1000); 
    }
  return 0;
}

/*
    Sintaxe: newPInMode()
    Descrição: Configura o pino especificado para funcionar como entrada ou saída.
    Parâmetros:
               -int pino: o numero do pino, que pode ser DDRXn.
               -bool modo: Este pode ser INPUT ou OUTPUT.
               -int porta: DDRB / DDRC / DDRD
*/
void newPinMode(int pino, bool modo, int portao)
{
  if (modo == INPUT) //Condição para que o pino seja declarado como entrada
  {
        if (portao == PORTAO_B)
        {
          DDRB &= ~(1 << pino);
        }
        
        else if (portao == PORTAO_C)
        {
          DDRC &= ~(1 << pino);
        }
        
        else if (portao == PORTAO_D)
        {
          DDRD &= ~(1 << pino);
        }
  }
  
  else if(modo == OUTPUT)//Condição para que o pino seja declarado como saida
  {
    
        if (portao == PORTAO_B)/
        {
          DDRB |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_B, o registrador DDRB sera setado no bit relacionado ao pino 
        }
        
        else if (portao == PORTAO_C)
        {
          DDRC |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_B, o registrador DDRB sera setado no bit relacionado ao pino
        }
        
        else if (portao == PORTAO_D)
        {
          DDRD |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_B, o registrador DDRB sera setado no bit relacionado ao pino
        }
    
  }
}
/*
    Sintaxe: newDigitalWrite()
    Descrição: Aciona um valor HIGH ou LOW em um pino digital.
    Parâmetros:
                   -int pino: o numero do pino.
                   -bool valor: Este pode ser HIGH ou LOW.
                   -int porta0: PORTB / PORTC / PORTD
*/
void newDigitalWrite(int pino, bool valor, int portao)
{
            if (valor == HIGH)
            {
                  if (portao == PORTAO_B)
                  {
                    PORTB |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_B, o registrador PORTB sera setado no bit relacionado ao pino
                  }
                  else if (portao == PORTAO_C)
                  {
                    PORTC |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_C, o registrador PORTC sera setado no bit relacionado ao pino
                  }
                  
                  else if (portao == PORTAO_D)
                  {
                    PORTD |= (1 << pino);//Caso o paramêtro portao seja do tipo PORTAO_D, o registrador PORTD sera setado no bit relacionado ao pino
                  }
            }
            
            else if(valor == LOW)
            {
                  if (portao == PORTAO_B)
                  {
                    PORTB &= ~(1 << pino);
                  }
                  
                  else if (portao == PORTAO_C)
                  {
                    PORTC &= ~(1 << pino);
                  }
                  
                  else if (portao == PORTAO_D)
                  {
                    PORTD &= ~(1 << pino);
                  }
            }
 }


 /*
    Sintaxe: newDigitalRead()
    Descrição: Lê o valor de um pino digital especificado, que pode ser HIGH ou LOW.
    Parâmetros:
                   -int pino: o numero do pino, que pode ser PINXn.
                   -int portao: Este por sua vez pode ser PORTA0_B / PORTA0_C / PORTA0_D.
*/
bool newDigitalRead(int pino, int portao)
{

      if (portao == PORTAO_B)
      {
          if ((PINB & (1 << pino)) == (1 << pino))//Se o pino PINB estiver setado na posição (1<<pino) a comparação retornará true
          {
            return HIGH;
          }
          else 
          {
            return LOW;
          }
      }
      
      else if (portao == PORTAO_C)
      {
          if ((PINC & (1 << pino)) == (1 << pino))//Se o pino PINC estiver setado na posição (1<<pino) a comparação retornará true
          {
            return HIGH;
          }
          else 
          {
            return LOW;
          }
      }
      
      else if (portao == PORTAO_D)
      {
          if ((PIND & (1 << pino)) == (1 << pino))//Se o pino PIND estiver setado na posição (1<<pino) a comparação retornará true
          {
            return HIGH;
          }
          else 
          {
            return LOW;
          }
      }
}