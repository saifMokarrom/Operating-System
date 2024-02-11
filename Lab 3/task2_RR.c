#include <stdio.h>

int main() {
    int nprocess = 4;
    int burst_time[] = {53, 17, 68, 24};
    int t_quan = 20, rem_time[nprocess], wt[nprocess],ct[nprocess],curr_time = 0, tasks = 0;

    for (int i = 0; i < nprocess; i++) {
        rem_time[i] = burst_time[i];
        wt[i] = 0;
    }

    while (tasks < nprocess) {
        for (int i = 0; i < nprocess; i++) {
            if (rem_time[i] > 0 && rem_time[i] > t_quan) {
                rem_time[i] = rem_time[i] - t_quan;
                curr_time = curr_time + t_quan;
            }
            else if (rem_time[i] > 0 && rem_time[i] <= t_quan) {
                curr_time = curr_time + rem_time[i];
                ct[i] = curr_time;
                tasks = tasks + 1;
                rem_time[i] = 0;

                int temp = ct[i];
                wt[i] = temp - burst_time[i];
            }
        }

    }

    for (int i = 0; i < nprocess; i++)
            printf("P%d: completion time: %d, turnaround time: %d, waiting time: %d\n", i + 1, ct[i], wt[i] + burst_time[i], wt[i]);
    return 0;
}
