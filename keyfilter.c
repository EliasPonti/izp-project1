#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

char *input = argv[1];
int length = strlen(input);
printf ("%d  %d %s",argc, length, input);
return 0;
}