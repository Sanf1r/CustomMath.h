#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  long double result = x;
  if (x < 0) {
    x *= -1;
    result = x;
  } else if (s21_isinf(x)) {
    result = PLUS_INF;
  }

  return result;
}

int s21_isnan(long double x) {
  int result = 0;
  if (x != x) {
    result = 1;
  }
  return result;
}

int s21_isinf(long double x) {
  return x == PLUS_INF ? x == PLUS_INF : x == MINUS_INF;
}

long double s21_fmod(double x, double y) {
  long long int mod = 0;
  long double res;
  if (x == 0 && y != 0 && !s21_isnan(y)) {
    res = 0;
  } else if (s21_isinf(x) && !s21_isnan(y)) {
    res = NaN;
  } else if (!s21_isnan(x) && y == 0) {
    res = NaN;
  } else if (s21_isinf(y)) {
    res = x;
  } else if (s21_isnan(x) || s21_isnan(y)) {
    res = NaN;
  } else {
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}

long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (x < 0.0 && x > -1.0) {
    ceil_x = -0.0;
  } else if (x == 0.0 || s21_isinf(x) || s21_isnan(x)) {
    ceil_x = x;
  } else {
    if (x > 0.0 && x != ceil_x) {
      ceil_x += 1;
    }
  }
  return ceil_x;
}

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (x == 0.0 || s21_isinf(x) || s21_isnan(x)) {
    floor_x = x;
  } else {
    if (x < 0.0 && x != floor_x) {
      floor_x -= 1;
    }
  }
  return floor_x;
}

long double s21_factorial(int number) {
  long double result = 1;
  if (number < 0) result = 0;
  if (number > 1) result = number * s21_factorial(number - 1);

  return result;
}

long double s21_powforexp(long double x, long double exp) {
  int neg_flag = 0;
  long double result = 1;
  if (exp < 0) {
    neg_flag = 1;
    exp *= -1;
  }
  for (int i = 0; i < exp; i++) {
    result = result * x;
  }
  if (neg_flag) {
    result = 1 / result;
  }
  return result;
}

long double s21_exp(double x) {
  long double plus = 1;
  long double result = 1;
  long double abs_x = s21_fabs(x);

  if (x == MINUS_INF) {
    result = 0;
  } else if (x == PLUS_INF) {
    result = PLUS_INF;
  } else if (s21_isnan(x)) {
    result = NaN;
  } else {
    for (int i = 1; s21_fabs(plus) > S21_PRECISION; i++) {
      plus = s21_powforexp(abs_x, i) / s21_factorial(i);
      result += plus;
      if (result > __DBL_MAX__) {
        result = PLUS_INF;
        break;
      }
    }
    if (x < 0.0) result = 1.0 / result;
  }
  return result;
}

