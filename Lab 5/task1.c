#include <stdio.h>

int main() {
  int n = 5, m = 4;

  int alloc[5][4] = {
      {0, 1, 0, 3}, {2, 0, 0, 0}, {3, 0, 2, 0}, {2, 1, 1, 5}, {0, 0, 2, 2}};
  int max[5][4] = {
      {6, 4, 3, 4}, {3, 2, 2, 1}, {9, 1, 2, 6}, {2, 2, 2, 8}, {4, 3, 3, 7}};
  int avail[4] = {3, 3, 2, 1};

  int need[5][4];

  int finish[5] = {0};

  int safe = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  int i, j, k;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  while (safe) {
    safe = 0;

    for (i = 0; i < n; i++) {
      int c = 0;
      j = 0;
      while (j < m) {
        if (finish[i] == 0 && need[i][j] <= avail[j]) {
          c++;
          if (c == m) {
            for (k = 0; k < m; k++) {
              avail[k] += alloc[i][k];
              finish[i] = 1;
              safe = 1;
            }

            if (finish[i] == 1) {
              i = n;
            }
          }
        }
        j++;
      }
    }
  }

  if (safe == 0) {
    printf("Deadlock Ahead\n");
  } else {
    printf("safe here\n");
  }

  return 0;
}
