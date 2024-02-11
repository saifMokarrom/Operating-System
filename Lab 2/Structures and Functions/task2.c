
#include <stdio.h>
void perfect_check(int num);


int main() {
    int lower, upper;
    lower= 1;
    upper = 10000;
    for (int i = lower; i <= upper; i++) {
        perfect_check(i);
    }
    return 0;
}


void perfect_check(int num) {
    int sum=0;
    for (int i = 1; i < num; i++) {
        if (num%i == 0) {
            sum=sum+i;
        }
    }

    if (sum == num)
        printf("%d\n", sum);

}
