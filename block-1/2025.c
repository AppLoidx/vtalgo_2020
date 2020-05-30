
/*****************************************************
 * Task 2025                                         *
 *                                                   *
 * TIMUS                                             *
 *                                                   *
 *****************************************************/

#include <stdio.h>

int main() {
  int iter, n, k;
  scanf("%d", &iter);

  for (int i = 0; i < iter; i++) {
    scanf("%d%d", &n, &k);
    int diff = n % k;
    int each = n / k;
    int a = (n - each) * (k - diff) * each;
    int b = (n - (each + 1)) * diff * (each + 1);

    int res = (a + b) / 2;
    printf("%d\n", res);
  }
}
