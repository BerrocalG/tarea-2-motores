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