#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main(void) {
    DDRD |= 0xC0; // PD6 y PD7 salida (motor 1)
    PORTD &= ~0xC0;

    DDRD |= 0x0C; // PD2 y PD3 salida (motor 2)
    PORTD &= ~0x0C;

    DDRB &= ~0x02; // PB1 como entrada (botón 1)
    PORTB |= 0x02; // pull-up para botón 1

    DDRB &= ~0x01; // PB0 como entrada (botón 2)
    PORTB |= 0x01; // pull-up para botón 2

    DDRD &= ~0x20; // PD5 como entrada (botón 3)
    PORTD |= 0x20; // pull-up para botón 3

    char A = 0;
    char B = 0;
    char C = 0;
    char D = 0;
    char E = 0;
    char F = 0;

    while (1) {
        // Primera condición gira motor 1 apaga motor 2 botnon2+boton3
        if (!(PINB & 0x02) && !(PINB & 0x01)) {
            _delay_ms(100);
            if (A == 0) {
                PORTD &= ~0x0C;     // Apaga motor 2
                PORTD &= ~0xC0;     // Apaga motor 1
                _delay_ms(100);
                PORTD |= 0x40;      // Enciende PD6 (motor 1)
                PORTD &= ~0x80;     // Apaga PD7
                A = 1;
                B = 0;              // corta la otra condición
                C = 0;
                D = 0;
                E = 0;
                F = 0;

            }
        }
        else{ //si solo presiono el b2  se ejecuta lo anterior que va actvar ambos motoresm1 isquierda m2 derecha
            if (!(PINB & 0x02)) {
                _delay_ms(100);
                if (E == 0) {
    
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X40); //
                PORTD|=(0X08);//el pin4 en 1
                PORTD &= ~0x80;
                PORTD &= ~0x04;
    
                    B = 0;
                    C = 0;
                    D = 0;
                    A = 0;
                    E = 1;
                    F = 0;

    
                }
        }

        // Segunda condición  gira motor 2 apaga motor 1 boton1+boton2
        if (!(PINB & 0x01) && !(PIND & 0x20)) {
            _delay_ms(100);
            if (B == 0) {
                PORTD &= ~0x0C;     // Apaga motor 2
                PORTD &= ~0xC0;     // Apaga motor 1
                _delay_ms(100);
                PORTD |= 0x04;      // Enciende PD2 (motor 2)
                PORTD &= ~0x08;     // apaga PD3
                B = 1;
                C = 0;
                D = 0;
                E = 0;
                F = 0;
                A = 0;              // corta la otra condición
            }
        }
        
        else{ //si solo presiono el b1  van los dos hacia adedlante
            if (!(PINB & 0x01)) {
                _delay_ms(100);

                if (F == 0) {
    
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X04); //
                PORTD|=(0X40);//

    
                    B = 0;
                    C = 0;
                    D = 0;
                    A = 0;
                    E = 0;
                    F = 1;
                }
            }
        }
    
        //giro corto 1 m1 derecha m2 izquierda
        if (!(PIND & 0x20) && !(PINB & 0x02)) {
            _delay_ms(100);
            if (D == 0) {
                PORTD&=~(0X0C); 
                PORTD&=~(0XC0);
                _delay_ms(100); //abra un delay
                PORTD|=(0X80); //el motor 1 en 0
                PORTD|=(0X04);//el pin4 en 1
                
                B = 0;
                C = 0;
                D = 1;
                A = 0; 
                E = 0;
                F = 0;

            }
        }       

    }
}
}
        


            
        /* por arreglar
        if(!(PIND&0X50)){

            if(C==0){
            PORTD &= ~0xC0;     
            PORTD &= ~0x0C;
            _delay_ms(100);
            PORTD |= 0x08;      
            PORTD &= ~0x04;      
            PORTD |= 0x40;      
            PORTD &= ~0x80;
            B = 0;
                C = 1;
                A = 0;  
            }

*/
     



    
/*
//codigo funcional con 3 botones pero secuencial
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    DDRD|=(0XC0); //este sonl os pines para el control del motor 1
    PORTD&=~(0XC0);

    DDRD|=(0X0C); //motor 2
    PORTD&=~(0x0c);

    DDRB&=~(0X01); //del boton como entrada
    PORTB|=(0X01); //pull del boton
    DDRB&=~(0X02); //del boton como entrada
    PORTB|=(0X02); //pull del boton
    DDRD&=~(0X20); //del boton como entrada
    PORTD|=(0X20); //pull del boton

    char B=0; //variable de estado del sistema
    char C=0;
    char A=0;

    while(1){ //cadena de inico
    if(!(PINB&0x01)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos

        if (B == 0) {
            // Apagar Motor 1 
            PORTD &= ~0x0C;     // Apaga PD6 y PD7
            PORTD &= ~0xC0;
            _delay_ms(100);
            PORTD |= 0x80;    
            PORTD &= ~0x40;
            PORTD |= 0x04;    
            PORTD &= ~0x08;
            B = 1;
        } else {
            // Apagar Motor 2 
            PORTD &= ~0xC0;     
            PORTD &= ~0x0C;
            _delay_ms(100);
            PORTD |= 0x08;      
            PORTD &= ~0x04;      
            PORTD |= 0x40;      
            PORTD &= ~0x80;
            B = 0;
        }

    }
    if(!(PIND&0x20)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos


        if(A==0){
            PORTD|=0X80; //si esta en reposo se enciende el in2 
            PORTD&=~0X40;
            _delay_ms(100);
            PORTD|=0X08;
            PORTD&=~0X04;
            A=1; //estado 1
        }
        else{
                PORTD&=~(0XC0); //apagara el motor
                PORTD &=~(0X0C);
                _delay_ms(50);
                A=0; //vuelve al estado 0
            }
        }
    

    if(!(PINB&0x02)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos

        if (C == 0) {
            // Apagar Motor 1 (PD6/PD7), encender Motor 2 (PD4)
            PORTD &= ~0x0C;     // Apaga PD6 y PD7
            PORTD &= ~0xC0;
            _delay_ms(100);
            PORTD |= 0x40;      // motor 2 prendido apra adelante
            PORTD &= ~0x08;     // motor1 apagado
            C = 1;
        } else {
            // Apagar Motor 2 (PD4/PD5), encender Motor 1 (PD6)
            PORTD &= ~0xC0;     // Apaga PD4 y PD5
            PORTD &= ~0x0C;
            _delay_ms(100);
            PORTD |= 0x04;      // motor 1 prendido para atras
            PORTD &= ~0x80;     // motor 2 apagado
            C = 0;
        }
    }
}
}

*/

