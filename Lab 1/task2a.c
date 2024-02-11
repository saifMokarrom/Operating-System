#include <stdio.h>

void subtractWhenFirstGreater(float a, float b);
void addWhenFirstLess(float a, float b);
void multiplyWhenEqual(float a, float b);

int main() {
float first, second;
char op;

printf("Two Numbers(space separated): ");
scanf("%f %f", &first,&second);
printf("Operator(+, -, *): ");
scanf(" %c", &op);

if (first > second && op == '-')
subtractWhenFirstGreater(first, second);
else if (first < second && op == '+')
addWhenFirstLess(first, second);
else if (first == second && op == '*')
multiplyWhenEqual(first, second);

else printf("You have given operator that does not matches with conditions\n");
return 0;
}




void subtractWhenFirstGreater(float a, float b) {
printf("Subtractred result: %.2f\n", a-b);
}
void addWhenFirstLess(float a, float b) {
printf("Added result: %.2f\n", a+b);
}

void multiplyWhenEqual(float a, float b) {
printf("Multiplied result: %.2f\n", a*b);
}
