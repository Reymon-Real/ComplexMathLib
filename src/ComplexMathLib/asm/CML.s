/**
 * Esté archivo es parte de ComplexMathLib
 * 
 * Este archivo es de software libre: puedes redistribuir o modificar siempre y cuando
 * se cumplan los terminos de la CC0-1.0
 * 
 * */

.intel_syntax noprefix

.globl suma, resta, mult, divs

.def suma;  .scl 3; .type 32; .endef
.def resta; .scl 3; .type 32; .endef
.def mult;  .scl 3; .type 32; .endef
.def divs;  .scl 3; .type 32; .endef

.section .rdata,"dr"
    msg:.asciz "Zero Division"
    error:.string "%s"

.section .text
    .seh_proc suma                      # Le indicamos al compilador la excepción de que comienza la etiqueta suma
    suma:                               # Inicio de la etiqueta suma
        movsd xmm0, xmm0                # Movemos el valor ingersado por xmm0 a xmm0
        addsd xmm0, xmm1                # Le sumamos el valor del segundo parámetro pasado por xmm1
        ret                             # Retornamos a la dirección de memoria donde llamamos a la función
    .seh_endproc                        # Le indicamos al compilador la exepción de que termino la etiqueta suma
    
    .seh_proc resta                     # Le indicamos al compilador la excepción de que comienza la etiqueta resta
    resta:                              # Inicio de la etiqueta resta
        movsd xmm0, xmm0                # Movemos el valor ingersado por xmm0 a xmm0
        subsd xmm0, xmm1                # Le resta el valor del segundo parámetro pasado por xmm1
        ret                             # Volvemos a donde fue invocada la función
    .seh_endproc                        # Le indicamos al compilador la exepción de que termino la etiqueta resta

    .seh_proc mult                      # Le indicamos al compilador la excepción de que comienza la etiqueta mult
    mult:                               # Inicio de la etiqueta mult
        push rbp                        # Guardamos el valor original de rbp
        .seh_pushreg rbp                # Excepción que indica que guardamos el valor de rbp
        sub rsp, 16                     # Reservamos 16 de pila
        .seh_stackalloc 16              # Excepción que indica que reservamos 16 de pila
        mov rbp, rsp                    # Hacemos que rbp apunte a rsp
        .seh_setframe rbp, 16           # Excepción que indica que rbp va a usar 16 de pila
        .seh_endprologue                # Excepción que indica que temrinamos las configuraciones básicas
        movsd xmm0, xmm0                # Movemos el valor ingersado por xmm0 a xmm0
        movsd qword ptr 16[rbp], xmm1   # Guardamos el valor del segundo parámetro en la pila 16[rbp]
        imul qword ptr 16[rbp]          # Le multiplicamos el valor almacenado en 16[rbp]
        add rsp, 16                     # Liberamos la pila utilizada
        pop rbp                         # Le devolvemos el valor original a rbp
        ret                             # Retornamos a la dirección de memoria donde llamamos a la función
    .seh_endproc                        # Le indicamos al compilador la exepción de que termino la etiqueta mult

    .seh_proc divs                      # Le indicamos al compilador la excepción de que comienza la etiqueta divs
    divs:                               # Inicio de la etiqueta divs
        push rbp                        # Guardamos el valor original de rbp
        .seh_pushreg rbp                # Excepción que indica que guardamos el valor de rbp
        sub rsp, 16                     # Reservamos 16 de pila
        .seh_stackalloc 16              # Excepción que indica que reservamos 16 de pila
        mov rbp, rsp                    # Hacemos que rbp apunte a rsp
        .seh_setframe rbp, 16           # Excepción que indica que rbp va a usar 16 de pila
        .seh_endprologue                # Excepción que indica que temrinamos las configuraciones básicas
        movsd xmm0, xmm0                # Movemos el valor ingersado por xmm0 a xmm0
        movsd qword ptr 16[rbp], xmm1   # Guardamos el valor del segundo parámetro en la pila 16[rbp] 
        cmp qword ptr 16[rbp], 0        # Verificamos que no sea una división con denominador cero
        je error_cero                   # Si el denominador es cero, saltamos a la etiqueta de error_cero
        idiv qword ptr 16[rbp]          # Dividimos el valor en xmm0 por el valor en 16[rbp] y el resultado se almacena en xmm0
        add rsp, 16                     # Liberamos la pila utilizada
        pop rbp                         # Le dolvemos a rbp su valor original
        ret                             # Retornamos a la dirección de memoria donde llamamos a la función
    .seh_endproc                        # Le indicamos al compilador la exepción de que termino la etiqueta divs

    .seh_proc error_cero                # Le indicamos al compilador la excepción de que comienza la etiqueta error_cero
    error_cero:                         # Inicio de la etiqueta error_cero
        mov rcx, error[rip]             # Movemos el valor "%s" al primer parámetro de la función printf
        mov rdx, msg[rip]               # Movemos el mensaje de error almacenado en msg al segundo parámetro de la función que es rdx
        call printf                     # Llamamos a la función printf
        add rsp, 16                     # Liberamos la pila reservada para que no haya lagunas
        pop rbp                         # Le devolvemos el valor original a rbp para que no haya problemas
        ret                             # Retornamos a la dirección de memoria donde llamamos a la función
    .seh_endproc                        # Le indicamos al compilador la exepción de que termino la etiqueta error_cero
