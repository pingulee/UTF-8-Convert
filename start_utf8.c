#include <stdio.h>

void utf8_decode(const char* hexStr) {
    unsigned int hex;
    int char_count = 0;
    int byte_count = 0;

    while (*hexStr) {
        if (sscanf(hexStr, "%2x", &hex) != 1) break;
        printf("%c", hex);
        byte_count++;
        while (*hexStr && *hexStr != ' ') hexStr++;
        if (*hexStr == ' ') hexStr++;
    }
    printf(" %d\n", byte_count);
}

int main() {
    char input[256] = {};

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        utf8_decode(input);
    }

    return 0;
}
