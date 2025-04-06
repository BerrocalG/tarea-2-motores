//codigo uniendo los dos motores funcionen al mismo tiempo con 1 boton
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    //motor 1
    DDRD|=0XC0;
    PORTD&=~(0XC0);
    //motor 2
    DDRD|=0X0C;
    PORTD&=~(0X0C);

    //boton
    DDRD&=~(0X20);
    PORTD|=(0X20);
    char flag=0;

    while(1) {

        if(!(PIND&0X20)){ //cuando el pin del boton este en 0 se va a prender
            _delay_ms(100);

            switch(flag){
                case 0: //caso 0
                PORTD|=0X80;
                PORTD|=0X08; //cuando el pd7 esta en 1
                flag=1; //estado1
                break; // para que solo ejecute ese bloque

                case 1:
                PORTD&=~(0X0C); //cuando el pd7 y pd6 esten en 1 se va negar y se volvera 0 significando que esta apagado
                PORTD&=~(0XC0);
                _delay_ms(50); //abra un delay
                PORTD|=(0X04); //el pin pd6 va a estar en 1 girando en otro sentido
                PORTD|=(0X40);
                flag=2; //estado 2
                break; //para solo ejecutar caso1

                case 2: //solo esn ombre de estado
                PORTD&=~(0X0C); //apagados pd7 y pd6
                PORTD&=~(0XC0);
                flag=0; // se va volver al estado 0
                break; //no seguir ejecutando
            }
        }
    } 
}
/*
//codigo base clase para 1 motor
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    DDRD|=0XC0;
    PORTD&=~(0XC0);
    DDRD&=~(0X20);
    PORTD|=(0X20);
    char flag=0;

    while(1) {

        if(!(PIND&0X20)){
            _delay_ms(100);
            switch(flag){
                case 0:

                PORTD|=0X80;
                flag=1;
                break;

                case 1:
                PORTD&=~(0XC0);
                _delay_ms(50);
                PORTD|=(0X40);
                flag=2;
                break;

                case 2:
                PORTD&=~(0XC0);
                flag=0;
                break;
            }
        }
    } 
}
*/