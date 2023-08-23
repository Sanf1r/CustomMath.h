#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_math.h"

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_abs_test) {
  int num = 30;
  int orig = 0;
  int my = 0;

  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = -30;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = 0;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = -1;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = 1;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = INT_MAX;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = INT_MIN;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = NaN;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = PLUS_INF;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);

  num = MINUS_INF;
  my = s21_abs(num);
  orig = abs(num);
  ck_assert_int_eq(orig, my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_fabs_test) {
  double num = 2.5;
  long double orig = 0;
  long double my = 0;

  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = 1839.9349939;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = -1839.9939293;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = 2.5;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = -0.99932038848;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = +0.99;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_eq(orig, my);

  num = NaN;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = PLUS_INF;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);

  num = MINUS_INF;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);

  num = 89477583892;
  orig = fabs(num);
  my = s21_fabs(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_fmod_test) {
  double num = 0;
  double num1 = 0;
  double orig = 0;
  double my = 0;

  num = 51515.5;
  num1 = 98;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 50;
  num1 = 98;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 0;
  num1 = 98;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = -51840;
  num1 = 98;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = -21561860;
  num1 = -9800;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 21561860;
  num1 = -9800;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 0;
  num1 = 15151;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = -1510;
  num1 = 15151;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 3;
  num1 = 0;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_nan(orig);
  ck_assert_float_nan(my);

  num = 3;
  num1 = PLUS_INF;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_eq(orig, my);

  num = 3;
  num1 = NaN;
  my = s21_fmod(num, num1);
  orig = fmod(num, num1);
  ck_assert_float_nan(orig);
  ck_assert_float_nan(my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_ceil_test) {
  double num = 2.5;
  long double orig = 0;
  long double my = 0;

  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = 1839.9349939;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = -1839.9939293;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = 2.5;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = -0.99932038848;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = +0.99;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_eq(orig, my);

  num = NaN;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = MINUS_INF;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);

  num = PLUS_INF;
  orig = ceil(num);
  my = s21_ceil(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_floor_test) {
  double num = 2.5;
  long double orig = 0;
  long double my = 0;

  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = 1839.9349939;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = -1839.9939293;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = 2.5;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = -0.99932038848;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = +0.99;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_eq(orig, my);

  num = NaN;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = PLUS_INF;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);

  num = MINUS_INF;
  orig = floor(num);
  my = s21_floor(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_exp_test) {
  double num = 0;
  double orig = 0;
  double my = 0;

  num = 23;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = MINUS_INF;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq(orig, my);

  num = PLUS_INF;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq(orig, my);

  num = NaN;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_nan(orig);
  ck_assert_double_nan(my);

  num = 45;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 0.00551;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -0.00551;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 0;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 595;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -22;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -4.595486;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -1;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 1;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 1.9;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -1.91;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -8.5545;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = -7.4545;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq_tol(orig, my, 1e-6);

  num = 4394865.595486;
  my = s21_exp(num);
  orig = exp(num);
  ck_assert_double_eq(orig, my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_log_test) {
  double num = 5.5;
  long double my = 0;
  long double orig = 0;

  orig = log(num);
  my = s21_log(num);
  ck_assert_float_eq(my, orig);

  num = 3929304.93499232;
  orig = log(num);
  my = s21_log(num);
  ck_assert_float_eq(my, orig);

  num = 0.932;
  orig = log(num);
  my = s21_log(num);
  ck_assert_float_eq(my, orig);

  num = 39944883929304.93499232;
  orig = log(num);
  my = s21_log(num);
  ck_assert_float_eq(my, orig);

  num = PLUS_INF;
  orig = log(num);
  my = s21_log(num);
  ck_assert_float_eq(my, orig);

  num = NaN;
  orig = log(num);
  my = s21_log(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = -4.93499232;
  orig = log(num);
  my = s21_log(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = 0.0;
  orig = log(num);
  my = s21_log(num);
  ck_assert_ldouble_infinite(my);
  ck_assert_ldouble_infinite(orig);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_pow_test) {
  double num = 5.5;
  long double my = 0;
  long double orig = 0;

  orig = pow(num, 0);
  my = s21_pow(num, 0);
  ck_assert_float_eq(orig, my);

  orig = pow(num, -1);
  my = s21_powforexp(num, -1);
  ck_assert_float_eq(orig, my);

  num = 0.0;
  orig = pow(num, 1);
  my = s21_pow(num, 1);
  ck_assert_float_eq(orig, my);

  num = -0.0;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = -0.0;
  orig = pow(num, 2);
  my = s21_pow(num, 2);
  ck_assert_float_eq(orig, my);

  num = -0.0;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = 0.5;
  orig = pow(num, MINUS_INF);
  my = s21_pow(num, MINUS_INF);
  ck_assert_float_eq(orig, my);

  num = 2;
  orig = pow(num, MINUS_INF);
  my = s21_pow(num, MINUS_INF);
  ck_assert_float_eq(orig, my);

  num = 0.5;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = 2;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = 0;
  orig = pow(num, -2);
  my = s21_pow(num, -2);
  ck_assert_float_eq(orig, my);

  num = 0;
  orig = pow(num, 2);
  my = s21_pow(num, 2);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = pow(num, 1.5);
  my = s21_pow(num, 1.5);
  ck_assert_float_nan(orig);
  ck_assert_float_nan(my);

  num = MINUS_INF;
  orig = pow(num, -2);
  my = s21_pow(num, -2);
  ck_assert_float_eq(orig, my);

  num = MINUS_INF;
  orig = pow(num, 2.5);
  my = s21_pow(num, 2.5);
  ck_assert_float_eq(orig, my);

  num = MINUS_INF;
  orig = pow(num, 2);
  my = s21_pow(num, 2);
  ck_assert_float_eq(orig, my);

  num = PLUS_INF;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = MINUS_INF;
  orig = pow(num, -2);
  my = s21_pow(num, -2);
  ck_assert_float_eq(orig, my);

  num = 0;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = pow(num, PLUS_INF);
  my = s21_pow(num, PLUS_INF);
  ck_assert_float_eq(orig, my);

  num = 3923984;
  orig = pow(num, 392.994);
  my = s21_pow(num, 392.994);
  ck_assert_float_eq(orig, my);

  num = -3923984;
  orig = pow(num, -4);
  my = s21_pow(num, -4);
  ck_assert_float_eq(orig, my);

  num = NaN;
  orig = pow(num, 3);
  my = s21_pow(num, 3);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = PLUS_INF;
  orig = pow(num, 3);
  my = s21_pow(num, 3);
  ck_assert_ldouble_infinite(my);
  ck_assert_ldouble_infinite(orig);

  num = MINUS_INF;
  orig = pow(num, 3);
  my = s21_pow(num, 3);
  ck_assert_ldouble_infinite(my);
  ck_assert_ldouble_infinite(orig);

  num = 4588394;
  orig = pow(num, 3.994);
  my = s21_pow(num, 3.994);
  ck_assert_float_eq(orig, my);

  num = 4588394;
  orig = pow(num, 0);
  my = s21_pow(num, 0);
  ck_assert_float_eq(orig, my);

  num = 4588394;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = FLT_MAX;
  orig = pow(num, -FLT_MAX);
  my = s21_pow(num, -FLT_MAX);
  ck_assert_float_eq(orig, my);

  num = DBL_MAX;
  orig = pow(num, -DBL_MAX);
  my = s21_pow(num, -DBL_MAX);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = +1;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = pow(num, -1);
  my = s21_pow(num, -1);
  ck_assert_float_eq(orig, my);

  num = -9;
  orig = pow(num, -19);
  my = s21_pow(num, -19);
  ck_assert_float_eq(orig, my);

  num = MINUS_INF;
  orig = pow(num, -39);
  my = s21_pow(num, -39);
  ck_assert_float_eq(orig, my);

  num = (0);
  orig = pow(num, MINUS_INF);
  my = s21_pow(num, MINUS_INF);
  ck_assert_ldouble_infinite(my);
  ck_assert_ldouble_infinite(orig);

  num = PLUS_INF;
  orig = pow(num, 39);
  my = s21_pow(num, 39);
  ck_assert_ldouble_infinite(my);
  ck_assert_ldouble_infinite(orig);

  num = NaN;
  orig = pow(num, 39);
  my = s21_pow(num, 39);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = NaN;
  orig = pow(num, 0);
  my = s21_pow(num, 0);
  ck_assert_float_eq(orig, my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_sqrt_test) {
  double num = 5.5;
  long double my = 0;
  long double orig = 0;

  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = 4994823;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = -0.0;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = -100;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_nan(orig);
  ck_assert_float_nan(my);

  num = FLT_MAX / 2;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = 0;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = 1;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_float_eq(orig, my);

  num = NaN;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = PLUS_INF;
  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);

  orig = sqrt(num);
  my = s21_sqrt(num);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_sin_test) {
  double num = 5.5;
  long double my = 0;
  long double orig = 0;

  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = 100;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = -100;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = 5555;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = -5555;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = NaN;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = PLUS_INF;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = MINUS_INF;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(my);

  num = 0;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = -1;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);

  num = +1;
  orig = sin(num);
  my = s21_sin(num);
  ck_assert_float_eq(orig, my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_cos_test) {
  double num = 0;
  double orig = 0;
  double my = 0;

  num = -1;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 1;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 0.84561;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = -0.84561;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 0.551564;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = -0.54568;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 0.26568;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = -0.2545;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 8;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = -8;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 25158;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = -8848;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 0;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = 150;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_float_eq(orig, my);

  num = NaN;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = PLUS_INF;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = MINUS_INF;
  my = s21_cos(num);
  orig = cos(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_tan_test) {
  double num = 5.5;
  long double my = 0;
  long double orig = 0;

  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = 3994.0;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = -3994.0;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = -3994.4993828384;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = -9490.49283828384;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = 8449.49993828384;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);

  num = NaN;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = PLUS_INF;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = MINUS_INF;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = 8436;
  my = s21_tan(num);
  orig = tan(num);
  ck_assert_float_eq(my, orig);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_atan_test) {
  double num = 0;
  double orig = 0;
  double my = 0;

  num = -1;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 1;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 0.84561;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = -0.84561;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 0.551564;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 526;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = -568;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 51.595;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = -51.595;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = 0;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);

  num = FLT_MAX;
  my = s21_atan(num);
  orig = atan(num);
  ck_assert_float_eq(orig, my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_asin_test) {
  double num = 0;
  double orig = 0;
  double my = 0;

  num = -1;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 1;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 0.84561;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = -0.84561;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 0.551564;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = -0.54568;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 0.26568;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = -0.2545;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 0;
  my = s21_asin(num);
  orig = asin(num);
  ck_assert_float_eq(orig, my);

  num = 8;
  my = s21_asin(num);
  ck_assert_ldouble_nan(my);

  num = -8;
  my = s21_asin(num);
  ck_assert_ldouble_nan(my);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

START_TEST(s21_acos_test) {
  double num = 0;
  double orig = 0;
  double my = 0;

  num = -1;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 1;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 0.84561;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = -0.84561;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 0.551564;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = -0.54568;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 0.26568;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = -0.2545;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 0;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_float_eq(orig, my);

  num = 8;
  my = s21_acos(num);
  ck_assert_ldouble_nan(my);

  num = -8;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);

  num = NaN;
  my = s21_acos(num);
  orig = acos(num);
  ck_assert_ldouble_nan(my);
  ck_assert_ldouble_nan(orig);
}
END_TEST

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

void tests_part1(TCase *tc1_1) {
  tcase_add_test(tc1_1, s21_abs_test);
  tcase_add_test(tc1_1, s21_fabs_test);
  tcase_add_test(tc1_1, s21_fmod_test);
  tcase_add_test(tc1_1, s21_ceil_test);
  tcase_add_test(tc1_1, s21_floor_test);
  tcase_add_test(tc1_1, s21_exp_test);
  tcase_add_test(tc1_1, s21_log_test);
  tcase_add_test(tc1_1, s21_pow_test);
  tcase_add_test(tc1_1, s21_sqrt_test);
}

void tests_part2(TCase *tc1_1) {
  tcase_add_test(tc1_1, s21_sin_test);
  tcase_add_test(tc1_1, s21_cos_test);
  tcase_add_test(tc1_1, s21_tan_test);
  tcase_add_test(tc1_1, s21_atan_test);
  tcase_add_test(tc1_1, s21_asin_test);
  tcase_add_test(tc1_1, s21_acos_test);
}

// WOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOWWOW

int main(void) {
  Suite *s1 = suite_create("s21_tests");
  TCase *tc1_1 = tcase_create("s21_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tests_part1(tc1_1);
  tests_part2(tc1_1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
