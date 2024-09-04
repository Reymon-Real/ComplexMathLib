/**
 * Esté archivo es parte de ComplexMathLib
 * 
 * Este archivo es de software libre: puedes redistribuir o modificar siempre y cuando
 * se cumplan los terminos de la CC0-1.0
 * 
 * */

#include <CML.h>

/**
 * Inicializa el número complejo
 * 
 * Sintaxis:
 * complejo_t numero = init_complejo(real, imaginario);
 */
complejo_t init_complejo(double num1, double num2) {
	return (complejo_t) { num1, num2 };
}

/**
 * Imprime el valor de números complejos
 * 
 * Sintaxis:
 * printf_complejo(complejo);
 * */
void printf_complejo_real(complejo_t com) {
	printf("%.2f\n", com.real);
}

/**
 * Imprime el valor de números complejos
 * 
 * Sintaxis:
 * printf_complejo(complejo);
 * */
void printf_complejo_imaginario(complejo_t com) {
	printf("%.2fi\n", com.img);
}

/**
 * Imprime el valor de números complejos
 * 
 * Sintaxis:
 * printf_complejo(complejo);
 * */
void printf_complejo(complejo_t com) {
	printf("%.2f + %.2fi\n", com.real, com.img);
}

/**
 * Suma dos números complejos
 * 
 * Formula: (a1 + a2) + i(b1 + b2)
 * 
 * Sintaxis:
 * complejo_t complejo_3 = suma_complejos(complejo_1, complejo_2);
 */
complejo_t suma_complejos(complejo_t com1, complejo_t com2) {
	return (complejo_t) { suma(com1.real, com2.real), suma(com1.img, com2.img) };
}

/**
 * Suma un número complejo con uno real
 * 
 * Formula: (a + real) + bi
 * 
 * Sintaxis:
 * complejo_t complejo_3 = suma_complejo_real(complejo_1, real);
 */
complejo_t suma_complejo_real(complejo_t com1, double real) {
	return (complejo_t) { suma(com1.real, real) };
}

/**
 * Resta dos números complejos
 * 
 * Formula: (a1 - a2) + i(b1 - b2)
 * 
 * Sintaxis:
 * complejo_t complejo_3 = resta_complejos(complejo_1, complejo_2);
 */
complejo_t resta_complejos(complejo_t com1, complejo_t com2) {
	return (complejo_t) { resta(com1.real, com2.real), resta(com2.img, com2.img) };
}

/**
 * Resta un número complejo con uno real
 * 
 * Formula: (a - real) + bi
 * 
 * Sintaxis:
 * complejo_t complejo_3 = suma_complejo_real(complejo_1, real);
 */
complejo_t resta_complejo_real(complejo_t com1, double real) {
	return (complejo_t) { resta(com1.real, real) };
}


/**
 * Multiplica dos números complejos
 * 
 * Formula: (a1 * a2 - b1 * b2) + i(a1 * b2 + b1 * a2)
 * 
 * Sintaxis:
 * complejo_t complejo_3 = mult_complejos(complejo_1, complejo_2);
 */
complejo_t mult_complejos(complejo_t com1, complejo_t com2) {
	return (complejo_t) { 
		resta( mult(com1.real, com2.real), mult(com1.img, com2.img) ),
		suma( mult(com1.real, com2.img), mult(com1.img, com2.real) )
		};
}

/**
 * Multiplica un número complejo por un número dado
 * 
 * Formula: (a1 * número) + i(b1 * número)
 * 
 * Sintaxis:
 * complejo_t complejo_2 = mult_complejo_real(complejo_1, número);
 */
complejo_t mult_complejo_real(complejo_t com, double num) {
	return (complejo_t) { mult(com.real, num), mult(com.img, num) };
}

/**
 * Divide dos números complejos
 * 
 * Formula: ((a1 * a2 + b1 * b2) + i(b1 * a2 - a1 * b2)) / a^2 + b^2
 * 
 * Sintaxis:
 * complejo_t complejo_3 = divs_complejos(complejo_1, complejo_2);
 */
complejo_t divs_complejos(complejo_t com1, complejo_t com2) {
	return (complejo_t) { 
		divs( suma( mult(com1.real, com2.real), mult(com1.img, com2.img) ), 
		suma( mult(com2.real, com2.real), mult(com2.img, com2.img) ) ),

		divs( resta( mult(com1.real, com2.img), mult(com2.real, com1.img) ), 
		suma( mult(com2.real, com2.real), mult(com2.img, com2.img) ) )
	};
}

/**
 * Divide un número complejo por un número real en el denominador
 * 
 * Fórmula: (a + b) / c
 * 
 * Sintaxis:
 * complejo_t complejo_2 = divs_complejo_real_denominador(complejo_1, número);
 */
complejo_t divs_complejo_real_denominador(complejo_t com, double num) {
	return (complejo_t) { divs(com.real, num), mult(com.img, num) };
}

/**
 * Divide un número complejo por un número real en el denominador
 * 
 * Fórmula: c(a - bi) / a^2 + b^2
 * 
 * Sintaxis:
 * complejo_t complejo_2 = divs_complejo_real_numerador(complejo_1, número);
 */
complejo_t divs_complejo_real_numerador(complejo_t com, double num) {
	return (complejo_t) { 
	divs( mult(com.real, num), suma( mult(com.real, com.real), mult(com.img, com.img) ) ),
	divs( mult(com.img, num), suma( mult(com.real, com.real), mult(com.img, com.img) ) ),
	 };
}