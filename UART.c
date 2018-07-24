#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "avrpin.h"

void initUSART( unsigned int ubrr){
	UBRR0H=(ubrr>>8);
	UBRR0L=ubrr;
	UCSR0B|=(1<<TXEN0);
	//UCSR0B|=(1<<TXCIE0);
	//LOS BIT UMSEL0 POR DEFENTO INDICAN UNA TRANSMISION ASINCRENA EN 00
	//LOS BIT UPM0 POR DEFECTO INDICAN UNA TRANSMISIÓN SIN PARIDAD
	//EL BIT USBS0 SE CONFIGURA CON 1 PARA UNA TRANSMISIÓN CON DOS BITS DE PARADA
	UCSR0C|=(0<<USBS0);
	UCSR0C|=(3<<UCSZ00);
	}

void TxData (unsigned char salida){
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0=salida;
		
}
