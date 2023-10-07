#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//int max_chars = 100;
void wrong_input(const char *input);

int main(int argc, char *argv[]){
    //char adress[max_chars];
    char *input = argv[1];
    wrong_input(input);
    int length = argc;
    printf ("%i", length);
    //while (fgets (adress, sizeof(adress), stdin) !=NULL) {
    //printf ("%s", adress);
    //}


return 0;
} 


void wrong_input(const char *input) {
    
    printf ("%s", input);
    for (int a = 0; input[a] !='\0'; a++){
        char i = input[a];
        if (i < 'A' || (i > 'Z' && i < 'a') )
    printf ("error: wrong input");
    }

}
