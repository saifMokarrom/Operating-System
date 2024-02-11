
#include <stdio.h>
#include <stdbool.h>

bool containsSpec(char* str);
int main() {
char str[100];
scanf("%[^\n]%*c", str);
/*for (int i = 0; str[i]!='\0'; i++) {
printf("%c",str[i]);
}*/
bool islow=false,isupp=false,isdig=false,isspec=false;
for (int i = 0; str[i]!='\0'; i++) {
if (str[i] >= 'a' && str[i] <= 'z')
islow=true;
if(str[i] >= 'A' && str[i] <= 'Z')
isupp=true;
if(str[i] >= '0' && str[i] <= '9')
isdig=true;
if(containsSpec(str[i]))
isspec=true;
}

if (!islow) printf("Lowercase character missing\n");
if (!isupp) printf("Uppercase character missing\n");
if (!isdig) printf("Digit missing\n");
if (!isspec) printf("Special character missing\n");
if (islow && isupp && isdig && isspec) printf("OK\n");
}


bool containsSpec(char* str) {
    char chars[] = "_$#@";
    for (int i = 0; chars[i]; i++) {
        if (str == chars[i]) return true;
    }
    return false;
}
