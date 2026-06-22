#include <stdio.h>
#include <ctype.h>

double my_atof(const char s[]);

int main(void)
{
  char s[] = "0.1";

  printf("atof(\"%s\") = %lf\n", s, my_atof(s));

  return 0;
}

double my_atof(const char s[]) {
  double val, power;
  int i, sign;

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
  return sign * val / power;
}
