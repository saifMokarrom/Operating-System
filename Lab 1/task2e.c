#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {

char text[100];
printf("Enter a string: ");
scanf("%s", text);

for (int i = 0; text[i]!='\0'; i++) {
text[i] = tolower(text[i]);
}
/*for (int i = 0; text[i]!='\0'; i++) {
printf("%c",text[i]);
}*/

char *pointst=text;
char *pointend=text;

while (*pointend != '\0')
 pointend++;
pointend--;


bool ispal = true;
while (pointst < pointend) {
if ((*pointst) != (*pointend)) {
 printf("Not Palindrome\n");
 ispal = false;
 break;
}
pointst++;
pointend--;
}

if (ispal)
 printf("Palindrome\n");

return 0;
}
