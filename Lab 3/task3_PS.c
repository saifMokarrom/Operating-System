
#include <stdio.h>
#include <limits.h>


int main() {
    int nprocess = 5;
    int arrival_time[] = {0, 14, 3, 9, 7};
    int burst_time[] = {15, 5, 10, 22, 16};
    int priorities[] = {2, 4, 0, 3, 1};

    int rem_time[nprocess], wt[nprocess],ct[nprocess],is_completed[nprocess],curr_time = 0,tasks = 0;

    for (int i = 0; i < nprocess; i++) {
        rem_time[i] = burst_time[i];
        wt[i] = ct[i] = is_completed[i] = 0;
    }

    while (tasks < nprocess) {
        int min = INT_MAX;
        int idx = INT_MIN;
        for (int i = 0; i < nprocess; i++) {
            if (arrival_time[i] <= curr_time && is_completed[i] == 0) {
                if (priorities[i] < min) {
                    min = priorities[i];
                    idx = i;
                }
                else if (priorities[i] == min && arrival_time[i] < arrival_time[idx]) {
                     min = priorities[i];
                     idx = i;
                }
            }
        }

        if (idx > INT_MIN) {
            if (rem_time[idx] == burst_time[idx]) {
                wt[idx] = curr_time - arrival_time[idx];
            }
            rem_time[idx] = rem_time[idx] - 1;
            curr_time = curr_time + 1;

            if (rem_time[idx] == 0) {
                ct[idx] = curr_time;
                int temp = ct[idx] - arrival_time[idx];
                wt[idx] = temp - burst_time[idx];
                is_completed[idx] = 1;
                tasks = tasks + 1;
            }
        } else {
            curr_time = curr_time + 1;
        }
    }

    for (int i = 0; i < nprocess; i++)
            printf("P%d: completion time: %d, turnaround time: %d, waiting time: %d\n", i + 1, ct[i], wt[i] + burst_time[i], wt[i]);
    return 0;
}



