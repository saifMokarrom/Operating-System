#include <stdio.h>
#include <limits.h>

int process_fin(int arrival_time[], int burst_time[], int rem_time[], int n, int curr_time);


int main() {
    int nprocess = 5;
    int arrival_time[] = {0, 2, 3, 4, 5};
    int burst_time[] = {5, 2, 7, 4, 5};
    int rem_time[nprocess], wt[nprocess],ct[nprocess],curr_time = 0, tasks = 0;

    for (int i = 0; i < nprocess; i++) {
        wt[i] = 0;
        rem_time[i] = burst_time[i];
    }

    while (tasks < nprocess) {
        int i = process_fin(arrival_time, burst_time, rem_time, nprocess, curr_time);

        if (i != INT_MIN) {
            if (rem_time[i] == burst_time[i]) {
                wt[i] = curr_time - arrival_time[i];
            }
           rem_time[i]= rem_time[i] -1;
           curr_time = curr_time + 1;

            if (rem_time[i] == 0) {
                ct[i] = curr_time;
                int temp = ct[i] - arrival_time[i];
                wt[i] = temp - burst_time[i];
                tasks = tasks + 1;
            }
        } else {
            curr_time = curr_time + 1;
        }
    }

    for (int i = 0; i < nprocess; i++)
            printf("P%d: completion time: %d, turnaround time: %d, waiting time: %d\n", i + 1, ct[i], wt[i] + burst_time[i], wt[i]);
}



int process_fin(int arrival_time[], int burst_time[], int rem_time[], int n, int curr_time) {
    int low_tinme = INT_MAX;
    int min_idx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arrival_time[i] <= curr_time && rem_time[i] > 0 && rem_time[i] < low_tinme) {
            low_tinme = rem_time[i];
            min_idx = i;
        }
    }
    return min_idx;
}

