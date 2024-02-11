#include <stdio.h>
#include <stdbool.h>


int main() {
    int n = 6, m = 4;
    int allocation[6][4] = {{0, 1, 0, 3},{2, 0, 0, 3},{3, 0, 2, 0},{2, 1, 1, 5},{0, 0, 2, 2},{1, 2, 3, 1}};
    int max[6][4] = {{6, 4, 3, 4},{3, 2, 2, 4},{9, 1, 2, 6},{2, 2, 2, 8}, {4, 3, 3, 7},{6, 2, 6, 5}};
    int available[4] = {2, 2, 2, 1};



    int finish[6] = {0};

    int seq[6];
    int idx = 0;



    int safe = 1;


    int work[4];
    for (int i = 0; i < 4; i++) {
        work[i] = available[i];
    }

    while (safe) {
        safe = 0;
        int i = 0;

        while(i < n) {
            if (finish[i] == 0) {
                int nobreak = 1;

                for (int j = 0; j < m; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        nobreak = 0;
                        break;
                    }
                }

                if (nobreak == 1) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safe = 1;
                    finish[i] = 1;
                    seq[idx] = i;
                    idx++;

                }
            }
            i++;
        }
    }

    int safe2 = 1;
    for (int i = 0; i < n; i++) {
        if (finish[i] != 1) {
            safe2 = 0;
            break;
        }
    }

    if (safe2) {
        printf("Safe sequence: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", seq[i]);
        }
    }
    else {
        printf("System is not safe.\n");
    }

    return 0;
}
