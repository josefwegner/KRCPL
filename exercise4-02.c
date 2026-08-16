#include <stdio.h>
#include <ctype.h>

/* Exercise 4-2. Expand atof to support scientific notation. */

double kr_atof(const char s[]);
void test_atof(const char s[]);

int main(void)
{
  test_atof("10e3");
  test_atof("123.45E-6");
  test_atof("-3.2e-3");

  return 0;
}

void test_atof(const char s[]) {
  printf("atof(\"%s\") = %lf\n", s, kr_atof(s));
}

double kr_atof(const char s[]) {
  double val, power;
  int i, sign, e, e_sign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  val = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    e_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;

    for (e = 0; isdigit(s[i]); i++)
      e = 10 * e + (s[i] - '0');

    while (e-- > 0)
      val = (e_sign == 1) ? val * 10.0 : val / 10.0;
  }

  return val;
}
