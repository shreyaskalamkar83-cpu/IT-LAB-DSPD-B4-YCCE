#include <stdio.h>

int main() {
    FILE *sourcefile, *destinationfile;
    char ch;

    sourcefile = fopen("input.txt", "r");
    destinationfile = fopen("output.txt", "w");

    if (sourcefile == NULL || destinationfile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(sourcefile)) != EOF) {
        fputc(ch, destinationfile);
    }

    printf("File copied successfully.\n");

    fclose(sourcefile);
    fclose(destinationfile);
    return 0;
}
//gcc pract10.c ./a.exe