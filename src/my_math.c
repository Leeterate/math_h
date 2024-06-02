#include "my_math.h"
long double MY_log_less1(double x);

/* вычисляет абсолютное значение целого числа */
int MY_abs(int x) { return (x < 0) ? x * (-1) : x; }

/* вычисляет арккосинус */
long double MY_acos(double x) {
  long double rezult = 0;
  if (x <= 1 && x >= -1 && x == x) {
    rezult = (MY_M_PI / 2) - MY_asin(x);
  } else {
    rezult = MY_NAN;
  }
  return rezult;
}

/* вычисляет арксинус */
long double MY_asin(double x) {
  long double tmp = x, sin = MY_NAN;
  if (-1.0 < x && x < 1.0) {
    sin = tmp;
    x *= x;
    for (int n = 1; MY_fabs(tmp) > MY_EPS; n += 2)
      sin += (tmp *= x * n / (n + 1)) / (n + 2);
  } else if (x == 1.0) {
    sin = MY_M_PI / 2.0;
  } else if (x == -1.0) {
    sin = -MY_M_PI / 2.0;
  }
  return sin;
}

/* вычисляет арктангенс */
long double MY_atan(double x) {
  long double rez = MY_asin(x / MY_sqrt(x * x + 1.0));
  return rez;
}

/* вычисляет косинус */
long double MY_cos(double x) {
  long double rezult = 0;
  x = (double)MY_fmod(x, 2 * MY_M_PI);
  double eps = 1, s = 1;
  for (int i = 2; i < 100 || MY_fabs(eps) > MY_EPS / 100; i += 2) {
    eps = -1 * eps * x * x / ((i - 1) * i);
    s = s + eps;
  }
  rezult = s;
  return rezult;
}

long double MY_exp_less(long double x) {
  long n = 1.0;
  long double dest = 0;
  long double x_double = (long double)x;
  long double precision = 1;
  while (MY_fabs(precision) > MY_EPS / 100000) {
    dest += precision;
    precision = precision * x_double / n++;
  }
  return dest;
}

long double MY_exp(double x) {
  long double dest = 0;
  int minus = 0;
  if (x > 709 || x == MY_INF) {
    dest = MY_INF;
  } else if (x == -MY_INF) {
    dest = 0;
  } else if (x != x) {
    dest = MY_NAN;
  } else {
    if (x < 0) {
      x = -x;
      minus = 1;
    }
    if (x > 10) {
      long double exp_int = 1;
      for (int i = 0; i < (x - MY_fmod(x, 10)); i++) {
        exp_int *= MY_EXP;
      }
      dest = exp_int * MY_exp_less((MY_fmod(x, 10)));
    } else {
      dest = MY_exp_less((long double)x);
    }
  }
  return ((minus) ? 1 / dest : dest);
}

/* вычисляет абсолютное значение числа с плавающей точкой */
long double MY_fabs(double x) {
  long double rezult = 0;
  if (x < 0) {
    rezult = x * -1;
  } else {
    rezult = x;
  }
  return rezult;
}

/* остаток операции деления с плавающей точкой */
long double MY_fmod(double x, double y) {
  long double rezult;
  if ((x != MY_INF && x != -MY_INF) && (y == MY_INF || y == -MY_INF)) {
    rezult = x;
  } else if ((x == -MY_INF || x == MY_INF) &&
             (y == -MY_INF || y == MY_INF)) {
    rezult = MY_NAN;
  } else {
    long double temp = (x / y > 0) ? MY_floor(x / y) : MY_ceil(x / y);
    rezult = x - temp * y;
  }
  return rezult;
}

long double MY_log_less1(double x) {
  x = x - 1;
  int sign = 1;
  int n = 1;
  double pow_x = x;
  double precision = x;
  double dest = 0;
  while (MY_fabs(precision) > MY_EPS / 10000) {
    dest = dest + precision;
    n = n + 1;
    pow_x = pow_x * x;
    sign = sign * (-1);
    precision = sign * pow_x / n;
  }
  return dest;
}

/* вычисляет натуральный логарифм */
long double MY_log(double x) {
  long double rezult;
  if (x >= 0) {
    if (x == MY_INF) {
      rezult = MY_INF;
    } else if (x == 0) {
      rezult = -MY_INF;
    } else if (x == -MY_INF) {
      rezult = MY_NAN;
    } else {
      long double dest = 0;
      int ex_pow = 0;
      for (; x > 1; x /= MY_EXP, ex_pow++) continue;
      dest = MY_log_less1(x);
      rezult = dest + ex_pow;
    }
  } else {
    rezult = MY_NAN;
  }
  return rezult;
}

