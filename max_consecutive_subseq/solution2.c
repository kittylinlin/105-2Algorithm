#include <stdio.h>
#define N 100000
int max_consecutive_subseq(int x[], int n);

int main(void) {
  // find by internet
  int l;
  int n = 0;
  int x[N];

  while(scanf("%d", &l) == 1) {
    x[n] = l;
    n = n + 1;
  }
  // maximun subseq sum of the seq which haven't been rotated
  int first_max = max_consecutive_subseq(x, n);

  int max_wrap = 0;
  int i;
  for(i = 0; i < n; i++) {
    // calculate total array sum
    max_wrap = max_wrap + x[i];
    // change the sign of each element
    x[i] = -x[i];
  }

  // After changing the sign, we can find the positive value of the largest negative subseq through max_consecutive_subseq
  // Since we want to find the maximum circular subseq, we need to ignore the subseq which carry out a large nagative value
  // So, we just add back the largest negative value
  // Then, we get the maximum subseq sum of the seq which have been rotated
  max_wrap = max_wrap + max_consecutive_subseq(x, n);
  printf("%d", (first_max > max_wrap) ? first_max : max_wrap);
  return 0;
}

int max_consecutive_subseq(int x[], int n) {
  int i;
  int global_max = 0;
  int suffix_max = 0;
  for(i = 0; i < n; i++) {
    if(x[i]+suffix_max > global_max) {
      suffix_max = suffix_max + x[i];
      global_max = suffix_max;
    } else if(x[i]+suffix_max > 0) {
      suffix_max = x[i] + suffix_max;
    } else {
      suffix_max = 0;
    }
  }
  return global_max;
}
