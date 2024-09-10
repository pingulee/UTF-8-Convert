#include <stdio.h>
#include <locale.h>
#include <string.h>

// UTF-8 문자열을 16진수로 변환하는 함수
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

    char str[256];

    while (1) {
        printf("> ");
        if (fgets(str, sizeof(str), stdin) == NULL) {
            perror("입력 오류");
            return 1;
        }

        // fgets로 입력 시 개행 문자 제거
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        printf("UTF-8 Hex: ");
        print_utf8_hex(str);
    }

    return 0;
}
