#include <stdio.h>

void quicksort_row(int *data, int left, int right);
void quicksort_col(int m, int n, int data[m][n], int left, int right);
void swap(int *a, int *b);

int main(void) {
  int m, n, a;
  int i = 0;
  int j = 0;
  scanf("%d %d\n", &m, &n);
  int A[m][n];

  while(scanf("%d", &a) == 1) {
    if(j == n) {
      i = i + 1;
      j = 0;
    }
    A[i][j] = a;
    j = j + 1;
  }

  for(i = 0; i < m; i++) {
    quicksort_row(A[i], 0, n-1);
  }

  quicksort_col(m, n, A, 0, m-1);

  int k;
  int count;
  int length[m];

  for (i = 0; i < m; i++) {
    length[i] = 1;
  }

  for (i = 0; i < m; i++) {
    for (j = i+1; j < m; j++) {

      count = 0;
      for(k = 0; k < n; k++) {
        if(A[i][k] < A[j][k]) {
          count = count + 1;
        } else {
          break;
        }
      }
      if(count == n) {
        if (length[i] + 1 > length[j]) {
          length[j] = length[i] + 1;
        }
      }

    }
  }

  int len = 0;

  for (i = 0; i < m; i++) {
    if (length[i] > len) {
      len = length[i];
    }
  }
  printf("%d", len);
  return 0;
}

void quicksort_row(int *data, int left, int right) {
  int pivot, i, j;
  if(left >= right) {
    return;
  }
  pivot = data[left];
  i = left + 1;
  j = right;
  while(1) {
    while(i <= right) {
      if (data[i] > pivot) {
        break;
      }
      i = i + 1;
    }
    while(j > left) {
      if (data[j] < pivot) {
        break;
      }
      j = j - 1;
    }
    if(i > j) {
      break;
    }
    swap(&data[i], &data[j]);
  }
  swap(&data[left], &data[j]);
  quicksort_row(data, left, j - 1);
  quicksort_row(data, j + 1, right);
}

void quicksort_col(int m, int n, int data[m][n], int left, int right) {
  int pivot, i, j, k;
  if(left >= right) {
    return;
  }
  pivot = data[left][0];
  i = left + 1;
  j = right;
  while(1) {
    while(i <= right) {
      if (data[i][0] > pivot) {
        break;
      }
      i = i + 1;
    }
    while(j > left) {
      if (data[j][0] < pivot) {
        break;
      }
      j = j - 1;
    }
    if(i > j) {
      break;
    }
    for(k = 0; k < n; k++) {
      swap(&data[i][k], &data[j][k]);
    }
  }
  for(k = 0; k < n; k++) {
    swap(&data[left][k], &data[j][k]);
  }
  quicksort_col(m, n, data, left, j - 1);
  quicksort_col(m, n, data, j + 1, right);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
