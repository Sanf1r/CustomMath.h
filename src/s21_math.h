#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define NaN 0.0 / 0.0
#define PLUS_INF 1.0 / 0.0
#define MINUS_INF -1.0 / 0.0
#define S21_PRECISION 1e-20
#define S21_EXP 2.7182818284590452353602874713527
#define S21_PI 3.14159265358979323846264338327950288

int s21_abs(int x);
long double s21_fabs(double x);
int s21_isnan(long double x);
int s21_isinf(long double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_factorial(int number);
long double s21_powforexp(long double x, long double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_sin_handler(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

#endif  // SRC_S21_MATH_H_
