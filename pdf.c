#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Improper Usage\n");
        return 1;
    }

    //open the file
    char* filename = argv[1];
    FILE *input = fopen(filename,"r");

    if (input == NULL)
    {
        printf("File '%s' could not be opened.\n", filename);
        return 1;
    }

    //add a buffer of size 4 with each element 8 bits large
    uint8_t buffer[4];

    //read through the first 4 bytes of the file
    fread(buffer, sizeof(uint8_t), 4, input);
/* 
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n",buffer[i]);
    }
 */

    uint8_t pdf_signature[] = {37, 80, 68, 70};

    //does the buffer signature match pdf signature?
    for (int i = 0; i < 4; i++)
    {
        if (pdf_signature[i] != buffer[i])
        {
            printf("This file is not a PDF.\n");
            fclose(input);
            return 0;
        } 
    }

    printf("This file is a PDF.\n");

    fclose(input);
}