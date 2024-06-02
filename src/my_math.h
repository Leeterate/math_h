#ifndef SRC_MY_MATH_H_
#define SRC_MY_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define MY_M_PI \
  (double)3.1415926535897932384626433832795028841971693993751058209
#define MY_PI (double)3.1415926535897932384626433832795028841971693993751058209
#define MY_EXP \
  (long double)2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537
#define MY_EPS 1e-9

#define MY_INF 1.0 / 0.0  // 0x7f800000

#define MY_NAN 0.0 / 0.0

// Prototype by Ninetale
long double MY_acos(double x);
long double MY_asin(double x);
long double MY_atan(double x);
long double MY_fabs(double x);
long double MY_fmod(double x, double y);
long double MY_sqrt(double x);
// Prototype by Hazelnut
long double MY_sin(double x);
long double MY_cos(double x);
long double MY_tan(double x);
// Prototype by Barberry
int MY_abs(int x);
long double MY_exp(double x);
long double MY_log(double x);
long double MY_pow(double base, double exp);
// Prototype by Waresher
long double MY_ceil(double x);
long double MY_floor(double x);

#endif  // SRC_MY_MATH_H_