/* возводит число в заданную степень */
long double MY_pow(double base, double exp) {
  long double dest = 0;
  if ((base == -1) && (exp == -MY_INF)) {
    dest = 1;
  } else if ((base == MY_INF || base == -MY_INF) && exp == MY_INF) {
    dest = MY_INF;
  } else if (base == 0 && exp == MY_INF) {
    dest = 0;
  } else if ((base < 1 && base > -1) && exp == -MY_INF) {
    dest = MY_INF;
  } else if (base == -MY_INF && exp == -MY_INF) {
    dest = 0;
  } else if (base == MY_INF && exp < 0) {
    dest = 0;
  } else if (base == -MY_INF && exp < 0) {
    dest = 0;
  } else if (base == -MY_INF) {
    dest = MY_INF;
  } else if (base == -MY_INF || exp == -MY_INF) {
    dest = 0;
  } else if (exp == MY_INF) {
    dest = MY_INF;
  } else if (exp == 0) {
    dest = 1;
  } else if (base == 1) {
    dest = 1;
  } else if (base == 0) {
    dest = 0;
  } else if (!(base == base) || !(exp == exp)) {
    dest = MY_NAN;
  } else {
    int sign = 0;
    int sign_exp = 0;
    if (base < 0) {
      sign = 1;
      base = base * (-1);
    }
    if (exp < 0) {
      sign_exp = 1;
      exp = -exp;
    }
    double exp_pow;
    long double log = MY_log(base);
    exp_pow = log * exp;
    dest = MY_exp(exp_pow);
    if (sign) {
      if ((int)exp % 2) {
        dest = -dest;
      }
    }
    if (sign_exp) {
      dest = 1 / dest;
    }
  }
  if (dest > 1.7e+308) dest = MY_INF;
  if (dest < -1.7e+308) dest = -MY_INF;
  return dest;
}

/* вычисляет синус */
long double MY_sin(double x) {
  long double rezult;
  int pi_f = 0;
  if (MY_fabs((MY_fabs(x) - MY_M_PI)) < MY_EPS) pi_f = 1;
  x = (double)MY_fmod(x, 2 * MY_M_PI);
  double eps = x, s = x;
  for (int i = 3; i < 100 || MY_fabs(eps) > MY_EPS / 100; i += 2) {
    eps = -1 * eps * x * x / ((i - 1) * i);
    s = s + eps;
  }
  rezult = s;
  return ((pi_f && (rezult < 0)) ? -rezult : rezult);
}

/* вычисляет квадратный корень */
long double MY_sqrt(double x) {
  double flag = 0;
  if (x < 0 || x != x) {
    flag = MY_NAN;
  } else {
    if (x == 0) {
      flag = x;
    } else {
      double s = 1, tmp = 0;
      while (s != tmp) {
        tmp = s;
        s = (x / tmp + tmp) / 2;
      }
      flag = s;
    }
  }
  return flag;
}

/* вычисляет тангенс */
long double MY_tan(double x) {
  x = (double)MY_fmod(x, MY_M_PI);
  long double rezult = MY_sin(x) / MY_cos(x);
  if (x == MY_M_PI / 2) {
    rezult = 16331239353195370L;
  } else if (x == -MY_M_PI / 2) {
    rezult = -16331239353195370L;
  }
  if (MY_fabs(x) < 0.000000001) {
    rezult = 0;
  }
  return rezult;
}

/* возвращает ближайшее целое число, не меньшее заданного значения */
long double MY_ceil(double x) {
  long double y = 0;
  if ((x == MY_INF) || (x == -MY_INF)) {
    y = x;
  } else if (x != x) {
    y = MY_NAN;
  } else {
    if (x > 0) {
      if ((long int)x - x < 0) {
        y = (long double)(long int)x + 1;
      } else {
        y = (long double)(long int)x;
      }
    } else {
      if ((long int)x - x < 0) {
        y = (long double)(long int)x - 1;
      } else {
        y = (long double)(long int)x;
      }
    }
  }
  return y;
}

/* возвращает ближайшее целое число, не превышающее заданное значение */
long double MY_floor(double x) {
  long double y = 0;
  if ((x == MY_INF)) {
    y = MY_INF;
  } else if (x == -MY_INF) {
    y = -MY_INF;
  } else if (x != x) {
    y = MY_NAN;
  } else {
    if (x < 0) {
      if ((long int)x - x > 0) {
        y = (long double)(long int)x - 1;
      } else {
        y = (long double)(long int)x;
      }
    } else {
      if ((long int)x - x > 0) {
        y = (long double)(long int)x + 1;
      } else {
        y = (long double)(long int)x;
      }
    }
  }
  return y;
}
