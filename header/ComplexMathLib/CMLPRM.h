#ifndef __CMLPRM_H__
#define __CMLPRM_H__
#include <CML.h>
#include <CML_utils.h>
#include <stdint.h>
#include <math.h>

void magnitud(complejo_t* com);
void conjugado(complejo_t* com);
void inverso(complejo_t* com);
void angulo(complejo_t* com);
complejo_t pow_complejo(complejo_t com, int64_t n);
complejo_t serie_de_taylor(complejo_t com);

#endif