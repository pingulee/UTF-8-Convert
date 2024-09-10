#include <stdio.h>
#include <locale.h>
#include <string.h>

void print_utf8_hex(const char *str) {
    while (*str) {
        unsigned char byte = (unsigned char)*str;
        printf("%02X ", byte);
        str++;
    }
    printf("\n");
}

int main() {
    setlocale(LC_CTYPE, "");

    while (1) {
        char str[256] = {};
        printf("> ");
        if (fgets(str, sizeof(str), stdin) == NULL) {
            perror("입력 오류");
            return 1;
        }

        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        printf("");
        print_utf8_hex(str);
    }

    return 0;
}
