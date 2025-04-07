//codigo clase un motor giro derecha izquierda con pulsador
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    DDRD|=(0XC0); //este sonl os pines para el control del motor 1
    PORTD&=~(0XC0);

    DDRC|=(0X0C); //motor 2
    PORTD&=~(0x0c);

    DDRD&=~(0X20); //del boton como entrada
    PORTD|=(0X20); //pull del boton

    char flag=0; //variable de estado del sistema

    while(1){ //cadena de inico
    if(!(PIND&0x20)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos


        if(flag==0){
            PORTD&=~(0XC0);
            PORTD|=0X80; //si esta en reposo se enciende el in2 
            PORTD&=~(0X0C);
            PORTD|=0X08;
            flag=1; //estado 1
        }
        else{
            if(flag==1){
                PORTD&=~(0XC0); //apaga los motores
                PORTD&=~(0X0C);

                _delay_ms(50); // evitar ruidos
                PORTD|=(0X40); //se enciende el in1 cambiando el giro
                PORTD|=(0X04);
                flag=2; //estado 2

            }
            else{
                PORTD&=~(0XC0); //apagara el motor
                PORTD &=~(0X0C);
                _delay_ms(50);
                flag=0; //vuelve al estado 0
            }
        }
    }    
    
}
}
        
/*
//codigo clase un motor giro derecha izquierda con pulsador
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    DDRD|=(0XC0); //este sonl os pines para el control del motor 1
    PORTD&=~(0XC0);
    DDRD&=~(0X20); //del boton como entrada
    PORTD|=(0X20); //pull del boton
    char flag=0; //variable de estado del sistema

    while(1){ //cadena de inico
    if(!(PIND&0x20)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos


        if(flag==0){
            PORTD&=~(0XC0);
            PORTD|=0X80; //si esta en reposo se enciende el in2 
            flag=1; //estado 1
        }
        else{
            if(flag==1){
                PORTD&=~(0XC0); //apaga los motores
                _delay_ms(50); // evitar ruidos
                PORTD|=(0X40); //se enciende el in1 cambiando el giro
                flag=2; //estado 2

            }
            else{
                PORTD&=~(0XC0); //apagara el motor
                _delay_ms(50);
                flag=0; //vuelve al estado 0
            }
        }
    }    
    
}
}
*/

/*
//codigo uniendo los dos motores funcionen al mismo tiempo con 1 boton switch
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

                case 1: //dos adelante
                PORTD&=~(0X0C); //cuando el pd7 y pd6 esten en 1 se va negar y se volvera 0 significando que esta apagado
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X04); //el pin pd6 va a estar en 1 girando en otro sentido
                PORTD|=(0X40);
                flag=2; //estado 2
                break; //para solo ejecutar caso1

                //prueba giro largo 1
                case 2:
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD&=~(0XC0); //el motor 1 en 0
                PORTD|=(0X08);//el pin4 en 1
                flag=3; //estado 2
                break; //para solo ejecutar caso1

                //prueba giro largo 2
                case 3:
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD&=~(0X0C); //el pin pd6 va a estar en 1 girando en otro sentido
                PORTD|=(0X80);
                flag=4; //estado 2
                break; //para solo ejecutar caso1

                //prueba giro corto 1
                case 4:
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X80); //el motor 1 en 0
                PORTD|=(0X04);//el pin4 en 1
                flag=5; //estado 2
                break; //para solo ejecutar caso1

                //prueba giro corto 2

                case 5:
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X40); //
                PORTD|=(0X08);//el pin4 en 1
                flag=5; //estado 2
                break; //para solo ejecutar caso1


                case 6: //solo esn ombre de estado
                PORTD&=~(0XC0); //apagados pd7 y pd6
                PORTD&=~(0X0C);
                flag=0; // se va volver al estado 0
                break; //no seguir ejecutando
            }
        }
    } 
}

*/