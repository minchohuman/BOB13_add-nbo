#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    FILE *fp2 = fopen(argv[2], "rb");
    if (fp2 == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[2]);
        fclose(fp1);
        return 1;
    }

    uint32_t num1, num2;
    if (fread(&num1, sizeof(uint32_t), 1, fp1) != 1) {
        fprintf(stderr, "Error: Cannot read from file %s\n", argv[1]);
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    if (fread(&num2, sizeof(uint32_t), 1, fp2) != 1) {
        fprintf(stderr, "Error: Cannot read from file %s\n", argv[2]);
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    fclose(fp1);
    fclose(fp2);

    uint32_t sum = num1 + num2;
    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}