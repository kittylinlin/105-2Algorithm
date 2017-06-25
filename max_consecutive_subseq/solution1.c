#include <stdio.h>
#define N 100000

int main(void) {
  int global_max = 0;
  int suffix_max = 0;
  int i,j,k;
  int l;
  int n = 0;
  int x[N];

  while(scanf("%d", &l) == 1) {
    x[n] = l;
    n = n + 1;
  }
  for(i = 0; i < n; i++) {
    for(j = i; j < n+i; j++) {
      if(x[i] <= 0) {
        break;
      } else if(j >= n) {
        k = j - n;
      } else {
        k = j;
      }
      if(x[k]+suffix_max > global_max) {
        suffix_max = suffix_max + x[k];
        global_max = suffix_max;
      } else if(x[k]+suffix_max > 0) {
        suffix_max = x[k] + suffix_max;
      } else {
        suffix_max = 0;
      }
    }
    suffix_max = 0;
  }
  printf("%d", global_max);
  return 0;
}
