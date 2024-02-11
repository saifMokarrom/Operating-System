#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int n = argc - 1;
int numbers[n];

for (int i = 0; i < n; i++)
numbers[i] = atoi(argv[i + 1]);
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

for (int i = 0; i < n; i++)
printf("%d ", numbers[i]);
return 0;
}

