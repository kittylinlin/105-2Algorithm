#include <stdio.h>
int black_white(int n, int m, int A[n][m], int visit[n][m], int i, int j, int k);
int l;

int main(void) {
  int n, m, a;
  int i = 0;
  int j = 0;
  scanf("%d %d\n", &n, &m);
  int A[n][m];
  int visit[n][m];

  while(scanf("%d", &a) == 1) {
    if(j == m) {
      i = i + 1;
      j = 0;
    }
    A[i][j] = a;
    visit[i][j] = 0;
    j = j + 1;
  }

  int max = 0;
  int temp;
  for(i = 0; i < n; i++) {
    for(j = 0; j < m; j++) {
      if(!visit[i][j]) {
        l = 0;
        temp = black_white(n, m, A, visit, i, j, A[i][j]);
        if(temp > max) {
          max = temp;
        }
      }
    }
  }
  printf("%d", max);
  return 0;
}

int black_white(int n, int m, int A[n][m], int visit[n][m], int i, int j, int k) {
  if(i-1 >= 0 && !visit[i-1][j] && A[i-1][j] == k) {
      visit[i-1][j] = 1;
      l = l + 1;
      black_white(n, m, A, visit, i-1, j, k);
  }
  if(j-1 >= 0 && !visit[i][j-1] && A[i][j-1] == k) {
      visit[i][j-1] = 1;
      l = l + 1;
      black_white(n, m, A, visit, i, j-1, k);
  }
  if(j+1 < m && !visit[i][j+1] && A[i][j+1] == k) {
      visit[i][j+1] = 1;
      l = l + 1;
      black_white(n, m, A, visit, i, j+1, k);
  }
  if(i+1 < n && !visit[i+1][j] && A[i+1][j] == k) {
      visit[i+1][j] = 1;
      l = l + 1;
      black_white(n, m, A, visit, i+1, j, k);
  }
  return l;
}
