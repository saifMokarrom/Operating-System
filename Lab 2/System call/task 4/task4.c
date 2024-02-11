#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sort(int numbers[], int n);
void oddeven(int arr[], int n);



int main() {
    int numbers[] = {102,172,2882,2,273,97};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    pid_t a;

    a = fork();
    if (a == 0) {
        printf("Sorting by child\n");
        sort(numbers, n);

   }
    else if (a > 0) {
        wait(NULL);
        printf("Odd-even by parent\n");
        oddeven(numbers, n);
 }
return 0;
}



void sort(int numbers[], int n) {
int i, j, temp;
for (i = 0; i < n-1; i++) {
  for (j = 0; j < n-i-1; j++) {
   if (numbers[j] < numbers[j+1]) {
    temp = numbers[j];
     numbers[j] = numbers[j+1];
     numbers[j+1] = temp;
    }
 }
}
for (int i = 0; i < n; i++){
 printf("%d ", numbers[i]);
}
printf("\n");
}


void oddeven(int numbers[], int n) {
for (int i = 0; i < n; i++) {
 if (numbers[i] % 2 == 0)
     printf("%d - even\n", numbers[i]);
 else
     printf("%d - odd\n", numbers[i]);
 }
}
