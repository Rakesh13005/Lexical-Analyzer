#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

char buffer[5000];   // Global buffer to store the contents of the source file
char *file = NULL;   // Pointer to hold filename from command-line argument

int main(int argc, char* argv[]) 
{
    // Check if exactly one argument (source file) is provided
    if (argc != 2) 
    {
        printf("Invalid arguments.\n");
        printf("Usage:\n");
        printf("  %s <source_file>\n", argv[0]);   // Display usage format
        printf("Example:\n");
        printf("  %s try.c\n", argv[0]);            // Example command
        return 1;                                   // Exit with error
    }

    file = argv[1];   // Store the input filename

    // Open the file in read mode
    FILE* fptr = fopen(file, "r");
    if (!fptr) 
    {
        printf("Error: Could not open file '%s'\n", file);  // File open failed
        return 1;
    }

    int i = 0;
    char ch;

    // Read file character by character into buffer
    while ((ch = fgetc(fptr)) != EOF && i < sizeof(buffer) - 1) 
    {
        buffer[i++] = ch;   // Store each character in buffer
    }
    buffer[i] = '\0';       // Null-terminate the string
    fclose(fptr);           // Close the file

    lexi();   // Call lexical analysis function

    return 0; // Exit successfully
}