/*
//boton 3 para giro largo
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h> 

int main (void){
    DDRD|=(0XC0); //este sonl os pines para el control del motor 1
    PORTD&=~(0XC0);

    DDRD|=(0X0C); //motor 2
    PORTD&=~(0x0c);

    DDRB&=~(0X02); //del boton como entrada
    PORTB|=(0X02); //pull del boton

    char C=0; //variable de estado del sistema

    while(1){ //cadena de inico
    if(!(PINB&0x02)){ // cuando se pulsa el d5 se qda en 0 por eso se niega para volverlo 1
        _delay_ms(100); //evitar ruidos

        if (C == 0) {
            // Apagar Motor 1 (PD6/PD7), encender Motor 2 (PD4)
            PORTD &= ~0x0C;     // Apaga PD6 y PD7
            PORTD &= ~0xC0;
            _delay_ms(100);
            PORTD |= 0x40;      // PD4 ON (Motor 2)
            PORTD &= ~0x08;     // PD5 OFF
            C = 1;
        } else {
            // Apagar Motor 2 (PD4/PD5), encender Motor 1 (PD6)
            PORTD &= ~0xC0;     // Apaga PD4 y PD5
            PORTD &= ~0x0C;
            _delay_ms(100);
            PORTD |= 0x04;      // PD6 ON (Motor 1)
            PORTD &= ~0x80;     // PD7 OFF
            C = 0;
        }
    }
}
}
*/
/*
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

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
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