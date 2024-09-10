#include <stdio.h>

int utf8_decode(const char* hexStr, int *char_count) {
    unsigned int hex;
    int byte_count = 0;
    int count = 0;

    while (*hexStr) {
        if (sscanf(hexStr, "%2x", &hex) != 1) break;
        if ((hex & 0xC0) != 0x80) {
            count++;
        }
        printf("%c", hex);
        byte_count++;
        while (*hexStr && *hexStr != ' ') hexStr++;
        if (*hexStr == ' ') hexStr++;
    }
    *char_count = count;
    return byte_count;
}

int main() {
    char input[256] = {};
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        int char_count;
        int byte_count = utf8_decode(input, &char_count);
        printf(" %d %d\n", char_count, byte_count);
    }

    return 0;
}
