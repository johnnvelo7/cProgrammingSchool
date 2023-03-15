#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        exit(1);
    }

    // Read the TGA header
    unsigned char header[18];
    fread(header, sizeof(unsigned char), 18, fp);

    // Extract the relevant information
    int width = header[12] + (header[13] << 8); //bitwise operator 
    int height = header[14] + (header[15] << 8);
    int compressed = header[2];
    int truecolor = header[16] == 24 || header[16] == 32;

    // Print the results
    printf("x-pixels: %d\n", width);
    printf("y-pixels: %d\n", height);
    printf("compression: %s\n", compressed ? "yes" : "no");
    printf("truecolor: %s\n", truecolor ? "yes" : "no");

    // Close the file
    fclose(fp);

    return 0;
}

