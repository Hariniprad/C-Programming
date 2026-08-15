#include<stdio.h>

int main()
{
    //NOTE - here only syntax in upper case
    FILE *filePointer, *targetFile;
    int value = 10;

    //File pointer with write - w
    filePointer = fopen("example.txt", "w");
    fprintf(filePointer, "The value is: %d\n", value);
    fclose(filePointer);

    // binary

    int values[] = {1, 2, 3, 4, 5};

    filePointer = fopen("binary.bin", "wb");    //replaces the content of the variable since different value
    fwrite(values, sizeof(int), 5, filePointer);
    fclose(filePointer);

    // File Pointer with read
    filePointer = fopen("example.txt", "r");
    fprintf(filePointer, "The value is: %d\n", value);
    printf("Read value: %d\n", value);

    // 14-11-2024 //

    // File copy with OPen the target file in write mode
    targetFile = fopen("target.txt", "w");
    if(targetFile == NULL)
    {
        fclose(filePointer);
        perror("Error opening target file");
        return -1;
    }

    // Copy the contents of source file to target file character by character
    char ch;
    while ((ch = fgetc(filePointer)) != EOF){
        fputc(ch, targetFile);
    }
    fclose(targetFile);

    printf("File copied successfully.\n");

    // // End of file
    // char character;
    // while(!feoof(filePointer))
    // {
    //     character = fgetc(filePointer);

    // }

}