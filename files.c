//using fopen() and fwrite() to write data to a file
#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("data.txt", "wb"); //open the file for writing in binary mode

    if (fp == NULL)
    {
        printf("Error: Unable to open the file\n");
        return 1;
    }

    int num = 100;
    float fnum = 3.14159;
    char string[] = "Hello, world!";

    fwrite(&num, sizeof(num), 1, fp); //write an integer to the file
    fwrite(&fnum, sizeof(fnum), 1, fp); //write a float to the file
    fwrite(string, sizeof(string), 1, fp); //write a string to the file

    fclose(fp); //Close the file

    
}