#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[100];
    int a = 10, b = 20, c = 0;
    sprintf(string, "Sum if %d and %d is %d", a, b, c);
    puts(string);

    FILE *f = NULL;
    char ch[100];

    // open the file for read and write operation
    if ((f = fopen("testFile.txt", "r+")) == NULL) {
        printf("Cannot open th file...");
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        // enter the strings with values in the file
        fprintf(f, "The count number is %d\n", i+1);
    }

    fclose(f);

    if ((f = fopen("testFile.txt", "r+")) == NULL) {
        printf("Cannot open the file...");
        exit(1);
    }

    printf("File content is:\n");
    printf("\n....................print the strings....................\n\n");

    while (!feof(f)) {
        fgets(ch, 100, f);
        printf("%s", ch);
    }

    fclose(f);

    return 0;
}