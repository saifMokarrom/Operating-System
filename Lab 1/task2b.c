#include <stdio.h>
#include <stdbool.h>

int main() {
FILE *inpF, *outF;
inpF = fopen("input multiple spaced.txt", "r");
outF = fopen("output single spaced.txt", "w");
char converttoSentence[300];
int i = 0;
char ch;

do {
ch = fgetc(inpF);
if (ch != EOF) {
converttoSentence[i] = ch;
i++;
}
} while (ch != EOF);

converttoSentence[i] = ' ';

bool isSpaceGot = false;
i = 0;
while (converttoSentence[i] != '\0') {
if (converttoSentence[i] == ' ') {
 isSpaceGot = true;
}
else {
if (isSpaceGot) {
 fputc(' ', outF);
 isSpaceGot = false;
}
fputc(converttoSentence[i], outF);
}
i++;
}

fclose(inpF);
fclose(outF);
return 0;
}
