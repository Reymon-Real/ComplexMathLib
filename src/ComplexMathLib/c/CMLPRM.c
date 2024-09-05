#include <CMLPRM.h>

static double ang(complejo_t com) {
	com.ang = atan2(com.img, com.real) * (180.0 / M_PI);
	com.ang = fmod(com.ang, 360);
	if(com.ang < 0) com.ang += 360;
	return com.ang;
}

static double mag(complejo_t com) {
	return sqrt( pow(com.real, 2) + pow(com.img, 2) );
}

void magnitud(complejo_t* com) {
	com->magt = sqrt( pow(com->real, 2) + pow(com->img, 2) );
}

void conjugado(complejo_t* com) {
	com->img = com->img * -1;
}

void inverso(complejo_t* com) {
	com->real = (com->real / (pow(com->real, 2) + pow(com->img, 2)));
	com->img  = (com->img  / (pow(com->real, 2) + pow(com->img, 2)));
}

void angulo(complejo_t* com) {
	com->ang = atan2(com->img, com->real) * (180.0 / M_PI);
	com->ang = fmod(com->ang, 360);
	if(com->ang < 0) com->ang += 360;
}

complejo_t pow_complejo(complejo_t com, int64_t n) {
	return (complejo_t) { 
		pow( pow(com.real, 2) + pow(com.img, 2), n / 2 ), 
		pow(EULER_NUMBER, com.img * n * com.ang),
		mag(com),
		ang(com)
	};
}

complejo_t serie_de_taylor(complejo_t com) {
	return (complejo_t) { com.magt * (cos(com.ang)), com.magt * (sin(com.ang)) };
}