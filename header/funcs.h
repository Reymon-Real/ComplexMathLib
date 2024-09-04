#ifndef __FUNCS_H__
#define __FUNCS_H__
#include <stdio.h>

typedef struct NComplejos {
	double real;
	double img;
} complejo_t;

extern double suma(double num1, double num2);
extern double resta(double num1, double num2);
extern double mult(double num1, double num2);
extern double divs(double num1, double num2);

void printf_complejo(complejo_t com);
void printf_complejo_imaginario(complejo_t com);
void printf_complejo_real(complejo_t com);

complejo_t init_complejos(double num1, double num2);

complejo_t suma_complejos(complejo_t com1, complejo_t com2);
complejo_t resta_complejos(complejo_t com1, complejo_t com2);

complejo_t mult_complejos(complejo_t com1, complejo_t com2);
complejo_t divs_complejos(complejo_t com1, complejo_t com2);

complejo_t mult_complejo_numero(complejo_t com, double num);
complejo_t divs_complejo_numero(complejo_t com, double num);

#endif