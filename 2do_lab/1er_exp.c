#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"

unsigned contador = 0;  // Variable contador 
//funcion con la configuracion de puertos
void fun_puertos() {
    DDRB |= 0x0F; //xxxx 1111 B0-B3 Salidas
    DDRD = (DDRD & 0x03) | 0xF0; //1111 00xx D2-D3 entradas D4-D7 Salidas 
}
//funcion con la configuracion de inicialisacion
void fun_init() {
    PORTB &= ~(1<<0); //PB0 inicializado en 0.
    PORTD |= (1 << PD3); // Pull-up en PD3
    PORTD |= (1 << PD2); // Pull-up en PD2
}
//funcion con la configuracion de interrupciones
void fun_interrupsiones() {
    EICRA = 0b00001010; //Interrupción externa por flanco de bajada en INT0 e INT1
    EIMSK = 0b00000011; //Habilita interrupción externa en INT0 y INT1
    EIFR = 0b00000000; //Bajamos Bandera de interrupción a cero.
    sei(); //Habilitar Interrupciones globales
}

//Interrupción por flanco de bajada en INT1
ISR(INT1_vect) {
    contador++; // Incrementa el contador cuando hay una interrupcion en INT1
}

//Interrupción por flanco de bajada en INT0
ISR(INT0_vect) {
    contador--; // Decrementa el contador cuando hay una interrupcion en INT0
}

//-------------------- Main Program -------------------------
int main(void) {
    fun_puertos();
    fun_init();
    fun_interrupsiones();
    while(1) {
        // Actualizar los puertos con el valor del contador
        PORTD = (PORTD & 0x0F) | ((contador & 0x0F) << 4);
        PORTB = (PORTB & 0xF0) | ((contador & 0xF0) >> 4);
    }
}
