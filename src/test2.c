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
  // Test 2
  double num1 = -0.99;
  long double orig_res1 = acos(num1), our_res1 = MY_acos(num1);
  int suc1 = 0;
  if ((fabsl(orig_res1 - our_res1) <= 1e-6)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
  // Test 3
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
  // Test 2
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
}
END_TEST

START_TEST(test_MY_atan) {
  // Test 1
  double num = -0.99;
  long double orig_res = MY_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
  double num1 = MY_NAN;
  long double orig_res1 = MY_atan(num1), our_res1 = atan(num1);
  int suc1 = 0;
  if (isnan(orig_res1) && isnan(our_res1)) suc1 = 1;
  ck_assert_int_eq(1, suc1);
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
}
END_TEST

START_TEST(test_MY_exp) {
  double num = NAN;
  long double orig_res = exp(num), our_res = MY_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_int_eq(MY_exp(0), exp(0));

  ck_assert_int_eq(MY_exp(1), exp(1));

  ck_assert_int_eq(MY_exp(2), exp(2));

  ck_assert_int_eq(MY_exp(3), exp(3));

  ck_assert_int_eq(MY_exp(1.5), exp(1.5));

  ck_assert_int_eq(MY_exp(-1.5), exp(-1.5));

  ck_assert_int_eq(MY_exp(0.5), exp(0.5));

  ck_assert_int_eq(MY_exp(-0.5), exp(-0.5));

  ck_assert_int_eq(MY_exp(-0), exp(-0));

  ck_assert_int_eq(MY_exp(0 / 1), exp(0 / 1));
}
END_TEST

START_TEST(test_MY_fabs) {
  double num = MY_NAN;
  long double orig_res = fabs(num), our_res = MY_fabs(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(test_MY_fmod) {
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
}
END_TEST

START_TEST(test_MY_sin) {
  double num = 0.55;
  long double orig_res = MY_sin(num), our_res = MY_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // // Test 1
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
}
END_TEST

START_TEST(test_MY_tan) {
  // Test 1
  double num = 0.55;
  long double orig_res = MY_tan(num), our_res = MY_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
  // Test 2
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
  tcase_add_test(tcase_core, test_MY_cos);
  tcase_add_test(tcase_core, test_MY_exp);
  tcase_add_test(tcase_core, test_MY_fabs);
  tcase_add_test(tcase_core, test_MY_fmod);
  tcase_add_test(tcase_core, test_MY_sin);
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
