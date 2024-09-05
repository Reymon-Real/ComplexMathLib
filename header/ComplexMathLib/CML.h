/**
 * Esté archivo es parte de ComplexMathLib
 * 
 * Este archivo es de software libre: puedes redistribuir o modificar siempre y cuando
 * se cumplan los terminos de la CC0-1.0
 * 
 * */

#ifndef __CML_H__
#define __CML_H__
#include <stdio.h>
#include <math.h>

/**
 * Estructura que define los números complejosS
 * */
typedef struct NComplejos {
	double real;
	double img;
	double magt;
	double ang;
} complejo_t;

extern double suma(double num1, double num2);  // Función definida en ASM
extern double resta(double num1, double num2); // Función definida en ASM
extern double mult(double num1, double num2);  // Función definida en ASM
extern double divs(double num1, double num2);  // Función definida en ASM

void printf_complejo(complejo_t com); 			 // Función definida en C
void printf_complejo_imaginario(complejo_t com); // Función definida en C
void printf_complejo_real(complejo_t com);		 // Función definida en C

complejo_t init_complejo(double num1, double num2); // Función definida en C

complejo_t suma_complejos(complejo_t com1, complejo_t com2);  // Función definida en C
complejo_t resta_complejos(complejo_t com1, complejo_t com2); // Función definida en C

complejo_t suma_complejo_real(complejo_t com1, double real); // Función definida en C
complejo_t resta_complejo_real(complejo_t com1, double real); // Función definida en C

complejo_t mult_complejos(complejo_t com1, complejo_t com2); // Función definida en C
complejo_t divs_complejos(complejo_t com1, complejo_t com2); // Función definida en C

complejo_t mult_complejo_real(complejo_t com, double num); 			  // Función definida en C
complejo_t divs_complejo_real_denominador(complejo_t com, double num); // Función definida en C
complejo_t divs_complejo_real_numerador(complejo_t com, double num);  // Función definida en C

#endif