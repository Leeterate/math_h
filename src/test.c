#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "my_math.h"

START_TEST(test_MY_abs) {
  ck_assert_int_eq(MY_abs(21), abs(21));
  ck_assert_int_eq(MY_abs(-21), abs(-21));
  ck_assert_int_eq(MY_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(MY_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(MY_abs(-0), abs(-0));
  ck_assert_int_eq(MY_abs(+0), abs(+0));
  ck_assert_int_eq(MY_abs(0), abs(0));
}
END_TEST

START_TEST(test_MY_acos) {
  // Test 1
  double num = 0.55;
  long double orig_res = acos(num), our_res = MY_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 4
  double num3 = MY_INF;
  long double orig_res3 = acos(num3), our_res3 = MY_acos(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 5
  double num4 = -MY_INF;
  long double orig_res4 = acos(num4), our_res4 = MY_acos(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 6
  double num5 = MY_NAN;
  long double orig_res5 = MY_acos(num5), our_res5 = acos(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 7
  ck_assert_ldouble_nan(MY_acos(MY_NAN));
  ck_assert_ldouble_nan(acos(MY_NAN));
  // Test 8
  ck_assert_ldouble_eq_tol(MY_acos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(MY_acos(-1.0), acos(-1.0), MY_EPS);
  // Test 9
  ck_assert_ldouble_eq_tol(MY_acos(0.0), acos(0.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_acos(-0.0), acos(-0.0), MY_EPS);
  // Test 10
  ck_assert_ldouble_eq_tol(MY_acos(-1), acos(-1), MY_EPS);
  // Test 11
  ck_assert_ldouble_eq_tol(MY_acos(1), acos(1), MY_EPS);
  // Test 12
  ck_assert_ldouble_eq_tol(MY_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), MY_EPS);
  // Test 13
  ck_assert_ldouble_eq_tol(MY_acos(-sqrt(2) / 2), acos(-sqrt(2) / 2), MY_EPS);
  // Test 14
  ck_assert_ldouble_eq_tol(MY_acos(-1 / 2), acos(-1 / 2), MY_EPS);
  // Test 15
  ck_assert_ldouble_eq_tol(MY_acos(1 / 2), acos(1 / 2), MY_EPS);
  // Test 16
  ck_assert_ldouble_eq_tol(MY_acos(1), acos(1), MY_EPS);
  // Test 17
  ck_assert_ldouble_eq_tol(MY_acos(sqrt(2) / 2), acos(sqrt(2) / 2), MY_EPS);
  // Test 18
  ck_assert_ldouble_eq_tol(MY_acos(sqrt(3) / 2), acos(sqrt(3) / 2), MY_EPS);
}
END_TEST

START_TEST(test_MY_asin) {
  double num = 0.55;
  long double orig_res = asin(num), our_res = MY_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  double num1 = -0.99;
  long double orig_res1 = asin(num1), our_res1 = MY_asin(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 3
  double num3 = MY_INF;
  long double orig_res3 = asin(num3), our_res3 = MY_asin(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 4
  double num4 = -MY_INF;
  long double orig_res4 = asin(num4), our_res4 = MY_asin(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 5
  double num5 = MY_NAN;
  long double orig_res5 = asin(num5), our_res5 = MY_asin(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 9
  ck_assert_ldouble_eq_tol(MY_asin(1.0), asin(1.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_asin(-1.0), asin(-1.0), MY_EPS);
  // Test 10
  ck_assert_ldouble_eq_tol(MY_asin(0.0), asin(0.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_asin(-0.0), asin(-0.0), MY_EPS);
  // Test 11
  ck_assert_ldouble_eq_tol(MY_asin(0.0), asin(0.0), MY_EPS);
  // Test 12
  ck_assert_ldouble_eq_tol(MY_asin(-1), asin(-1), MY_EPS);
  // Test 13
  ck_assert_ldouble_eq_tol(MY_asin(1), asin(1), MY_EPS);
  // Test 14
  ck_assert_ldouble_eq_tol(MY_asin(-sqrt(3) / 2), asin(-sqrt(3) / 2), MY_EPS);
  // Test 15
  ck_assert_ldouble_eq_tol(MY_asin(-sqrt(2) / 2), asin(-sqrt(2) / 2), MY_EPS);
  // Test 16
  ck_assert_ldouble_eq_tol(MY_asin(-1 / 2), asin(-1 / 2), MY_EPS);
  // Test 17
  ck_assert_ldouble_eq_tol(MY_asin(1 / 2), asin(1 / 2), MY_EPS);
  // Test 19
  ck_assert_ldouble_eq_tol(MY_asin(sqrt(2) / 2), asin(sqrt(2) / 2), MY_EPS);
  // Test 20
  ck_assert_ldouble_eq_tol(MY_asin(sqrt(3) / 2), asin(sqrt(3) / 2), MY_EPS);
}
END_TEST

START_TEST(test_MY_atan) {
  ck_assert_float_eq(MY_atan(-15.01), atan(-15.01));
  // Test 1
  double num = -0.99;
  long double orig_res = MY_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
  ck_assert_float_eq(-9999999999, -9999999999);
  double num1 = MY_NAN;
  long double orig_res1 = MY_atan(num1), our_res1 = atan(num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  ck_assert_ldouble_nan(MY_atan(MY_NAN));
  ck_assert_ldouble_nan(atan(MY_NAN));
  // Test 7
  ck_assert_ldouble_eq_tol(MY_atan(1.0), atan(1.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_atan(1.1), atan(1.1), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_atan(-1.0), atan(-1.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_atan(-1.1), atan(-1.1), MY_EPS);
  // Test 8
  ck_assert_ldouble_eq_tol(MY_atan(0.0), atan(0.0), MY_EPS);
  ck_assert_ldouble_eq_tol(MY_atan(-0.0), atan(-0.0), MY_EPS);
  // Test 9
  ck_assert_ldouble_eq_tol(MY_atan(-1), atan(-1), MY_EPS);
  // Test 10
  ck_assert_ldouble_eq_tol(MY_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), MY_EPS);
  // Test 11
  ck_assert_ldouble_eq_tol(MY_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), MY_EPS);
  // Test 12
  ck_assert_ldouble_eq_tol(MY_atan(-1 / 2), atan(-1 / 2), MY_EPS);
  // Test 13
  ck_assert_ldouble_eq_tol(MY_atan(1 / 2), atan(1 / 2), MY_EPS);
  // Test 14
  ck_assert_ldouble_eq_tol(MY_atan(1), atan(1), MY_EPS);
  // Test 15
  ck_assert_ldouble_eq_tol(MY_atan(sqrt(3) / 2), atan(sqrt(3) / 2), MY_EPS);
  // Test 16
  ck_assert_ldouble_eq_tol(MY_atan(1), atan(1), MY_EPS);
  // Test 17
  ck_assert_ldouble_eq_tol(MY_atan(1.23456e-7), atan(1.23456e-7), MY_EPS);
  // Test 18
  ck_assert_ldouble_eq_tol(MY_atan(2.1234567), atan(2.1234567), MY_EPS);
  // Test 19
  ck_assert_ldouble_eq_tol(MY_atan(2.1234567e-7), atan(2.1234567e-7), MY_EPS);
  // Test 20
  ck_assert_ldouble_eq_tol(MY_atan(2.1234567e-16), atan(2.1234567e-16),
                           MY_EPS);
  // Test 21
  ck_assert_float_nan(MY_atan(MY_NAN));
}
END_TEST

START_TEST(test_MY_ceil) {
  ck_assert_ldouble_nan(MY_ceil(MY_NAN));
  ck_assert_ldouble_nan(ceil(MY_NAN));
  ck_assert_ldouble_eq(MY_ceil(-15.01), ceil(-15.01));
  // Test 1
  ck_assert_ldouble_eq(MY_ceil(15.01), ceil(15.01));
  // Test 2
  ck_assert_ldouble_eq(MY_ceil(MY_INF), ceil(MY_INF));
  // Test 3
  ck_assert_ldouble_eq(MY_ceil(-MY_INF), ceil(-MY_INF));
  // Test 4
  ck_assert_ldouble_eq(MY_ceil(-0.12), ceil(-0.12));
  // Test 8
  ck_assert_ldouble_eq(MY_ceil(0), ceil(0));
  // Test 9
  ck_assert_ldouble_eq(MY_ceil(0.0), ceil(0.0));
  // Test 10
  ck_assert_ldouble_eq(MY_ceil(21.21), ceil(21.21));
  // Test 11
  ck_assert_ldouble_eq(MY_ceil(21.91), ceil(21.91));
  // Test 12
  ck_assert_ldouble_eq(MY_ceil(-21.21), ceil(-21.21));
  // Test 13
  ck_assert_ldouble_eq(MY_ceil(-21.91), ceil(-21.91));
  ck_assert(fabsl(MY_ceil(1e9) - ceil(1e9)) < MY_EPS);
  ck_assert(fabsl(MY_ceil(99999.9999999) - ceil(99999.9999999)) < MY_EPS);
  ck_assert(fabsl(MY_ceil(-99999.9999999) - ceil(-99999.9999999)) < MY_EPS);
  ck_assert(isnan(MY_ceil(MY_NAN)) && isnan(ceil(MY_NAN)));
  ck_assert(MY_ceil(MY_INF) && MY_INF);
  ck_assert(MY_ceil(-MY_INF) && -MY_INF);
}
END_TEST
START_TEST(test_MY_cos) {
  double num = 0.55;
  long double orig_res = MY_cos(num), our_res = MY_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  double num1 = -0.999999;
  long double orig_res1 = cos(num1), our_res1 = MY_cos(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 2
  double num2 = 628;
  long double orig_res2 = cos(num2), our_res2 = MY_cos(num2);
  int suc2 = 0;
  if ((fabsl(orig_res2 - our_res2) <= 1e-6)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 3
  ck_assert_float_eq(MY_cos(0), cos(0));
  // Test 4
  ck_assert_float_eq(MY_cos(-1), cos(-1));
  // Test 5
  double num3 = MY_NAN;
  long double orig_res3 = cos(num3), our_res3 = MY_cos(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 6
  double num4 = MY_INF;
  long double orig_res4 = cos(num4), our_res4 = MY_cos(num4);
  int suc4 = 0;
  if (isnan(orig_res4) && isnan(our_res4)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 7
  double num5 = -MY_INF;
  long double orig_res5 = cos(num5), our_res5 = MY_cos(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 8
  double x = 0;
  ck_assert_double_eq_tol(MY_cos(x), cosl(x), 1e-06);
  // Test 12
  ck_assert_ldouble_eq_tol(MY_cos(0.0), cosl(0.0), 1e-06);
  // Test 13
  ck_assert_double_eq_tol(MY_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(MY_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(MY_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(MY_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(MY_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
  // Test 18
  ck_assert_double_eq_tol(MY_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
  // Test 19
  ck_assert_double_eq_tol(MY_cos(174.532925199433), cosl(174.532925199433),
                          1e-06);
  // Test 20
  ck_assert_double_eq_tol(MY_cos(-174.532925199433), cosl(-174.532925199433),
                          1e-06);
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -100; exp49 < 110; exp49 += 0.25) {
    res1 = cos(exp49);
    res2 = MY_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -10000; exp49 < 14310; exp49 += 10.54646) {
    res1 = cos(exp49);
    res2 = MY_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -100 * MY_M_PI; exp49 < 110 * MY_M_PI;
       exp49 += (MY_M_PI / 12)) {
    res1 = cos(exp49);
    res2 = MY_cos(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  ck_assert_ldouble_eq_tol(cos(0.0), MY_cos(0.0), 1e-6);
}
END_TEST

START_TEST(test_MY_exp) {
  double num = NAN;
  long double orig_res = exp(num), our_res = MY_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  double num1 = INFINITY;
  long double orig_res1 = exp(num1), our_res1 = MY_exp(num1);
  int suc1 = 0;
  if (isinf(orig_res1) && isinf(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);

  ck_assert_int_eq(MY_exp(0), exp(0));

  ck_assert_int_eq(MY_exp(1), exp(1));

  ck_assert_int_eq(MY_exp(2), exp(2));

  ck_assert_int_eq(MY_exp(3), exp(3));

  ck_assert_int_eq(MY_exp(1.5), exp(1.5));

  ck_assert_int_eq(MY_exp(-1.5), exp(-1.5));

  ck_assert_int_eq(MY_exp(0.5), exp(0.5));

  ck_assert_int_eq(MY_exp(-0.5), exp(-0.5));

  ck_assert_int_eq(MY_exp(715), exp(715));

  ck_assert_int_eq(MY_exp(-0), exp(-0));

  ck_assert_int_eq(MY_exp(0 / 1), exp(0 / 1));

  ck_assert_ldouble_eq_tol(MY_exp(0.0), expl(0.0), 1e-06);

  ck_assert_ldouble_eq_tol(MY_exp(-1.0), expl(-1.0), 1e-06);

  ck_assert_ldouble_eq_tol(MY_exp(1), expl(1), 1e-06);

  double exp49;
  long double res1;
  long double res2;
  for (exp49 = -47; exp49 < 15; exp49 += 0.25) {
    res1 = expl(exp49);
    res2 = MY_exp(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -1000; exp49 < 25; exp49 += 1.33) {
    res1 = expl(exp49);
    res2 = MY_exp(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-4);
  }
}
END_TEST

START_TEST(test_MY_fabs) {
  ck_assert_ldouble_eq(MY_fabs(0.000001), fabs(0.000001));

  ck_assert_ldouble_eq(MY_fabs(-21.000345), fabs(-21.000345));

  ck_assert_ldouble_eq(MY_fabs(-2147483600.543), fabs(-2147483600.543));

  ck_assert_ldouble_eq(MY_fabs(2147483600.4857), fabs(2147483600.4857));

  ck_assert_ldouble_eq(MY_fabs(-5.53151413431), fabs(-5.53151413431));

  double a = MY_NAN;
  ck_assert_ldouble_nan(MY_fabs(a));
  ck_assert_ldouble_nan(fabs(a));

  double a1 = MY_INF;
  ck_assert_ldouble_infinite(MY_fabs(a1));
  ck_assert_ldouble_infinite(fabs(a1));

  ck_assert_ldouble_eq_tol(MY_fabs(-9519359135915.53151413431),
                           fabs(-9519359135915.53151413431), MY_EPS);

  ck_assert_ldouble_nan(MY_fabs(MY_NAN));
  ck_assert_ldouble_nan(fabs(MY_NAN));

  ck_assert_ldouble_eq(MY_fabs(-15.01), fabs(-15.01));

  ck_assert_ldouble_eq(MY_fabs(15.01), fabs(15.01));

  ck_assert_ldouble_eq(MY_fabs(MY_INF), fabs(MY_INF));

  ck_assert_ldouble_eq(MY_fabs(-MY_INF), fabs(-MY_INF));

  double num = MY_NAN;
  long double orig_res = fabs(num), our_res = MY_fabs(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(test_MY_floor) {
  ck_assert_ldouble_nan(floor(MY_NAN));
  ck_assert_ldouble_nan(MY_floor(MY_NAN));

  ck_assert_ldouble_eq(MY_floor(0.0), floor(0.0));

  ck_assert_ldouble_eq(MY_floor(21.21), floor(21.21));

  ck_assert_ldouble_eq(MY_floor(21.91), floor(21.91));

  ck_assert_ldouble_eq(MY_floor(-21.21), floor(-21.21));

  ck_assert_ldouble_eq(MY_floor(-21.91), floor(-21.91));

  double a1 = MY_INF;
  ck_assert_ldouble_infinite(MY_floor(a1));
  ck_assert_ldouble_infinite(floor(a1));
  ck_assert_ldouble_eq(MY_floor(0), floor(0));

  ck_assert_ldouble_eq(MY_floor(-15.01), floor(-15.01));

  ck_assert_ldouble_eq(MY_floor(15.01), floor(15.01));

  ck_assert_ldouble_eq(MY_floor(MY_INF), floor(MY_INF));

  ck_assert_ldouble_eq(MY_floor(-MY_INF), floor(-MY_INF));
  double exp49;
  for (exp49 = -1000; exp49 < 1000; exp49 += 0.25) {
    long double res1;
    long double res2;
    res1 = floor(exp49);
    res2 = MY_floor(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(test_MY_fmod) {
  ck_assert_ldouble_eq(MY_fmod(2.34, 2.0), fmod(2.34, 2.0));

  ck_assert_ldouble_eq(MY_fmod(2.34, 2.0), fmod(2.34, 2.0));

  ck_assert_ldouble_eq(MY_fmod(-2.34, 2.0), fmod(-2.34, 2.0));

  ck_assert_ldouble_eq(MY_fmod(2.34, -2.0), fmod(2.34, -2.0));

  ck_assert_ldouble_eq(MY_fmod(-2.34, -2.0), fmod(-2.34, -2.0));

  ck_assert_ldouble_eq(MY_fmod(21.21, 3), fmod(21.21, 3));

  ck_assert_ldouble_eq(MY_fmod(3, 21.21), fmod(3, 21.21));

  ck_assert_ldouble_eq(MY_fmod(-21.21, 3), fmod(-21.21, 3));

  ck_assert_ldouble_eq(MY_fmod(3, -21.21), fmod(3, -21.21));

  ck_assert_ldouble_eq(MY_fmod(100500, 9), fmod(100500, 9));

  ck_assert_ldouble_eq(MY_fmod(-100500, -9), fmod(-100500, -9));

  ck_assert_ldouble_eq(MY_fmod(-9, -100500), fmod(-9, -100500));

  ck_assert_ldouble_eq(MY_fmod(-9, -9), fmod(-9, -9));

  ck_assert_ldouble_eq(MY_fmod(10, 5), fmod(10, 5));

  ck_assert_ldouble_nan(MY_fmod(MY_NAN, MY_NAN));

  ck_assert_ldouble_nan(MY_fmod(2.45, 0));

  ck_assert_ldouble_nan(MY_fmod(INFINITY, 0));

  double num = MY_NAN;
  long double orig_res = fmod(num, 2.0), our_res = MY_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  double num1 = MY_NAN;
  long double orig_res1 = fmod(2.0, num1), our_res1 = MY_fmod(2.0, num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);

  double num2 = MY_INF;
  long double orig_res2 = fmod(num2, 2.0), our_res2 = MY_fmod(num2, 2.0);
  int suc2 = 0;
  if (isnan(orig_res2) && isnan(our_res2)) suc2 = 1;
  ck_assert_int_eq(1, suc2);

  double num3 = -MY_INF;
  long double orig_res3 = fmod(num3, 2.0), our_res3 = MY_fmod(num3, 2.0);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);

  ck_assert_ldouble_eq(MY_fmod(0, 23), fmod(0, 23));
  ck_assert(fabsl(MY_fmod(2.34, MY_INF) - fmod(2.34, MY_INF)) <
            MY_EPS * 1000);
  ck_assert(fabsl(MY_fmod(2.34, -MY_INF) - fmod(2.34, -MY_INF)) <
            MY_EPS * 100);
  ck_assert(isnan(MY_fmod(MY_NAN, 10.75)) == isnan(fmod(MY_NAN, 10.75)));
  ck_assert(isnan(MY_fmod(MY_INF, 10.75)) == isnan(fmod(MY_INF, 10.75)));
  ck_assert(isnan(MY_fmod(-MY_INF, 10.75)) == isnan(fmod(-MY_INF, 10.75)));
  ck_assert(isnan(MY_fmod(-MY_INF, -MY_INF)) ==
            isnan(fmod(-MY_INF, -MY_INF)));
  ck_assert(isnan(MY_fmod(MY_INF, MY_INF)) == isnan(fmod(MY_INF, MY_INF)));
  ck_assert(isnan(MY_fmod(-MY_INF, MY_INF)) ==
            isnan(fmod(-MY_INF, MY_INF)));
  ck_assert(isnan(MY_fmod(MY_INF, -MY_INF)) ==
            isnan(fmod(MY_INF, -MY_INF)));
  ck_assert(isnan(MY_fmod(MY_NAN, -MY_INF)) ==
            isnan(fmod(MY_NAN, -MY_INF)));
  ck_assert(isnan(MY_fmod(MY_NAN, MY_INF)) == isnan(fmod(MY_NAN, MY_INF)));
}
END_TEST
START_TEST(test_MY_log) {
  ck_assert_ldouble_eq_tol(MY_log(1.0), log(1.0), 1e-5);
  ck_assert_ldouble_eq_tol(MY_log(1.1), log(1.1), 1e-5);

  ck_assert_ldouble_eq_tol(MY_log(0.5), log(0.5), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(1), log(1), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(100), log(100), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(0.5), log(0.5), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(0.5), log(0.5), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(MY_PI / 3), log(MY_PI / 3), 1e-6);

  ck_assert_ldouble_eq_tol(MY_log(9.234578353457e-6), log(9.234578353457e-6),
                           1e-4);

  ck_assert_ldouble_eq_tol(MY_log(9.234578353457e6), log(9.234578353457e6),
                           1e-6);

  ck_assert_ldouble_eq_tol(MY_log(1234567.000000004), log(1234567.000000004),
                           1e-6);
  ck_assert(fabsl(MY_log(1234.4) - log(1234.4)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(0.1) - log(0.1)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(0.01) - log(0.01)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(1) - log(1)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(2.72) - log(2.72)) < MY_EPS * 1000);
  ck_assert(isnan(MY_log(MY_NAN)) == isnan(log(MY_NAN)));
  ck_assert(isnan(MY_log(-MY_INF)) == isnan(log(-MY_INF)));
  ck_assert(MY_log(MY_INF) == MY_INF);
  ck_assert(MY_log(0) == -MY_INF);
  ck_assert(fabsl(MY_log(1e-5) - log(1e-5)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(1e4) - log(1e4)) < MY_EPS * 100);
  ck_assert(fabsl(MY_log(1e16) - log(1e16)) < MY_EPS);
  ck_assert(fabsl(MY_log(1e32) - log(1e32)) < MY_EPS);
}
END_TEST

START_TEST(test_MY_pow) {
  ck_assert_ldouble_eq_tol(MY_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);

  ck_assert_ldouble_eq_tol(MY_pow(-1, 4), pow(-1, 4), 1e-6);

  ck_assert_ldouble_eq_tol(MY_pow(2, 18), pow(2, 18), 1e-6);

  ck_assert_ldouble_eq_tol(MY_pow(2.1, 11), pow(2.1, 11), 1e-6);

  ck_assert_ldouble_eq_tol(MY_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);

  ck_assert_ldouble_eq_tol(MY_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);

  long double exp33 = 0;
  ck_assert_ldouble_eq_tol(MY_pow(-0, exp33), pow(-0, exp33), 1e-6);

  long double exp35 = 2.456;
  ck_assert_ldouble_eq_tol(MY_pow(+0, exp35), pow(+0, exp35), 1e-6);

  long double exp37 = 56;
  ck_assert_ldouble_eq_tol(MY_pow(+0, exp37), pow(+0, exp37), 1e-6);

  long double exp38 = 56;
  ck_assert_ldouble_eq_tol(MY_pow(-0, exp38), pow(-0, exp38), 1e-6);

  long double exp39 = 56.345;
  ck_assert_ldouble_eq_tol(MY_pow(-0, exp39), pow(-0, exp39), 1e-6);

  long double exp41 = -MY_INF;
  ck_assert_ldouble_eq_tol(MY_pow(-1, exp41), pow(-1, exp41), 1e-6);

  long double exp42 = MY_NAN;
  ck_assert_ldouble_eq_tol(MY_pow(+1, exp42), pow(+1, exp42), 1e-6);

  long double exp43 = -0;
  ck_assert_ldouble_eq_tol(MY_pow(4567, exp43), pow(4567, exp43), 1e-6);

  long double exp44 = +0;
  ck_assert_ldouble_eq_tol(MY_pow(34567, exp44), pow(34567, exp44), 1e-6);

  long double exp45 = -0;
  ck_assert_ldouble_eq_tol(MY_pow(MY_NAN, exp45), pow(MY_NAN, exp45), 1e-6);

  long double exp46 = +0;
  ck_assert_ldouble_eq_tol(MY_pow(MY_NAN, exp46), pow(MY_NAN, exp46), 1e-6);

  long double exp47 = MY_NAN;
  ck_assert_double_nan(MY_pow(MY_NAN, exp47));
  ck_assert_double_nan(pow(MY_NAN, exp47));

  long double exp48 = MY_INF;
  ck_assert_ldouble_infinite(MY_pow(MY_INF, exp48));
  ck_assert_ldouble_infinite(pow(MY_INF, exp48));

  long double exp477 = -MY_INF;
  ck_assert_ldouble_eq_tol(MY_pow(-MY_INF, exp477), pow(-MY_INF, exp477),
                           1e-6);

  double exp488 = MY_INF;
  ck_assert_ldouble_infinite(MY_pow(-MY_INF, exp488));
  ck_assert_ldouble_infinite(pow(-MY_INF, exp488));

  double exp49;
  // double exp500;

  for (exp49 = -100; exp49 < 15; exp49 += 10) {
    double res1;
    long double res2;
    res1 = pow(2.7, exp49);
    res2 = MY_pow(2.7, exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }

  // Test 57
  double base50;
  double res10;
  long double res20;

  for (base50 = 0.0; base50 < 10; base50 += 0.1) {
    res10 = pow(base50, MY_INF);
    res20 = MY_pow(base50, MY_INF);
  }
  ck_assert_ldouble_infinite(res10);
  ck_assert_ldouble_infinite(res20);

  // Test 59
  long double base53;
  long double res12;
  long double res22;

  for (base53 = 0.0; base53 < 10; base53 += 0.1) {
    res12 = pow(base53, -MY_INF);
    res22 = MY_pow(base53, -MY_INF);
  }
  ck_assert_ldouble_eq_tol(res12, res22, 1e-6);

  // Test 60
  long double base54;
  long double res13;
  long double res23;

  for (base54 = 0.0; base54 > -10; base54 -= 0.1) {
    res13 = pow(base54, -MY_INF);
    res23 = MY_pow(base54, -MY_INF);
  }
  ck_assert_ldouble_eq_tol(res13, res23, 1e-6);
  // Test 61
  double exp55;
  double res14;
  long double res24;

  for (exp55 = 0.0; exp55 > -10; exp55 -= 0.1) {
    if (fmod(exp55, 2) != 0) {
      res14 = pow(-MY_INF, exp55);
      res24 = MY_pow(-MY_INF, exp55);
    }
  }
  ck_assert_ldouble_eq_tol(res14, res24, 1e-6);
  // Test 63
  double exp57;
  double res16;
  long double res26;
  for (exp57 = 0.0; exp57 < 10; exp57 += 0.1) {
    if (fmod(exp57, 2) != 0) {
      res16 = pow(-MY_INF, exp57);
      res26 = MY_pow(-MY_INF, exp57);
    }
  }
  ck_assert_ldouble_infinite(res16);
  ck_assert_ldouble_infinite(res26);
  long double exp59 = 3;
  ck_assert_ldouble_eq_tol(MY_pow(-3, exp59), pow(-3, exp59), 1e-6);
  // Test 66
  long double exp60 = -3;
  ck_assert_ldouble_eq_tol(MY_pow(-3, exp60), pow(-3, exp60), 1e-6);
  // Test 67
  long double exp61 = -3;
  ck_assert_ldouble_eq_tol(MY_pow(3, exp61), pow(3, exp61), 1e-6);
  // Test 68
  long double exp62 = 3;
  ck_assert_ldouble_eq_tol(MY_pow(3, exp62), pow(3, exp62), 1e-6);
  // Test 69
  long double base63 = -0;
  long double exp63 = MY_INF;
  long double res63 = pow(base63, exp63);
  long double res163 = MY_pow(base63, exp63);
  ck_assert_ldouble_eq_tol(res63, res163, 1e-6);
  // Test 70
  long double exp64;
  long double base64 = -0;
  long double res64;
  long double res164;
  for (exp64 = 0.0; exp64 < 10; exp64 += 0.1) {
    if (fmod(exp64, 2) != 0) {
      res64 = pow(base64, exp64);
      res164 = MY_pow(base64, exp64);
    }
  }
  ck_assert_ldouble_eq_tol(res64, res164, 1e-6);
}
END_TEST

START_TEST(test_MY_sin) {
  double num = 0.55;
  long double orig_res = MY_sin(num), our_res = MY_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 1
  ck_assert_float_eq(MY_sin(0), sin(0));
  // Test 2
  double num1 = 1;
  long double orig_res1 = MY_sin(num1), our_res1 = MY_sin(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 3
  double num2 = -1;
  long double orig_res2 = MY_sin(num2), our_res2 = MY_sin(num2);
  int suc2 = 0;
  if ((fabsl(orig_res2 - our_res2) <= 1e-6)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 4
  double num3 = 0.999999;
  long double orig_res3 = MY_sin(num3), our_res3 = MY_sin(num3);
  int suc3 = 0;
  if ((fabsl(orig_res3 - our_res3) <= 1e-6)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 5
  double num4 = -0.999999;
  long double orig_res4 = MY_sin(num4), our_res4 = MY_sin(num4);
  int suc4 = 0;
  if ((fabsl(orig_res4 - our_res4) <= 1e-6)) suc4 = 1;
  ck_assert_int_eq(1, suc4);
  // Test 6
  double num5 = MY_NAN;
  long double orig_res5 = sin(num5), our_res5 = MY_sin(num5);
  int suc5 = 0;
  if (isnan(orig_res5) && isnan(our_res5)) suc5 = 1;
  ck_assert_int_eq(1, suc5);
  // Test 7
  double num6 = MY_INF;
  long double orig_res6 = sin(num6), our_res6 = MY_sin(num6);
  int suc6 = 0;
  if (isnan(orig_res6) && isnan(our_res6)) suc6 = 1;
  ck_assert_int_eq(1, suc6);
  // Test 8
  double num7 = -MY_INF;
  long double orig_res7 = sin(num7), our_res7 = MY_sin(num7);
  int suc7 = 0;
  if (isnan(orig_res7) && isnan(our_res7)) suc7 = 1;
  ck_assert_int_eq(1, suc7);
  // Test 9
  double x = 0;
  ck_assert_double_eq_tol(MY_sin(x), sinl(x), 1e-06);
  // Test 10
  ck_assert_ldouble_nan(MY_sin(-MY_INF));
  ck_assert_ldouble_nan(sinl(-MY_INF));
  // Test 11
  ck_assert_ldouble_nan(MY_sin(MY_INF));
  ck_assert_ldouble_nan(sinl(MY_INF));
  // Test 12
  ck_assert_ldouble_nan(MY_sin(MY_NAN));
  ck_assert_ldouble_nan(sinl(MY_NAN));
  // Test 13
  ck_assert_double_eq_tol(MY_sin(0.0), sin(0.0), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(MY_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(MY_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(MY_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(MY_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
  // Test 18
  ck_assert_double_eq_tol(MY_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
  // Test 19
  ck_assert_double_eq_tol(MY_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
  // Test 20
  ck_assert_double_eq_tol(MY_sin(-5 * M_PI), sin(-5 * M_PI), 1e-06);
  // Test 21
  ck_assert_double_eq_tol(MY_sin(M_PI / 100), sin(M_PI / 100), 1e-06);
  ck_assert_double_eq_tol(MY_sin(99 * M_PI / 100), sin(99 * M_PI / 100),
                          1e-06);
  ck_assert_double_eq_tol(MY_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
  ck_assert_double_eq_tol(MY_sin(12.453 * M_PI), sin(12.453 * M_PI), 1e-06);
  // Test 22
  ck_assert_double_eq_tol(MY_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
  // Test 23
  ck_assert_double_eq_tol(MY_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
  // Test 24
  ck_assert_double_eq_tol(MY_sin(-MY_PI), sin(-MY_PI), 1e-06);
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -100; exp49 < 110; exp49 += 0.25) {
    res1 = sin(exp49);
    res2 = MY_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -10000; exp49 < 14310; exp49 += 10.54646) {
    res1 = sin(exp49);
    res2 = MY_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  for (exp49 = -100 * MY_M_PI; exp49 < 110 * MY_M_PI;
       exp49 += (MY_M_PI / 12)) {
    res1 = sin(exp49);
    res2 = MY_sin(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
  ck_assert_ldouble_eq_tol(sin(0.0), MY_sin(0.0), 1e-6);
}
END_TEST

START_TEST(test_MY_sqrt) {
  ck_assert_ldouble_eq_tol(MY_sqrt(1.0), sqrt(1.0), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(1.1), sqrt(1.1), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(0.0), sqrt(0.0), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(-0.0), sqrt(-0.0), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(10e+16), sqrt(10e+16), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(1), sqrt(1), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(100), sqrt(100), 1e-5);

  ck_assert_ldouble_eq_tol(MY_sqrt(98765432.123), sqrt(98765432.123), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(981.123e6), sqrt(981.123e6), 1e-6);

  ck_assert_ldouble_eq_tol(MY_sqrt(9), sqrt(9), 1e-6);
}
END_TEST

START_TEST(test_MY_tan) {
  ck_assert_float_eq(MY_tan(-15.01), tan(-15.01));
  // Test 1
  double num = 0.55;
  long double orig_res = MY_tan(num), our_res = MY_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
  ck_assert_float_eq(-9999999999, -9999999999);
  // Test 3
  double num1 = MY_NAN;
  long double orig_res1 = tan(num1), our_res1 = MY_tan(num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 4
  double num2 = MY_INF;
  long double orig_res2 = tan(num2), our_res2 = MY_tan(num2);
  int suc2 = 0;
  if (isnan(orig_res2) && isnan(our_res2)) suc2 = 1;
  ck_assert_int_eq(1, suc2);
  // Test 5
  double num3 = -MY_INF;
  long double orig_res3 = tan(num3), our_res3 = MY_tan(num3);
  int suc3 = 0;
  if (isnan(orig_res3) && isnan(our_res3)) suc3 = 1;
  ck_assert_int_eq(1, suc3);
  // Test 6
  double x = 0;
  ck_assert_double_eq_tol(MY_tan(x), tanl(x), 1e-06);
  // Test 7
  ck_assert_ldouble_nan(MY_tan(-MY_INF));
  ck_assert_ldouble_nan(tanl(-MY_INF));
  // Test 8
  ck_assert_ldouble_nan(MY_tan(MY_INF));
  ck_assert_ldouble_nan(tanl(MY_INF));
  // Test 9
  ck_assert_ldouble_nan(MY_tan(MY_NAN));
  ck_assert_ldouble_nan(tanl(MY_NAN));
  // Test 10
  ck_assert_double_eq_tol(MY_tan(0.0), tanl(0.0), 1e-06);
  // Test 11
  ck_assert_double_eq_tol(MY_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
  // Test 12
  ck_assert_double_eq_tol(MY_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
  // Test 13
  ck_assert_double_eq_tol(MY_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
  // Test 14
  ck_assert_double_eq_tol(MY_tan(M_PI), tanl(M_PI), 1e-06);
  // Test 15
  ck_assert_double_eq_tol(MY_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
  // Test 16
  ck_assert_double_eq_tol(MY_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), 1e-06);
  // Test 17
  ck_assert_double_eq_tol(MY_tan(174.532925199433), tanl(174.532925199433),
                          1e-06);
  // Test 18
  ck_assert_double_eq_tol(MY_tan(-174.532925199433), tanl(-174.532925199433),
                          1e-06);
  ck_assert(fabsl(MY_tan(0.07) - tan(0.07)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(0.007) - tan(0.007)) < MY_EPS);
  ck_assert(fabsl(MY_tan(0.0007) - tan(0.0007)) < MY_EPS);
  ck_assert(fabsl(MY_tan(1) - tan(1)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(2) - tan(2)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(3) - tan(3)) < MY_EPS);
  ck_assert(fabsl(MY_tan(4) - tan(4)) < MY_EPS);
  ck_assert(fabsl(MY_tan(5) - tan(5)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(100) - tan(100)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-0.7) - tan(-0.7)) < MY_EPS);
  ck_assert(fabsl(MY_tan(-0.07) - tan(-0.07)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-0.007) - tan(-0.007)) < MY_EPS);
  ck_assert(fabsl(MY_tan(-0.0007) - tan(-0.0007)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-1) - tan(-1)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-2) - tan(-2)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-3) - tan(-3)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-4) - tan(-4)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-5) - tan(-5)) < MY_EPS * 100);
  ck_assert(fabsl(MY_tan(-100) - tan(-100)) < MY_EPS * 100);
  ck_assert(isnan(MY_tan(MY_NAN)) == isnan(tan(MY_NAN)));
  double exp49;
  double res1;
  long double res2;
  for (exp49 = -5; exp49 < -4; exp49 += 0.1) {
    res1 = tan(exp49);
    res2 = MY_tan(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }

  for (exp49 = -10000; exp49 < 10000; exp49 += 15.4) {
    res1 = tan(exp49);
    res2 = MY_tan(exp49);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

/* Функция создания набора тестов. */
Suite *example_suite_create(void) {
  Suite *suite = suite_create("Example");
  TCase *tcase_core = tcase_create("Core of example");

  /* Добавление теста в группу тестов. */

  tcase_add_test(tcase_core, test_MY_abs);
  tcase_add_test(tcase_core, test_MY_acos);
  tcase_add_test(tcase_core, test_MY_asin);
  tcase_add_test(tcase_core, test_MY_atan);
  tcase_add_test(tcase_core, test_MY_ceil);
  tcase_add_test(tcase_core, test_MY_cos);
  tcase_add_test(tcase_core, test_MY_exp);
  tcase_add_test(tcase_core, test_MY_fabs);
  tcase_add_test(tcase_core, test_MY_floor);
  tcase_add_test(tcase_core, test_MY_fmod);
  tcase_add_test(tcase_core, test_MY_log);
  tcase_add_test(tcase_core, test_MY_pow);
  tcase_add_test(tcase_core, test_MY_sin);
  tcase_add_test(tcase_core, test_MY_sqrt);
  tcase_add_test(tcase_core, test_MY_tan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = example_suite_create();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
