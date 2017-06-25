#include <stdio.h>
int dijkstra(int n, int source, int w[n][n]);

int main(void) {
  int n, a, b;
  int i = 0;
  scanf("%d\n", &n);
  int A[n][2];

  while(scanf("%d %d", &a, &b) == 2) {
    A[i][0] = a;
    A[i][1] = b;
    i = i + 1;
  }

  int B[n][n];
  int j, k;
  for(j = 0; j < n; j++) {
    for(k = j; k < n; k++) {
      if(j == k) {
        B[j][k] = n;
      } else if(((A[j][0] <= A[k][0]) && (A[k][0] <= A[j][1])) || ((A[j][0] <= A[k][1]) && (A[k][1] <= A[j][1])) || ((A[k][0] <= A[j][0]) && (A[j][0] <= A[k][1])) || ((A[k][0] <= A[j][1]) && (A[j][1] <= A[k][1]))) {
        B[j][k] = 1;
        B[k][j] = 1;
      } else {
        B[j][k] = n;
        B[k][j] = n;
      }
    }
  }
  printf("%d", dijkstra(n, 0, B));
  return 0;
}

int dijkstra(int n, int source, int w[n][n]) {
  int d[n];      // 記錄起點到各個點的最短路徑長度
  int visit[n];  // 記錄各個點是不是已在最短路徑樹之中
  int i, j, k;

  for(i = 0; i < n; i++) { // initialize
    visit[i] = 0;
  }
  for(i = 0; i < n; i++) { // initialize
    d[i] = n;
  }

  d[source] = 0;

  for(k = 0; k < n; k++) {
    int a = -1;
    int b;
    int min = n;
    for(i = 0; i < n; i++) {
      if (!visit[i] && d[i] < min) { // 記錄這一條邊
        a = i;
        min = d[i];
      }
    }
    if(a == -1) { // 起點有連通的最短路徑都已找完
      break;
    }
    visit[a] = 1;
    for(b = 0; b < n; b++) { // 以邊ab進行relaxation
      if (!visit[b] && d[a] + w[a][b] < d[b]) {
        d[b] = d[a] + w[a][b];
      }
    }
  }
  return d[n-1];
}