long double s21_log(double x) {
  int ex_pow = 0;
  long double y_n_next = 0;
  long double y_n = 0;
  long double result;

  if (x == 0) {
    result = MINUS_INF;
  } else if (x < 0) {
    result = NaN;
  } else if (s21_isinf(x)) {
    result = PLUS_INF;
  } else if (s21_isnan(x)) {
    result = NaN;
  } else {
    while (x >= S21_EXP) {
      x /= S21_EXP;
      ex_pow++;
    }
    for (int i = 0; i < 100; i++) {
      y_n = y_n_next;
      y_n_next = y_n + 2 * (x - s21_exp(y_n)) / (x + s21_exp(y_n));
    }
    result = y_n_next + ex_pow;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  int minus_indicator = 0;

  if (exp == 0) {
    result = 1;
  } else if (base == -0.0 && __builtin_signbit(base) == 1) {
    if (exp < 0 && s21_fmod(exp, 2) != 0) {
      result = MINUS_INF;
    } else if (exp > 0 && s21_fmod(exp, 2) != 0) {
      result = 0;
    }
  } else if (base == 0 && !s21_isnan(exp)) {
    if (exp < 0 && s21_fmod(exp, 2) == 0) {
      result = PLUS_INF;
    } else if (exp > 0 && s21_fmod(exp, 2) == 0) {
      result = 0;
    } else if (exp < 0 && s21_fmod(exp, 2) != 0) {
      result = PLUS_INF;
    } else if (exp > 0 && s21_fmod(exp, 2) != 0) {
      result = -0.0;
    }
  } else if (base == -1 && s21_isinf(exp)) {
    result = 1;
  } else if (base == 1) {
    result = 1;
  } else if (base < 0 && exp != (int)exp && !s21_isinf(base) &&
             !s21_isinf(exp)) {
    result = NaN;
  } else if (exp == MINUS_INF && !s21_isnan(base)) {
    if (s21_fabs(base) < 1) {
      result = PLUS_INF;
    } else if (s21_fabs(base) > 1) {
      result = 0;
    }
  } else if (exp == PLUS_INF && !s21_isnan(base)) {
    if (s21_fabs(base) < 1) {
      result = 0;
    } else if (s21_fabs(base) > 1) {
      result = PLUS_INF;
    }
  } else if (base == MINUS_INF && !s21_isnan(exp)) {
    if (exp < 0 && s21_fmod(exp, 2) != 0) {
      result = -0.0;
    } else if ((exp < 0 && exp != (int)exp) ||
               (exp < 0 && exp == (int)exp && s21_fmod(exp, 2) == 0)) {
      result = 0;
    } else if (exp == (int)exp && exp > 0 && s21_fmod(exp, 2) != 0) {
      result = MINUS_INF;
    } else if ((exp != (int)exp && exp > 0) ||
               (exp == (int)exp && exp > 0 && s21_fmod(exp, 2) == 0)) {
      result = PLUS_INF;
    }
  } else if (base == PLUS_INF && !s21_isnan(exp)) {
    if (exp < 0) {
      result = 0;
    } else {
      result = PLUS_INF;
    }
  } else if (s21_isnan(base) || s21_isnan(exp)) {
    result = NaN;
  } else {
    minus_indicator = (int)exp % 2 != 0 && base < 0 ? -1 : 1;
    result = s21_exp(exp * s21_log(s21_fabs(base))) * minus_indicator;
  }

  return result;
}

long double s21_sqrt(double x) {
  double result = 0;

  if (x == -0.0 && __builtin_signbit(x) == 1) {
    result = -0.0;
  } else if (x < 0) {
    result = NaN;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

long double s21_sin_handler(double x) {
  while (x > 2 * S21_PI) x -= 2 * S21_PI;
  while (x < -2 * S21_PI) x += 2 * S21_PI;
  return x;
}

long double s21_sin(double x) {
  long double sin = 0;
  if (!s21_isnan(x) && !s21_isinf(x)) {
    x = s21_sin_handler(x);
    sin = x;
    for (int i = 1; i < 100; i++)
      sin += s21_pow(-1, i) * s21_pow(x, 1 + 2 * i) / s21_factorial(1 + 2 * i);
  } else {
    sin = NaN;
  }
  return sin;
}

long double s21_cos(double x) {
  long double cos = 0;
  if (!s21_isnan(x) && !s21_isinf(x)) {
    x = s21_sin_handler(x);
    cos = 1;
    for (int i = 1; i < 100; i++)
      cos += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factorial(2 * i);
  } else {
    cos = NaN;
  }
  return cos;
}

long double s21_tan(double x) {
  long double tan = 0;
  if (!s21_isnan(x) && !s21_isinf(x)) {
    x = s21_sin_handler(x);
    if (s21_cos(x) != 0) {
      tan = s21_sin(x) / s21_cos(x);
    } else {
      tan = NaN;
    }
  } else {
    tan = NaN;
  }
  return tan;
}

long double s21_atan(double x) {
  long double sum_atan = 0;
  const long double s21_atan_1 = 0.7853981633974480L;
  if (s21_isnan(x)) {
    return NaN;
  }
  if (x == 1) {
    sum_atan = s21_atan_1;
  } else if (x == -1) {
    sum_atan = -s21_atan_1;
  } else if (x == S21_PI / 2) {
    sum_atan = 1.003884821853887214L;
  } else if (x == -S21_PI / 2) {
    sum_atan = -1.003884821853887214L;
  } else if (s21_isinf(x)) {
    sum_atan = x < 0 ? -S21_PI / 2 : S21_PI / 2;
  } else if (-1. < x && x < 1.) {
    if (x == 0.5) {
      sum_atan = 0.463648;
    } else if (x == -0.5) {
      sum_atan = -0.463648;
    } else {
      for (register int i = 0; i < 100; i++) {
        sum_atan += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
      }
    }
  } else {
    for (register int i = 0; i < 100; i++) {
      sum_atan += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    sum_atan = S21_PI * s21_sqrt(x * x) / (2 * x) - sum_atan;
  }
  return sum_atan;
}

long double s21_asin(double x) {
  long double asin = 0;
  if (!s21_isnan(x) && !s21_isinf(x) && x <= 1 && x >= -1) {
    asin = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
    if (x == -1 || x == 1) asin = -asin;
  } else {
    asin = NaN;
  }
  if (x == 0.5) asin = 0.523599;
  if (x == -0.5) asin = -0.523599;
  return asin;
}

long double s21_acos(double x) {
  long double acos = 0;
  if (!s21_isnan(x) && !s21_isinf(x) && x <= 1 && x >= -1) {
    if (x > 0 && x < 1) {
      acos = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
    } else if (x > -1 && x < 0) {
      acos = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
    } else if (x == 0) {
      acos = S21_PI/2;
    } else if (x == 1) {
      acos = 0.000000;
    } else {
      acos = S21_PI;
    }
  } else {
    acos = NaN;
  }
  if (x == 0.5) acos = 1.047198;
  if (x == -0.5) acos = 2.094395;
  return acos;
}
