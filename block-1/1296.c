
/*****************************************************
 * Task 1296                                         *
 *                                                   *
 * TIMUS                                             *
 *                                                   *
 *****************************************************/

#include <stdio.h>

int main(void) {
  int iter;

  if (scanf("%d", &iter) != 1) {
    printf("Invalid input");
  }

  int values[iter];
  int max = 0;
  int sum = 0;
  for (int i = 0; i < iter; i++) {
    int inp;
    if (scanf("%d", &inp) != 1) {
      printf("Invalid input: you provided wrong amount of variables");
    }

    sum = sum + inp;
    if (sum > max)
      max = sum;
    if (sum < 0)
      sum = 0;
  }

  printf("%d", max);
}
