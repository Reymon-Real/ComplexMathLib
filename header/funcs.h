#ifndef __FUNCS_H__
#define __FUNCS_H__
#include <stdio.h>


/**
 * Estructura que define los números complejosS
 * */
typedef struct NComplejos {
	double real;
	double img;
} complejo_t;

extern double suma(double num1, double num2);  // Función definida en ASM
extern double resta(double num1, double num2); // Función definida en ASM
extern double mult(double num1, double num2);  // Función definida en ASM
extern double divs(double num1, double num2);  // Función definida en ASM

void printf_complejo(complejo_t com); 			 // Función definida en C
void printf_complejo_imaginario(complejo_t com); // Función definida en C
void printf_complejo_real(complejo_t com);		 // Función definida en C

complejo_t init_complejos(double num1, double num2); // Función definida en C

complejo_t suma_complejos(complejo_t com1, complejo_t com2);  // Función definida en C
complejo_t resta_complejos(complejo_t com1, complejo_t com2); // Función definida en C

complejo_t suma_complejo_real(complejo_t com1, double real); // Función definida en C
complejo_t resta_complejo_real(complejo_t com1, complejo_t com2); // Función definida en C

complejo_t mult_complejos(complejo_t com1, complejo_t com2); // Función definida en C
complejo_t divs_complejos(complejo_t com1, complejo_t com2); // Función definida en C

complejo_t mult_complejo_real(complejo_t com, double num); // Función definida en C
complejo_t divs_complejo_numero(complejo_t com, double num); // Función definida en C

#endif