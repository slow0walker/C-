#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s source dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* source = fopen(argv[1], "rb");
    FILE* dest = fopen(argv[2], "wb");
    if (source == NULL || dest == NULL) {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(source);
    fclose(dest);
    return 0;
}