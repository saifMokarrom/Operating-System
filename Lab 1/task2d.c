
#include <stdio.h>
#include <string.h>

void isCorrect(const char *email);
int main() {
char email[50];
printf("Enter your email address: ");
scanf("%s", email);

isCorrect(email);

return 0;
}




void isCorrect(const char *email) {
char temp[15];
char newdom[] = "sheba.xyz";
for (int i = 0; email[i]!='\0'; i++) {
//printf("%c",email[i]);
if (email[i] == '@'){
 int k=0;
 for (int j=i+1; j<email[j]!='\0';j++){
  temp[k] = email[j];
  k++;
 }
}
}

/*for (int i = 0; temp[i]!='\0'; i++) {
printf("%c",temp[i]);
}*/
int decision = strcmp(temp, newdom);
if (decision)
 printf("Email address is outdated\n");
else
 printf("Email address is okay");

}
