#include <stdio.h>
#include <string.h>

char* formatName(char *first, char *last); 

int main () {
    char fname[100] = "Taha ";
    char lname[100] = "Mahmood";

    formatName(fname, lname);
    return 0;
    
}

char* formatName(char *first, char *last) {
    char fullname[100];

    strcat(first,last);
    printf("%s\n", first);
}